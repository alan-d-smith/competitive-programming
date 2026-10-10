"""Jane Street puzzle "It's a Metric, Too" """
import heapq

from ortools.sat.python import cp_model

N = 11
_ = None
CLUES = [
    [ _,  8,  4,  _,  _, 11,  _,  _,  _,  5,  _],
    [ _,  _,  _,  _,  _,  _,  _, 11,  _,  _,  _],
    [ _,  _,  7,  _,  _,  1,  _,  _,  _,  _, 14],
    [28,  _,  _, 51,  _,  _,  1,  _,  6,  _,  _],
    [ _, 22,  _,  _,  _,  _,  _,  _,  4,  _,  1],
    [ _,  _,  _, 15,  _, 10,  _,  0,  _,  _,  _],
    [11,  _, 11,  _,  _,  _,  _,  _,  _,  9,  _],
    [ _,  _, 17,  _, 14,  _,  _, 10,  _,  _, 13],
    [30,  _,  _,  _,  _,  6,  _,  _, 45,  _,  _],
    [ _,  _,  _, 10,  _,  _,  _,  _,  _,  _,  _],
    [ _, 26,  _,  _,  _,  0,  _,  _, 77, 61,  _],
]

HINT_SIZES = {(10, 5): 3, (3, 3): 37}
HINT_SAME = [(3, 3), (2, 3), (6, 5), (10, 7)]
HINT_ROT_CENTRE = ((3, 3), (6, 5))

CELLS = [(r, c) for r in range(N) for c in range(N)]
IDX = {x: i for i, x in enumerate(CELLS)}
NC = len(CELLS)
DMAX = 4000


def nbrs(r, c):
    return [(r + dr, c + dc) for dr, dc in ((-1, 0), (1, 0), (0, -1), (0, 1)) if 0 <= r + dr < N and 0 <= c + dc < N]


def witnesses():
    out = []
    for pr in range(2 * N - 1):
        for pc in range(2 * N - 1):
            fx = [(pr // 2, pc // 2)] if pr % 2 == 0 and pc % 2 == 0 else []
            out.append(("rot", (pr, pc), lambda r, c, pr=pr, pc=pc: (pr - r, pc - c), fx))
    for p in range(2 * N - 1):
        out.append(("rows", p, lambda r, c, p=p: (p - r, c), [(p // 2, c) for c in range(N)] if p % 2 == 0 else []))
        out.append(("cols", p, lambda r, c, p=p: (r, p - c), [(r, p // 2) for r in range(N)] if p % 2 == 0 else []))
        out.append(("anti", p, lambda r, c, p=p: (p - c, p - r), [(r, p - r) for r in range(N) if 0 <= p - r < N]))
    for k in range(-(N - 1), N):
        out.append(("diag", k, lambda r, c, k=k: (c + k, r - k), [(r, r - k) for r in range(N) if 0 <= r - k < N]))
    return out


def symmetries(cells):
    s = set(cells)
    ops = [lambda r, c: (c, -r), lambda r, c: (-r, -c), lambda r, c: (-c, r), lambda r, c: (-r, c),
           lambda r, c: (r, -c), lambda r, c: (c, r), lambda r, c: (-c, -r)]
    out = []
    for f in ops:
        img = [f(r, c) for r, c in s]
        t = (min(s)[0] - min(img)[0], min(s)[1] - min(img)[1])
        if {(a + t[0], b + t[1]) for a, b in img} == s:
            out.append([x for x in s if (f(*x)[0] + t[0], f(*x)[1] + t[1]) == x])
    return out


def capitol(cells):
    fixed = symmetries(cells)
    return fixed[0][0] if fixed and all(len(f) == 1 for f in fixed) else None


def evaluate(labels):
    regs = {}
    for x in CELLS:
        regs.setdefault(labels[x[0]][x[1]], []).append(x)
    size = [[len(regs[labels[r][c]]) for c in range(N)] for r in range(N)]
    caps = []
    for cells in regs.values():
        seen, stack = {cells[0]}, [cells[0]]
        while stack:
            for y in nbrs(*stack.pop()):
                if y in cells and y not in seen:
                    seen.add(y)
                    stack.append(y)
        assert len(seen) == len(cells) and symmetries(cells), f"invalid state {cells}"
        if capitol(cells):
            caps.append(capitol(cells))
    dist = {x: float("inf") for x in CELLS}
    pq = [(0, x) for x in caps]
    for x in caps:
        dist[x] = 0
    while pq:
        dx, x = heapq.heappop(pq)
        if dx > dist[x]:
            continue
        for y in nbrs(*x):
            w = min(size[x[0]][x[1]], size[y[0]][y[1]])
            if dx + w < dist[y]:
                dist[y] = dx + w
                heapq.heappush(pq, (dx + w, y))
    return size, caps, dist


def build():
    m = cp_model.CpModel()
    # states: rid = index of the state's first square. eq for every pair
    rid = [m.NewIntVar(0, i, "") for i in range(NC)]
    root = [m.NewBoolVar("") for _ in range(NC)]
    for i in range(NC):
        m.Add(rid[i] == i).OnlyEnforceIf(root[i])
        m.Add(rid[i] < i).OnlyEnforceIf(root[i].Not())
    eq = {}
    for i in range(NC):
        for j in range(i + 1, NC):
            b = m.NewBoolVar("")
            m.Add(rid[i] == rid[j]).OnlyEnforceIf(b)
            m.Add(rid[i] != rid[j]).OnlyEnforceIf(b.Not())
            eq[i, j] = eq[j, i] = b
    size = [m.NewIntVar(1, NC, "") for _ in range(NC)]
    for i in range(NC):
        m.Add(size[i] == 1 + sum(eq[i, j] for j in range(NC) if j != i))
    z = [m.NewIntVar(0, NC, "") for _ in range(NC)]
    for i in range(NC):  # each state counted once, at its root
        m.Add(z[i] == size[i]).OnlyEnforceIf(root[i])
        m.Add(z[i] == 0).OnlyEnforceIf(root[i].Not())
    m.Add(sum(z) == NC)

    # every non-root square has a parent in its state, one step closer to the root
    depth = [m.NewIntVar(0, NC - 1, "") for _ in range(NC)]
    for i, x in enumerate(CELLS):
        pars = []
        for y in nbrs(*x):
            j, p = IDX[y], m.NewBoolVar("")
            m.AddImplication(p, eq[i, j])
            m.Add(depth[j] < depth[i]).OnlyEnforceIf(p)
            pars.append(p)
        m.Add(depth[i] == 0).OnlyEnforceIf(root[i])
        m.Add(sum(pars) == 1 - root[i])
        for y in nbrs(*x):
            if IDX[y] > i:
                m.Add(size[i] == size[IDX[y]]).OnlyEnforceIf(eq[i, IDX[y]])

    # each square picks a witness symmetry, shared across its state, mapping it into the state
    wits = witnesses()
    e = [[None] * len(wits) for _ in range(NC)]
    for i, x in enumerate(CELLS):
        lits = []
        for g, (_k, _p, f, _fx) in enumerate(wits):
            y = f(*x)
            if 0 <= y[0] < N and 0 <= y[1] < N:
                e[i][g] = m.NewBoolVar("")
                if y != x:
                    m.AddImplication(e[i][g], eq[i, IDX[y]])
                lits.append(e[i][g])
        m.AddExactlyOne(lits)
    for i, x in enumerate(CELLS):
        for y in nbrs(*x):
            j = IDX[y]
            if j < i:
                continue
            for g in range(len(wits)):
                a, b = e[i][g], e[j][g]
                if a is not None and b is not None:
                    m.AddBoolOr([eq[i, j].Not(), a.Not(), b])
                    m.AddBoolOr([eq[i, j].Not(), b.Not(), a])
                elif a is not None or b is not None:
                    m.AddBoolOr([eq[i, j].Not(), (a if a is not None else b).Not()])

    # the witness pairs up the state's squares except the ones it fixes
    for i, x in enumerate(CELLS):
        par, q = m.NewBoolVar(""), m.NewIntVar(0, NC // 2, "")
        m.Add(size[i] == 2 * q + par)
        free = []
        for g, (_k, _p, _f, fx) in enumerate(wits):
            if e[i][g] is None:
                continue
            if not fx:
                free.append(e[i][g])
                continue
            terms = [1 if y == x else eq[i, IDX[y]] for y in fx]
            k = m.NewIntVar(0, len(fx), "")
            m.Add(sum(terms) - par == 2 * k).OnlyEnforceIf(e[i][g])
        m.Add(par + sum(free) <= 1)

    # the square the state's witness fixes, when it fixes exactly one
    cap = [m.NewBoolVar("") for _ in range(NC)]
    for i, x in enumerate(CELLS):
        ts = []
        for g, (_k, _p, _f, fx) in enumerate(wits):
            if e[i][g] is None or x not in fx:
                continue
            t = m.NewBoolVar("")
            others = [eq[i, IDX[y]] for y in fx if y != x]
            m.AddImplication(t, e[i][g])
            for o in others:
                m.AddImplication(t, o.Not())
            m.AddBoolOr([t, e[i][g].Not()] + others)
            ts.append(t)
        m.AddBoolOr(ts).OnlyEnforceIf(cap[i])
        for t in ts:
            m.AddImplication(t, cap[i])

    # capitols travel cost is 0, otherwise the cheapest step plus the neighbour's cost
    d = [m.NewIntVar(0, DMAX, "") for _ in range(NC)]
    for i, x in enumerate(CELLS):
        m.Add(d[i] == 0).OnlyEnforceIf(cap[i])
        steps = []
        for y in nbrs(*x):
            j = IDX[y]
            w = m.NewIntVar(1, NC, "")
            m.AddMinEquality(w, [size[i], size[j]])
            s = m.NewIntVar(1, DMAX + NC, "")
            m.Add(s == w + d[j])
            m.Add(d[i] <= s)
            steps.append(s)
        best = m.NewIntVar(1, DMAX + NC, "")
        m.AddMinEquality(best, steps)
        m.Add(d[i] == best).OnlyEnforceIf(cap[i].Not())
        if CLUES[x[0]][x[1]] is not None:
            m.Add(d[i] == CLUES[x[0]][x[1]])

    # a clue square's state only reaches squares within size-1 steps through possible members
    for a in [x for x in CELLS if CLUES[x[0]][x[1]] is not None]:
        ia = IDX[a]
        lv = [m.NewIntVar(0, NC, "") for _ in range(NC)]
        m.Add(lv[ia] == 0)
        for i, x in enumerate(CELLS):
            if i == ia:
                continue
            t, u = m.NewIntVar(0, NC, ""), m.NewIntVar(0, NC, "")
            m.AddMinEquality(t, [lv[IDX[y]] for y in nbrs(*x)])
            m.AddMinEquality(u, [t + 1, NC])
            m.Add(lv[i] >= u)
            m.Add(lv[i] <= size[ia] - 1).OnlyEnforceIf(eq[ia, i])
            m.Add(lv[i] == NC).OnlyEnforceIf(eq[ia, i].Not())

    for x, v in HINT_SIZES.items():
        m.Add(size[IDX[x]] == v)
    for y in HINT_SAME[1:]:
        m.Add(eq[IDX[HINT_SAME[0]], IDX[y]] == 1)
    x, ctr = HINT_ROT_CENTRE
    g = next(g for g, w in enumerate(wits) if w[0] == "rot" and w[1] == (2 * ctr[0], 2 * ctr[1]))
    m.Add(e[IDX[x]][g] == 1)
    return m, rid, eq, size, cap


def solve():
    m, rid, eq, size, cap = build()
    solver = cp_model.CpSolver()
    solver.parameters.num_workers = 8
    solver.parameters.max_time_in_seconds = 3600
    while True:
        st = solver.Solve(m)
        assert st in (cp_model.OPTIMAL, cp_model.FEASIBLE), solver.StatusName(st)
        labels = [[solver.Value(rid[IDX[(r, c)]]) for c in range(N)] for r in range(N)]
        regs = {}
        for x in CELLS:
            regs.setdefault(labels[x[0]][x[1]], []).append(x)
        cuts = 0
        for cells in regs.values():
            claimed = [x for x in cells if solver.Value(cap[IDX[x]])]
            if claimed and capitol(cells) is None:  # another symmetry fixes more or fewer squares: no capitol
                i0 = IDX[claimed[0]]
                k = m.NewBoolVar("")
                m.Add(size[i0] == len(cells)).OnlyEnforceIf(k)
                m.Add(size[i0] != len(cells)).OnlyEnforceIf(k.Not())
                m.AddBoolOr([eq[i0, IDX[y]].Not() for y in cells if IDX[y] != i0] + [k.Not(), cap[i0].Not()])
                cuts += 1
        if not cuts:
            return labels


if __name__ == "__main__":
    labels = solve()
    size, caps, dist = evaluate(labels)
    bad = [(x, CLUES[x[0]][x[1]], dist[x]) for x in CELLS if CLUES[x[0]][x[1]] is not None
           and CLUES[x[0]][x[1]] != dist[x]]
    assert not bad, bad
    for row in size:
        print(" ".join(f"{v:3d}" for v in row))
    print(sum(sum(row) ** 2 for row in size))
