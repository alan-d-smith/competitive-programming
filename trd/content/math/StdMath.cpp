/**
 * Author: Alan Smith
 * Description: C++20, all in bits/stdc++.h. Here $a, b$ are int/ll, $u$ is unsigned/ull
 *  (the \texttt{<bit>} functions only take unsigned) and $x, y, t$ are double.
 *  long is 32-bit on Windows (Codeforces): use long long.
 */
gcd(a, b); lcm(a, b);
__lg(a);           // floor(log2(a)), exact
bit_width(u);      // floor(log2(u)) + 1
bit_ceil(u);       // smallest power of 2 >= u
has_single_bit(u); popcount(u); __builtin_popcountll(a);
countl_zero(u); countr_zero(u); rotl(u, k); rotr(u, k);
log2(x);           // inexact for big integers
atan2(y, x);       // angle of (x, y) in [-pi, pi]
hypot(x, y); sqrt(x); cbrt(x);
midpoint(a, b);    // (a + b) / 2 without overflow
lerp(x, y, t);     // x + t * (y - x)

INT_MAX    == 2147483647;            // ~2.1e9
UINT_MAX   == 4294967295;            // ~4.3e9
LLONG_MAX  == 9223372036854775807;   // ~9.2e18
ULLONG_MAX == 18446744073709551615;  // ~1.8e19
INT_MIN == -INT_MAX - 1; LLONG_MIN == -LLONG_MAX - 1;
numeric_limits<ll>::max(); numeric_limits<ll>::min();
__int128 big;                        // ~1.7e38, no cin/cout
DBL_DIG == 15; LDBL_DIG == 18;       // significant digits
DBL_MAX;                             // ~1.8e308

accumulate(all(v), 0LL);                // 0 would sum in int
partial_sum(all(v), p.begin());         // v[0] + ... + v[i]
adjacent_difference(all(v), d.begin()); // v[i] - v[i-1]
sort(all(v)); do {} while (next_permutation(all(v)));
prev_permutation(all(v));               // false on wrap-around

numbers::pi; numbers::e; numbers::phi; numbers::sqrt2;
numbers::pi_v<long double>;
