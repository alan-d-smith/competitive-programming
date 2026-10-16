/**
 * Author: Alan Smith
 * Description: Fenwick tree (binary indexed tree): change one element and get prefix sums, both in $O(\log n)$.
 *  Shorter and faster than a segment tree, but only for sums (or anything you can undo, like xor).
 *  add(i, x) does a[i] += x, and sum(r) is $a_0 + \dots + a_{r-1}$ (0-indexed), so the sum of a[l..r) is
 *  sum(r) - sum(l). For range add and point query instead: add x at l and -x at r, then a[i] is sum(i + 1).
 * Usage: Fenwick f(n); f.add(i, x); ll s = f.sum(r) - f.sum(l);
 * Time: O(\log n)
 */
struct Fenwick {
	vector<ll> t; // t[i] = a[i - (i & -i)] + ... + a[i - 1]
	Fenwick(int n) : t(n + 1) {}
	void add(int i, ll x) {
		for (i++; i < sz(t); i += i & -i) t[i] += x;
	}
	ll sum(int r) {
		ll s = 0;
		for (; r > 0; r -= r & -r) s += t[r];
		return s;
	}
};
