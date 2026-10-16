/**
 * Author: Alan Smith
 * Source: follows KACTL's KMP.h (Johan Sannemo, CC0)
 * Description: Knuth--Morris--Pratt. pi[i] is the length of the longest proper prefix of s[0..i] that is
 *  also a suffix of it. match(text, pat) returns the start of every occurrence of pat in text, overlapping
 *  ones included: in pi of pat + separator + text, a value equal to the length of pat marks the end of a match.
 *  The separator is char 0, so neither string may contain it (e.g. numbers stored as chars): pick another one then.
 *  The shortest period of s is $p = n - $ pi[n-1], and s is a shorter block repeated iff $p < n$ and p divides n.
 * Usage: vi starts = match(text, pat);
 * Time: O(n + m)
 */
vi prefixFunction(const string& s) {
	vi pi(sz(s));
	rep(i,1,sz(s)) {
		int k = pi[i-1]; // try to extend the previous match
		while (k > 0 && s[i] != s[k]) k = pi[k-1];
		if (s[i] == s[k]) k++;
		pi[i] = k;
	}
	return pi;
}
vi match(const string& text, const string& pat) {
	vi pi = prefixFunction(pat + '\0' + text), res;
	int p = sz(pat);
	rep(i,2*p,sz(pi)) if (pi[i] == p) res.push_back(i - 2*p);
	return res;
}
