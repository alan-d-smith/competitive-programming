/**
 * Author: Alan Smith
 * Description: Shortest distances from s, with negative weights allowed (else Dijkstra is faster).
 *  Set the global n of GraphBasics.cpp and put each edge in edges as (a, b, w). An undirected edge goes in
 *  both directions, so a negative one is a negative cycle by itself. Returns false if a negative cycle is
 *  reachable from s (some distances are then $-\infty$). Unreachable nodes get LLONG\_MAX.
 *  For real weights (e.g. $-\log$ of exchange rates), make w and dist double and only relax by more than $10^{-9}$.
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
	return false; }
