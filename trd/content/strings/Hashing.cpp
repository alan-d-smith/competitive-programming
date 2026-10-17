/**
 * Author: Alan Smith
 * Description: get(l, r) is a hash of s[l..r), so substrings (also of different strings) are compared in O(1).
 *  It is probabilistic: mod the prime $2^{61}-1$ with a random base, a comparison is wrong with probability
 *  at most $n/2^{61} \approx 10^{-13}$. Do not use mod $10^9+7$ (a set of $2 \cdot 10^5$ hashes has about 20
 *  collisions) or ull overflow (Thue--Morse strings break it for every base).
 *  longestRepeat finds the longest substring that appears twice (overlaps allowed) in $O(n \log n)$:
 *  binary search on the length L, with a set of the hashes of all length-L windows.
 *  The same finds the longest common substring of two strings.
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
