#include <bits/stdc++.h>
using namespace std;

/*
2 <= a, b, c

a * b * c = n

---

minimum possible n: 2 * 3 * 4 = 24

 */

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        if (n < 24)
        {
            cout << "NO\n";
            continue;
        }

        int a=0, b=0, c=n;
        for (int i=2; i*i<n; ++i)
        {
            if (c%i == 0)
            {
                if (a==0) a=i;
                else b=i;

                c /= i;

                if (b!=0 && b<c) break;
            }
        }

        if (a != 0 && b != 0 && b < c) cout << "YES\n" << a << ' ' << b << ' ' << c << '\n';
        else cout << "NO\n";
    }

    return 0;
}