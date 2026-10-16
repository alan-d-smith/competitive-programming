/**
 * Author: Alan Smith
 * Description: Interval DP: dp[l][r] is the answer for the segment a[l..r), found by trying every split
 *  point m and combining dp[l][m] and dp[m][r]. Go by increasing length, so both parts are already done.
 *  minMergeCost: n piles in a row are merged into one, two neighbouring piles at a time, and each merge
 *  costs the total size of the two piles; returns the cheapest total. The same shape solves matrix chain
 *  multiplication, optimal bracketing and many ``remove or merge parts of a sequence'' problems.
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
