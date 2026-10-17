/**
 * Author: Alan Smith
 * Description: dp[l][r] is the answer for a[l..r), from every split point m: dp[l][m] and dp[m][r]. Go by increasing
 *  length. minMergeCost merges n piles in a row into one, two neighbours at a time, each merge costing
 *  the sum of the two; it returns the cheapest total. Same shape: matrix chain order, optimal bracketing.
 * Time: O(n^3), so n up to about 500
 */
ll minMergeCost(const vector<ll>& a) {
	int n = sz(a);
	vector<ll> p(n + 1);
	rep(i,0,n) p[i+1] = p[i] + a[i];
	vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
	rep(len,2,n+1) for (int l = 0; l + len <= n; l++) {
		int r = l + len;
		dp[l][r] = LLONG_MAX;
		rep(m,l+1,r) dp[l][r] = min(dp[l][r], dp[l][m] + dp[m][r]);
		dp[l][r] += p[r] - p[l]; // the last merge
	}
	return n ? dp[0][n] : 0;
}
