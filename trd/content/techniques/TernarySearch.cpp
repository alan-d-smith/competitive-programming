/**
 * Author: Alan Smith
 * Source: KACTL has the same idea as TernarySearch.h (integers) and GoldenSectionSearch.h (reals, fewer calls of f)
 * Description: The x in [lo, hi] where f is largest, if f strictly increases up to the peak and never increases
 *  after it (flat stretches before the peak break it). For the smallest value, use -f. Use it for e.g.
 *  a distance that shrinks then grows over time, or a sum of convex functions (minimum).
 *  ternaryMax calls f 200 times. ternaryMaxInt is for integers: the first x with $f(x) \ge f(x+1)$.
 * Usage: double x = ternaryMax(lo, hi, f); // f: a lambda taking and returning double
 * Time: O(\log(hi - lo)) for integers
 */
template<class F> double ternaryMax(double lo, double hi, F f) {
	rep(it,0,100) {
		double m1 = lo + (hi - lo) / 3, m2 = hi - (hi - lo) / 3;
		if (f(m1) < f(m2)) lo = m1; // the peak is right of m1
		else hi = m2;               // the peak is left of m2
	}
	return (lo + hi) / 2;
}
template<class F> ll ternaryMaxInt(ll lo, ll hi, F f) {
	while (lo < hi) {
		ll mid = lo + (hi - lo) / 2;
		if (f(mid) < f(mid + 1)) lo = mid + 1;
		else hi = mid;
	}
	return lo;
}
