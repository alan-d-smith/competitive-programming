#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;

    while (t--)
    {
        int a;
        cin >> n;
        int zeros = 0;
        string res = "";

        while (n--)
        {
            cin >> a;
            if (a == 0)
            {
                if (zeros == 0)
                {
                    res += 'A';
                } else
                {
                    res += 'B';
                }
                ++zeros;
            } else
            {
                res += 'C';
            }
        }

        if (zeros == 0 || zeros > 1)
        {
            cout << "YES\n" << res << '\n';
        } else
        {
            cout << "NO\n";
        }
    }

    return 0;
}