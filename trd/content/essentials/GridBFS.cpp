/**
 * Author: Alan Smith
 * Description: Fewest steps from (sr, sc) to every cell of the grid g, moving up, down, left or right
 *  and never onto a '\#' ($-1$ if unreachable). For 8 directions, add the diagonals to dr and dc.
 *  For several starts, push them all first with distance 0. Puzzles: BFS over states (position,
 *  keys held, \dots) in the same way.
 * Usage: auto d = gridBFS(g, sr, sc); // g: the rows of the grid
 * Time: O(hw)
 */
const int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
vector<vi> gridBFS(const vector<string>& g, int sr, int sc) {
	int h = sz(g), w = sz(g[0]);
	vector<vi> d(h, vi(w, -1));
	queue<pii> q;
	q.push({sr, sc}), d[sr][sc] = 0;
	while (!q.empty()) {
		auto [r, c] = q.front(); q.pop();
		rep(k,0,4) {
			int nr = r + dr[k], nc = c + dc[k];
			if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
			if (g[nr][nc] == '#' || d[nr][nc] >= 0) continue;
			d[nr][nc] = d[r][c] + 1;
			q.push({nr, nc});
		}
	}
	return d;
}
