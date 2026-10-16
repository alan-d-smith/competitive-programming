/**
 * Author: Alan Smith
 * Description: Minimum spanning tree: the cheapest set of n - 1 edges that connects all n nodes.
 *  Goes through the edges from cheapest to most expensive and keeps each edge that joins two
 *  different groups. Returns the total weight; the kept edges are in mst, and the graph is
 *  connected iff sz(mst) == n - 1. For a maximum spanning tree, sort in decreasing order.
 * Usage: edges.push_back({w, a, b}); ll cost = kruskal(n, edges);
 * Time: O(m \log m)
 */
#include "../data-structures/UnionFind.h"

typedef tuple<ll, int, int> WEdge; // (w, a, b)
vector<WEdge> mst;
ll kruskal(int n, vector<WEdge> edges) {
	sort(all(edges));
	UF uf(n);
	mst.clear();
	ll total = 0;
	for (auto [w, a, b] : edges)
		if (uf.join(a, b)) total += w, mst.push_back({w, a, b});
	return total;
}
