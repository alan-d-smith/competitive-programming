/**
 * Author: Alan Smith
 * Description: dp[i][j] is the answer for a[0..i) and b[0..j). lcs is the longest common subsequence (in order, not
 *  necessarily contiguous); editDistance is the fewest single-character inserts, deletes and replacements
 *  turning a into b. To print a solution, walk back from dp[n][m], taking moves that give the stored values.
 * Time: O(nm)
 */
int lcs(const string& a, const string& b) {
	int n = sz(a), m = sz(b);
	vector<vi> dp(n + 1, vi(m + 1));
	rep(i,1,n+1) rep(j,1,m+1)
		dp[i][j] = a[i-1] == b[j-1] ? dp[i-1][j-1] + 1
		                            : max(dp[i-1][j], dp[i][j-1]);
	return dp[n][m];
}
int editDistance(const string& a, const string& b) {
	int n = sz(a), m = sz(b);
	vector<vi> dp(n + 1, vi(m + 1));
	rep(i,0,n+1) dp[i][0] = i; // delete all of a[0..i)
	rep(j,0,m+1) dp[0][j] = j; // insert all of b[0..j)
	rep(i,1,n+1) rep(j,1,m+1)
		dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1,
		                dp[i-1][j-1] + (a[i-1] != b[j-1])});
	return dp[n][m];
}
