/**
 * Author: Alan Smith
 * Description: Checks whether the undirected graph g can be 2-coloured so that every edge joins two
 *  different colours (e.g. split people into two teams with no rivals in the same team).
 *  g and n are the globals of GraphBasics.cpp, e.g. filled by readGraph (do not declare your own n).
 *  This holds iff there is no cycle of odd length. BFS from each uncoloured node gives each neighbour
 *  the other colour; afterwards col[u] is 0 or 1.
 * Usage: if (bipartite()) ... col[u] ...
 * Time: O(n + m)
 */
#include "GraphBasics.cpp"

vi col;
bool bipartite() {
	col.assign(n, -1);
	rep(s,0,n) if (col[s] < 0) {
		queue<int> q;
		q.push(s), col[s] = 0;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int v : g[u]) {
				if (col[v] < 0) col[v] = !col[u], q.push(v);
				else if (col[v] == col[u]) return false;
			}
		}
	}
	return true;
}
