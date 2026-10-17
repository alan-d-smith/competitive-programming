/**
 * Author: Alan Smith
 * Description: Whether the undirected graph in the globals g and n of GraphBasics.cpp (do not declare your own n)
 *  can be 2-coloured so that every edge joins different colours, i.e. it has no odd cycle.
 *  If so, col[u] is 0 or 1. E.g. splitting people into two teams with no rivals in the same team.
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
	return true; }
