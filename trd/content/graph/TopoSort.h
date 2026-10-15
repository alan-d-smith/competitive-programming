/**
 * Author: Unknown
 * Date: 2002-09-13
 * Source: predates tinyKACTL
 * Description: Topological sorting. Orders the nodes of a directed graph so that every edge goes
 * from left to right, e.g. so that each task comes after the tasks it depends on.
 * gr[u] lists the nodes that u has an edge to. Works by repeatedly taking a node with no incoming edges left.
 * If there is a cycle, the result has fewer than $n$ nodes, so this also detects cycles.
 * Usage: vi order = topoSort(vector<vi>(g, g + n));
 * Time: $O(|V|+|E|)$
 * Status: stress-tested
 */
#pragma once

vi topoSort(const vector<vi>& gr) {
	vi indeg(sz(gr)), q;
	for (auto& li : gr) for (int x : li) indeg[x]++;
	rep(i,0,sz(gr)) if (indeg[i] == 0) q.push_back(i);
	rep(j,0,sz(q)) for (int x : gr[q[j]])
		if (--indeg[x] == 0) q.push_back(x);
	return q;
}
