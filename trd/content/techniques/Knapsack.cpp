/**
 * Author: Alan Smith
 * Description: DPs over the capacity c = 0..W; items holds (weight, value) pairs. knapsack01 uses each item at most
 *  once: best[c] is the most value with weight $\le$ c, and c goes down so that no item is reused.
 *  knapsackUnbounded is the same with c going up. coinWays[c] is the number of ways to make exactly c,
 *  ignoring order (reduce mod p if asked); minCoins[c] is the fewest coins for exactly c (LLONG\_MAX if none).
 *  If W is too big but the values are small, swap roles: the least weight for each total value.
 * Usage: vector<ll> best = knapsack01(W, items); ll ans = best[W];
 * Time: O(nW)
 */
vector<ll> knapsack01(int W, const vector<pii>& items) {
	vector<ll> best(W + 1);
	for (auto [w, v] : items)
		for (int c = W; c >= w; c--)
			best[c] = max(best[c], best[c - w] + v);
	return best;
}
vector<ll> knapsackUnbounded(int W, const vector<pii>& items) {
	vector<ll> best(W + 1);
	for (auto [w, v] : items)
		for (int c = w; c <= W; c++)
			best[c] = max(best[c], best[c - w] + v);
	return best;
}
vector<ll> coinWays(int W, const vi& coins) {
	vector<ll> ways(W + 1);
	ways[0] = 1;
	for (int x : coins)
		for (int c = x; c <= W; c++) ways[c] += ways[c - x];
	return ways;
}
vector<ll> minCoins(int W, const vi& coins) {
	vector<ll> f(W + 1, LLONG_MAX);
	f[0] = 0;
	rep(c,1,W+1) for (int x : coins)
		if (x <= c && f[c - x] != LLONG_MAX) f[c] = min(f[c], f[c - x] + 1);
	return f;
}
