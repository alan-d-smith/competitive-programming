/**
 * Author: Alan Smith
 * Description: Segment tree with lazy propagation, for range updates. add(l, r, x) adds x to every a[i] with
 *  $l \le i < r$, and sum(l, r) returns the sum of those a[i]. All a[i] start at 0; to start from an array,
 *  call add(i, i + 1, a[i]) for each i. Node v covers [lo, hi) and its children are 2v and 2v + 1.
 *  lz[v] is an add already applied to v but not yet to its children: push hands it down before visiting them.
 *  For range min instead of sum: apply does t[v] += x (not times the length), combine with min
 *  instead of +, and return LLONG\_MAX instead of 0 outside the range.
 * Usage: LazySeg st(n); st.add(l, r, x); ll s = st.sum(l, r);
 * Time: O(\log n) per operation
 */
struct LazySeg {
	int n;
	vector<ll> t, lz;
	LazySeg(int n) : n(n), t(4 * n), lz(4 * n) {}
	void apply(int v, int lo, int hi, ll x) {
		t[v] += x * (hi - lo), lz[v] += x;
	}
	void push(int v, int lo, int hi) {
		int mid = (lo + hi) / 2;
		apply(2*v, lo, mid, lz[v]), apply(2*v+1, mid, hi, lz[v]);
		lz[v] = 0;
	}
	void add(int v, int lo, int hi, int l, int r, ll x) {
		if (r <= lo || hi <= l) return;
		if (l <= lo && hi <= r) return apply(v, lo, hi, x);
		push(v, lo, hi);
		int mid = (lo + hi) / 2;
		add(2*v, lo, mid, l, r, x), add(2*v+1, mid, hi, l, r, x);
		t[v] = t[2*v] + t[2*v+1];
	}
	ll sum(int v, int lo, int hi, int l, int r) {
		if (r <= lo || hi <= l) return 0;
		if (l <= lo && hi <= r) return t[v];
		push(v, lo, hi);
		int mid = (lo + hi) / 2;
		return sum(2*v, lo, mid, l, r) + sum(2*v+1, mid, hi, l, r);
	}
	void add(int l, int r, ll x) { add(1, 0, n, l, r, x); }
	ll sum(int l, int r) { return sum(1, 0, n, l, r); }
};
