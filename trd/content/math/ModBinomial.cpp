/**
 * Author: Alan Smith
 * Description: $\binom{n}{r}$ and ${}^nP_r$ mod a prime, 0 if $r < 0$ or $r > n$.
 * Time: O(N) for init, O(1) per query
 */
const ll mod = 1e9 + 7; // or 998244353
ll modpow(ll b, ll e) { // b^e, and 1/b if e = mod - 2
	ll r = 1;
	for (b %= mod; e; e /= 2, b = b * b % mod)
		if (e & 1) r = r * b % mod;
	return r;
}
const int N = 1e6;
ll f[N + 1], fi[N + 1]; // n! and 1/n!
void init() { // call once
	f[0] = 1;
	rep(i,1,N+1) f[i] = f[i-1] * i % mod;
	fi[N] = modpow(f[N], mod - 2);
	for (int i = N; i > 0; i--) fi[i-1] = fi[i] * i % mod;
}
ll nCr(int n, int r) {
	if (r < 0 || r > n) return 0;
	return f[n] * fi[r] % mod * fi[n-r] % mod;
}
ll nPr(int n, int r) {
	if (r < 0 || r > n) return 0;
	return f[n] * fi[n-r] % mod;
}
