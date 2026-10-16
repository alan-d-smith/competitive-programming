/**
 * Author: Alan Smith
 * Description: Binary search on the answer, for ``the smallest x that works'' when works(x) goes
 *  false, ..., false, true, ..., true (if x works, so does every bigger x). firstTrue returns the
 *  smallest x in [lo, hi) that works, or hi if none does; each step halves the range.
 *  Take mid = lo + (hi - lo) / 2, not (lo + hi) / 2: the sum can overflow for big values, and for negative
 *  ones it rounds towards 0, so mid can equal hi and the loop never ends (e.g. lo = -3, hi = -2).
 *  For ``the largest x that works'' (true, ..., true, false, ...), find the first x that does not work and subtract 1.
 *  firstTrueReal does the same on real numbers with a fixed 100 halvings, so there is no off-by-one.
 *  For a sorted array, use lower\_bound instead (BinarySearch.cpp).
 *  minMaxPart is an example: cut a (all a[i] $\ge$ 0) into at most k contiguous parts, minimising the largest
 *  part's sum. Checking one cap greedily is easy, while finding the best cap directly is not.
 * Usage: ll x = firstTrue(lo, hi, works); // works: a lambda taking ll, returning bool
 * Time: O(\log(hi - lo)) calls to works
 */
template<class F> ll firstTrue(ll lo, ll hi, F works) {
	while (lo < hi) {
		ll mid = lo + (hi - lo) / 2;
		if (works(mid)) hi = mid;
		else lo = mid + 1;
	}
	return lo;
}
template<class F> double firstTrueReal(double lo, double hi, F works) {
	rep(it,0,100) {
		double mid = (lo + hi) / 2;
		if (works(mid)) hi = mid;
		else lo = mid;
	}
	return hi;
}

ll minMaxPart(const vector<ll>& a, int k) {
	auto works = [&](ll cap) { // can every part have sum <= cap?
		int parts = 1;
		ll cur = 0;
		for (ll x : a) {
			if (x > cap) return false;
			if (cur + x > cap) parts++, cur = 0;
			cur += x;
		}
		return parts <= k;
	};
	return firstTrue(0, accumulate(all(a), 0LL), works);
}
