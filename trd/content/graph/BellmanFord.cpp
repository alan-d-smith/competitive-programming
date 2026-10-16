/**
 * Author: Alan Smith
 * Description: Shortest distances from s when some edge weights are negative (otherwise Dijkstra is faster).
 *  edges holds every edge as (a, b, w), from a to b with weight w, and the global n of GraphBasics.cpp must be
 *  the number of nodes. For an undirected edge add both directions, but then a negative edge is itself a negative cycle.
 *  For real weights (e.g. $-\log$ of exchange rates), use double for w and dist, and only count improvements over $10^{-9}$.
 *  Each round relaxes every edge. A shortest path has at most n - 1 edges, so without a negative cycle
 *  the distances stop changing within n - 1 rounds. Returns false if the n-th round still changes
 *  something: then a negative cycle is reachable from s, and some distances are really $-\infty$.
 *  Unreachable nodes get LLONG\_MAX.
 * Usage: n = 5; edges.push_back({a, b, w}); bool ok = bellmanFord(s);
 * Time: O(nm)
 */
#include "GraphBasics.cpp"

struct Edge { int a, b; ll w; };
vector<Edge> edges;
vector<ll> dist;
bool bellmanFord(int s) {
	dist.assign(n, LLONG_MAX);
	dist[s] = 0;
	rep(round,0,n) {
		bool changed = false;
		for (auto [a, b, w] : edges)
			if (dist[a] != LLONG_MAX && dist[a] + w < dist[b])
				dist[b] = dist[a] + w, changed = true;
		if (!changed) return true;
	}
	return false;
}
