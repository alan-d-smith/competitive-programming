/**
 * Author: Alan Smith
 * Description: Bitmask DP over subsets, for $1 \le n \le$ about 18: a set S of items is the int whose bit i is
 *  set iff i is in S. tsp is the travelling salesman problem: dp[S][v] is the cheapest path that starts at 0,
 *  visits exactly the nodes in S and ends at v; tsp returns the cheapest round trip through all nodes.
 *  The same pattern assigns n people to n tasks: dp[S] is the best way to give the first popcount(S)
 *  people the tasks in S. Memory is $2^n n$ values, so use int if the costs fit.
 * Usage: ll cost = tsp(d); // d[u][v] = cost from u to v, big but finite (not LLONG_MAX) if no edge
 * Time: O(2^n n^2)
 */
ll tsp(const vector<vector<ll>>& d) {
	int n = sz(d), full = (1 << n) - 1;
	vector<vector<ll>> dp(1 << n, vector<ll>(n, LLONG_MAX));
	dp[1][0] = 0;
	rep(S,1,full+1) rep(v,0,n) if (dp[S][v] != LLONG_MAX)
		rep(u,0,n) if (!(S >> u & 1)) {
			ll& to = dp[S | 1 << u][u];
			to = min(to, dp[S][v] + d[v][u]);
		}
	ll best = LLONG_MAX;
	rep(v,0,n) if (dp[full][v] != LLONG_MAX)
		best = min(best, dp[full][v] + d[v][0]);
	return best;
}
