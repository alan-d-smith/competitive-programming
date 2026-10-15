/**
 * Author: Simon Lindholm
 * Date: 2018-07-06
 * License: CC0
 * Description: Permutation -> integer conversion. (Not order preserving.)
 * Maps a permutation of 0..n-1 to a unique integer in [0, n!), e.g. to index
 * visited states in a BFS over permutations. Fits in an int for n <= 12.
 * Integer -> permutation can use a lookup table.
 * Time: O(n)
 */
#pragma once

int permToInt(vi& v) {
	int use = 0, i = 0, r = 0;
	for(int x:v) r = r * ++i + __builtin_popcount(use & -(1<<x)),
		use |= 1 << x;                     // (note: minus, not ~!)
	return r;
}
