#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, k, c;
    cin >> t;

    while (t--)
    {
        cin >> k;
        int x2=0, xgt2=0;
        while (k--)
        {
            cin >> c;
            if (c>2) ++xgt2;
            else if (c==2) ++x2;
        }

        cout << ((xgt2>0 || x2 > 1) ? "YES\n" : "NO\n");
    }

    return 0;
}