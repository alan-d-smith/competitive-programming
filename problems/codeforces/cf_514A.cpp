#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned long long x, ret=0, pow_10 = 1;
    cin >> x;
    unsigned long long last_pow_10 = 1;
    while(last_pow_10*10 <= x) last_pow_10*=10;

    while(pow_10 <= last_pow_10)
    {
        int d = x%10;
        x/=10;

        if (d==9 && last_pow_10 == pow_10)
        {
            ret += 9 * pow_10;
        } else ret += min(d, 9-d) * pow_10;

        pow_10*=10;
    }

    cout << ret;

    return 0;
}