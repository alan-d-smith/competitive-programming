#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /*
    1: -1
    0: +1
    */

    int n, mx=-1, cur=0, total=0, a;
    cin >> n;

    while (n--)
    {
        cin >> a;
        total += a;

        if (a == 1)
        {
            --cur;
            if (cur < 0) cur = 0;
        }
        else
        {
            ++cur;
            mx = max(cur, mx);
        }
    }

    cout << total + mx;
}