/**
 * Author: Alan Smith
 * Description: Sums over subsets: afterwards D[m] is the sum of the old D[s] over all submasks s of m (masks using only bits of m).
 *  The example counts, for each mask m, how many numbers in a fit inside m, e.g. D[5] $= 2$ as 1 and 4 fit in 101.
 *  For sums over supersets, use \mbox{\texttt{if (!(i \& 1 << b)) D[i] += D[i | 1 << b]}} instead.
 *  The same loops with \texttt{-=} undo it, giving back the old D.
 * Time: O(K \cdot 2^K)
 */
const int K = 3;
vector<int> a = {1, 3, 3, 4};
vector<ll> D(1 << K, 0);
for (int x : a) D[x]++;      // D = [0, 1, 0, 2, 1, 0, 0, 0]
rep(b,0,K) rep(i,0,(1 << K))
	if (i & 1 << b) D[i] += D[i^(1 << b)];
// now D = [0, 1, 0, 3, 1, 2, 1, 4]
