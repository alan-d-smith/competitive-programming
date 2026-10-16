/**
 * Author: Alan Smith
 * Description: Maximum flow from s to t, which must differ (Dinic's algorithm). addEdge(a, b, c) adds a directed edge with
 *  capacity c; for an undirected edge, use addEdge(a, b, c, c). Each phase finds the distance of every
 *  node from s with BFS (only using edges with capacity left), then pushes flow along shortest paths with DFS.
 *  After maxFlow, inCut(u) says whether u is on s's side of a minimum cut, whose capacity equals the max flow.
 *  Bipartite matching: an edge from s to each left node, left to right, and right to t, all with capacity 1.
 * Usage: Dinic fl(n); fl.addEdge(a, b, c); ll f = fl.maxFlow(s, t);
 * Time: O(V^2 E), and O(E \sqrt V) for bipartite matching
 */
struct Dinic {
	struct E { int to; ll cap; };
	vector<E> e; // e[i ^ 1] is the reverse edge of e[i]
	vector<vi> adj;
	vi level, it;
	Dinic(int n) : adj(n), level(n), it(n) {}
	void addEdge(int a, int b, ll c, ll rc = 0) {
		adj[a].push_back(sz(e)), e.push_back({b, c});
		adj[b].push_back(sz(e)), e.push_back({a, rc});
	}
	bool bfs(int s, int t) {
		fill(all(level), -1);
		queue<int> q;
		q.push(s), level[s] = 0;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int i : adj[u])
				if (e[i].cap > 0 && level[e[i].to] < 0)
					level[e[i].to] = level[u] + 1, q.push(e[i].to);
		}
		return level[t] >= 0;
	}
	ll dfs(int u, int t, ll f) { // push at most f from u to t
		if (u == t) return f;
		for (; it[u] < sz(adj[u]); it[u]++) {
			int i = adj[u][it[u]], v = e[i].to;
			if (e[i].cap <= 0 || level[v] != level[u] + 1) continue;
			if (ll got = dfs(v, t, min(f, e[i].cap))) {
				e[i].cap -= got, e[i ^ 1].cap += got;
				return got;
			}
		}
		return 0;
	}
	ll maxFlow(int s, int t) {
		ll flow = 0;
		while (bfs(s, t)) {
			fill(all(it), 0);
			while (ll f = dfs(s, t, LLONG_MAX)) flow += f;
		}
		return flow;
	}
	bool inCut(int u) { return level[u] >= 0; }
};
