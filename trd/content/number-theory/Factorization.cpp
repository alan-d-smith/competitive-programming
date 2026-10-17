/**
 * Author: Alan Smith
 * Source: euclid follows KACTL's euclid.h (CC0)
 * Description: Trial division, for n up to about $10^{12}$. factorize gives the prime factors in increasing
 *  order with repeats ($12 = 2 \cdot 2 \cdot 3$); divisors gives all divisors, sorted.
 *  euclid finds x, y with ax + by = gcd(a, b) and returns the gcd. modInverse(a, m) is the x with
 *  $ax \equiv 1 \pmod m$ for any m, prime or not; it exists iff gcd(a, m) = 1, and is -1 otherwise.
 * Time: O(\sqrt n) for factorize and divisors, O(\log m) for euclid and modInverse
 */
vector<ll> factorize(ll n) {
	vector<ll> f;
	for (ll p = 2; p * p <= n; p++)
		while (n % p == 0) f.push_back(p), n /= p;
	if (n > 1) f.push_back(n);
	return f;
}
vector<ll> divisors(ll n) {
	vector<ll> d;
	for (ll i = 1; i * i <= n; i++) if (n % i == 0) {
		d.push_back(i);
		if (i != n / i) d.push_back(n / i);
	}
	sort(all(d));
	return d;
}
ll euclid(ll a, ll b, ll& x, ll& y) {
	if (!b) return x = 1, y = 0, a;
	ll g = euclid(b, a % b, y, x);
	y -= a / b * x;
	return g;
}
ll modInverse(ll a, ll m) {
	ll x, y;
	if (euclid((a % m + m) % m, m, x, y) != 1) return -1;
	return (x % m + m) % m;
}
