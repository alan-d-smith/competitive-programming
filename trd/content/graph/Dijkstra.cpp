/**
 * Author: Alan Smith
 * Description: Shortest distances from s when no edge weight is negative.
 *  adj[u] holds a pair (v, w) for each edge from u to v with weight w (add both directions if undirected).
 *  Unreachable nodes get LLONG\_MAX. The priority queue always gives the closest node that is not done yet.
 *  If you only need s to t, pass t to stop early: then only dist[t] and path(t) are final.
 *  par[v] is the node before v on a shortest path, and path(t) follows it back to s.
 * Usage: adj[a].push_back({b, w});
 *  dijkstra(s, t); ll d = dist[t]; vi p = path(t);
 * Time: O((n + m) \log m)
 */
#include "GraphBasics.cpp"

typedef pair<ll, int> pli;
vector<pair<int, ll>> adj[MAXN];
vector<ll> dist;
vi par;
void dijkstra(int s, int t = -1) {
	dist.assign(n, LLONG_MAX), par.assign(n, -1);
	priority_queue<pli, vector<pli>, greater<pli>> pq;
	dist[s] = 0;
	pq.push({0, s});
	while (!pq.empty()) {
		auto [d, u] = pq.top(); pq.pop();
		if (d > dist[u]) continue; // u was already done
		if (u == t) break;         // dist[t] is final
		for (auto [v, w] : adj[u]) if (d + w < dist[v]) {
			dist[v] = d + w, par[v] = u;
			pq.push({dist[v], v});
		}
	}
}
vi path(int t) { // s, ..., t, or empty if unreachable
	if (dist[t] == LLONG_MAX) return {};
	vi p;
	for (int u = t; u != -1; u = par[u]) p.push_back(u);
	reverse(all(p));
	return p;
}
