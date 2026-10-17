/**
 * Author: Alan Smith
 * Description: Lowest common ancestor by binary lifting. build(root) uses the tree in the globals g and n of
 *  GraphBasics.cpp (do not declare your own n). up[j][u] is the $2^j$-th ancestor of u (the root's is itself).
 *  kth(u, k) is the k-th ancestor ($k \le$ depth[u]), and treeDist(a, b) counts the edges between a and b.
 *  For weighted distances, store each node's distance d from the root: $d_a + d_b - 2 d_{\mathrm{lca}}$.
 * Usage: build(0); int c = lca(a, b);
 * Time: O(n \log n) for build, O(\log n) per query
 */
#include "GraphBasics.cpp"

const int LOG = 18; // 2^LOG > n
int up[LOG][MAXN], depth[MAXN];
void build(int root) { // BFS, so deep trees are fine
	vi order = {root};
	up[0][root] = root, depth[root] = 0;
	rep(i,0,sz(order)) {
		int u = order[i];
		for (int v : g[u]) if (v != up[0][u]) {
			up[0][v] = u, depth[v] = depth[u] + 1;
			order.push_back(v);
		}
	}
	rep(j,1,LOG) rep(u,0,n) up[j][u] = up[j-1][up[j-1][u]];
}
int kth(int u, int k) {
	rep(j,0,LOG) if (k >> j & 1) u = up[j][u];
	return u;
}
int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	a = kth(a, depth[a] - depth[b]);
	if (a == b) return a;
	for (int j = LOG - 1; j >= 0; j--)
		if (up[j][a] != up[j][b]) a = up[j][a], b = up[j][b];
	return up[0][a];
}
int treeDist(int a, int b) {
	return depth[a] + depth[b] - 2 * depth[lca(a, b)];
}
