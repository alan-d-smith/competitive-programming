/**
 * Author: Alan Smith
 * Description: Prefix sums: p[i] = a[0] + ... + a[i-1], so the sum of a[l..r) is p[r] - p[l] in O(1).
 *  In 2D, P[i][j] is the sum of g over rows $< i$ and columns $< j$, and any rectangle follows by inclusion-exclusion.
 *  countSum counts the subarrays with sum exactly k in $O(n \log n)$: pairs of prefix sums with p[r] - p[l] = k
 *  (works with negatives).
 *  Difference array: to add x to a[l..r) many times and read a only at the end, do d[l] += x and d[r] -= x
 *  (d has size n + 1), then add the running sum d[0] + ... + d[i] to each a[i]. For both online, use a Fenwick tree.
 * Usage: vector<ll> p = prefixSums(a); ll s = p[r] - p[l];
 *  auto P = prefixSums2D(g); // rows [r1, r2), columns [c1, c2):
 *  ll rect = P[r2][c2] - P[r1][c2] - P[r2][c1] + P[r1][c1];
 * Time: O(n) or O(nm) setup, O(1) per query
 */
vector<ll> prefixSums(const vector<ll>& a) {
	vector<ll> p(sz(a) + 1);
	rep(i,0,sz(a)) p[i+1] = p[i] + a[i];
	return p;
}
vector<vector<ll>> prefixSums2D(const vector<vector<ll>>& g) {
	int n = sz(g), m = n ? sz(g[0]) : 0;
	vector<vector<ll>> P(n + 1, vector<ll>(m + 1));
	rep(i,0,n) rep(j,0,m)
		P[i+1][j+1] = g[i][j] + P[i][j+1] + P[i+1][j] - P[i][j];
	return P;
}
ll countSum(const vector<ll>& a, ll k) {
	map<ll, ll> seen{{0, 1}}; // prefix sum -> times seen
	ll s = 0, cnt = 0;
	for (ll x : a) {
		s += x;
		if (seen.count(s - k)) cnt += seen[s - k];
		seen[s]++;
	}
	return cnt;
}
