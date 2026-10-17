/**
 * Author: Alan Smith
 * Description: For each right end r, move the left end l forward until a[l..r] is valid again. This works when a valid
 *  window stays valid if shrunk (e.g. sum $\le$ S with all a[i] $\ge$ 0, or at most k distinct values), so l only
 *  moves forward: O(n) in total. Both functions need all a[i] $\ge$ 0. longestWindow is the longest subarray
 *  with sum $\le$ S (0 if none); shortestWindow is the shortest with sum $\ge$ S > 0 (-1 if none).
 * Time: O(n)
 */
int longestWindow(const vector<ll>& a, ll S) {
	int best = 0;
	ll sum = 0;
	for (int l = 0, r = 0; r < sz(a); r++) {
		sum += a[r];
		while (l <= r && sum > S) sum -= a[l++];
		best = max(best, r - l + 1);
	}
	return best;
}
int shortestWindow(const vector<ll>& a, ll S) {
	int best = INT_MAX;
	ll sum = 0;
	for (int l = 0, r = 0; r < sz(a); r++) {
		sum += a[r];
		while (l < r && sum - a[l] >= S) sum -= a[l++]; // a[l] not needed
		if (sum >= S) best = min(best, r - l + 1);
	}
	return best == INT_MAX ? -1 : best;
}
