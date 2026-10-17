/**
 * Author: Alan Smith
 * Description: DP over subsets for $1 \le n \le$ about 18, with a set S of items stored as the bits of an int.
 *  tsp is the cheapest round trip through all nodes: dp[S][v] is the cheapest path from 0 that visits
 *  exactly S and ends at v. Assigning n people to n tasks works the same way: dp[S] gives the first
 *  popcount(S) people the tasks in S. Memory is $2^n n$ values, so use int if the costs fit.
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
