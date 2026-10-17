/**
 * Author: Alan Smith
 * Description: Common causes of wrong answers. int overflows past $2.1 \cdot 10^9$ with no error: use ll when
 *  in doubt. v.size() is unsigned, so v.size() - 1 is huge for an empty v. sqrt, pow and log are inexact for
 *  big integers. A sort comparator must use <, never <=, or sort can crash.
 */
ll p = 1LL * a * b;        // not a * b
ll bit = 1LL << 40;        // not 1 << 40
rep(i,0,sz(v)-1) {}        // not i < v.size() - 1
int r = (a % m + m) % m;   // in [0, m) even if a < 0
ll up = (a + b - 1) / b;   // ceil(a / b) for a >= 0, b > 0
ll s = (ll)sqrtl(n);       // floor(sqrt(n)), n <= 9e18:
while (s * s > n) s--;
while ((s + 1) * (s + 1) <= n) s++;
sort(all(v), [](pii x, pii y) { return x.second < y.second; });
if (fabs(x - y) < 1e-9) {} // doubles "equal"
memset(arr, 0, sizeof arr); // only for 0 and -1
