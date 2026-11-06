#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, k;
    cin >> t;

    while (t--)
    {
        cin >> n >> k;

        vector<int> v(n);

        for (int i=0; i<n; ++i)
        {
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        if (n == k)
        {
            cout << "YES\n";
            for (int x : v) cout << x << " ";
            cout << "\n";
            continue;
        }

        int a, b;
        a = v[n-1];
        b = v[n-k-1];

        cout << ((a == b) ? "NO" : "YES") << "\n";
        if (a == b) continue;

        for (int i=k; i>0; --i) cout << v[n-i] << " ";
        for (int i=n-k-1; i>=0; --i) cout << v[i] << " ";
        cout << "\n";
    }
}