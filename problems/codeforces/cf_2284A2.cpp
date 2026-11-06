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
        cin >> n;
        long long a=0, b=0;

        vector<int> v(n);
        for (int i=0; i<n; ++i) cin >> v[i];
        sort(v.rbegin(), v.rend());

        for (int x : v)
        {
            if (a < b) a += 1LL << x;
            else b += 1LL << x;
        }

        cout << a*b << "\n";
    }
}