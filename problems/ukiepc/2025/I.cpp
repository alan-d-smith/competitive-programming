#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ull n;
    cin >> n;

    ull bits = ceil(log2l(n+1));
    ull ans = 1;
    while (ans < bits) ans = ans << 1;
    cout << ans << ((ans == 1) ? " bit": " bits");
}