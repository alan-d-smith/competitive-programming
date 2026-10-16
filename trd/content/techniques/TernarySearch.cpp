/**
 * Author: Alan Smith
 * Source: KACTL has the same idea as TernarySearch.h (integers) and GoldenSectionSearch.h (reals, fewer calls of f)
 * Description: Ternary search: finds the x in [lo, hi] where f is largest, when f strictly increases up to
 *  its peak and never increases after it (unimodal). Each step compares f at two points and drops the
 *  third of the range that cannot contain the peak. For the smallest value instead, use -f.
 *  Typical uses: a distance that shrinks and then grows over time, or a sum of convex functions (minimum).
 *  Flat stretches are fine after the peak but break it before the peak.
 *  ternaryMax evaluates f 200 times; each step keeps 2/3 of the range, so 100 steps shrink it by $10^{-17}$.
 *  ternaryMaxInt is for integers: the peak is the first x with $f(x) \ge f(x+1)$, found by binary search.
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
