/**
 * Author: Alan Smith
 * Description: String hashing: after O(n) setup, get(l, r) is a number for the substring s[l..r)
 *  (r exclusive), so two substrings can be compared in O(1). Equal strings always get equal hashes.
 *  It is probabilistic: different strings can also get equal hashes. Here that is very unlikely, as we
 *  work mod the prime $p = 2^{61}-1$ with a random base B: a comparison is wrong with probability at most
 *  $n/p \approx 10^{-13}$. It goes wrong with a small modulus like $10^9+7$ (a set of $2 \cdot 10^5$ hashes
 *  then has about 20 collisions) or with ull overflow (mod $2^{64}$), which Thue--Morse strings break for
 *  every base. All Hash objects share B, so substrings of different strings can be compared too.
 *  For example, longestRepeat finds the longest substring that appears at least twice (possibly overlapping)
 *  in $O(n \log n)$. If some length-L substring repeats, so does a length-(L-1) one, so binary search on L, checking each L
 *  by putting the hash of every window of length L in a set. The same idea finds the longest common
 *  substring of two strings: put one string's windows in the set and look up the other's.
 * Usage: Hash h(s); if (h.get(a, a + len) == h.get(b, b + len)) ...
 * Time: O(n) setup, O(1) per get
 */
typedef unsigned long long ull;
const ull MOD = (1ULL << 61) - 1;
ull mul(ull a, ull b) { return (ull)((__uint128_t)a * b % MOD); }
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ull B = rng() % (MOD - 1000) + 500;

struct Hash {
	vector<ull> h, pw; // h[i] = hash of s[0..i), pw[i] = B^i
	Hash(const string& s) : h(sz(s) + 1), pw(sz(s) + 1, 1) {
		rep(i,0,sz(s)) {
			h[i+1] = (mul(h[i], B) + (unsigned char)s[i]) % MOD;
			pw[i+1] = mul(pw[i], B);
		}
	}
	ull get(int l, int r) { // hash of s[l..r)
		return (h[r] + MOD - mul(h[l], pw[r - l])) % MOD;
	}
};

string longestRepeat(const string& s) {
	Hash hs(s);
	int best = 0, at = 0;
	auto twice = [&](int L) { // a repeat of length L?
		unordered_set<ull> seen;
		rep(i,0,sz(s)-L+1)
			if (!seen.insert(hs.get(i, i + L)).second) {
				at = i;
				return true;
			}
		return false;
	};
	for (int lo = 1, hi = sz(s) - 1; lo <= hi;) {
		int mid = (lo + hi) / 2;
		if (twice(mid)) best = mid, lo = mid + 1;
		else hi = mid - 1;
	}
	return s.substr(at, best);
}
