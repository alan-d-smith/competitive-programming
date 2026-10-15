/**
 * Author: Alan Smith
 * Description: Graph as adjacency lists g.
 *  bfs(s) returns the unweighted shortest distances from s, -1 if unreachable.
 *  dfs(u) marks everything reachable from u in vis. Its recursion can get n deep, and 8 MB of stack fits only about $4 \cdot 10^4$ levels
 *  (Codeforces gives 256 MB); bfs also works for reachability. Usage counts connected components.
 * Usage: int c = 0; rep(u,0,n) if (!vis[u]) c++, dfs(u);
 * Time: O(n + m)
 */
const int MAXN = 2e5 + 5;
int n, m; // nodes 0..n-1, m edges
vector<int> g[MAXN];
void readGraph() {
	cin >> n >> m;
	rep(i,0,m) {
		int a, b; cin >> a >> b; a--, b--; // if 1-indexed
		g[a].push_back(b);
		g[b].push_back(a); // remove if directed
	}
}
vi bfs(int s) {
	vi dist(n, -1);
	queue<int> q;
	q.push(s), dist[s] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : g[u]) if (dist[v] < 0)
			dist[v] = dist[u] + 1, q.push(v);
	}
	return dist;
}
bool vis[MAXN];
void dfs(int u) {
	vis[u] = true;
	for (int v : g[u]) if (!vis[v]) dfs(v);
}
