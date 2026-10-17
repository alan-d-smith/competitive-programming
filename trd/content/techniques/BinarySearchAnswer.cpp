/**
 * Author: Alan Smith
 * Description: For ``the smallest x that works'', when works(x) is false, ..., false, true, ..., true.
 *  firstTrue returns the smallest such x in [lo, hi), or hi if there is none. For ``the largest x that
 *  works'', find the first x that does not work and subtract 1. firstTrueReal does 100 halvings on reals.
 *  Write mid = lo + (hi - lo) / 2, as (lo + hi) / 2 can overflow, and for negative values rounds up, so
 *  the loop can run forever (lo = -3, hi = -2). For a sorted array, use lower\_bound (BinarySearch.cpp).
 *  minMaxPart splits a (all a[i] $\ge$ 0) into at most k contiguous parts with the smallest largest sum.
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
