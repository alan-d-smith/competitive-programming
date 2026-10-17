/**
 * Author: Alan Smith
 * Description: lds(a) returns the indices of a longest strictly decreasing subsequence of a: the longest
 *  increasing subsequence of the negated values. For non-increasing, make the change marked in LIS.h.
 * Usage: vi idx = lds(a); int len = sz(idx);
 * Time: O(n \log n)
 */
#include "LIS.h"

vi lds(vector<ll> a) {
	for (ll& x : a) x = -x;
	return lis(a);
}
