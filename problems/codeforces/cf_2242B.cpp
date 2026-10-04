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
        vector<int> a(n);

        for (size_t i=0; i<n; ++i) cin >> a[i];

        vector<int> pref1(n+1);
        vector<int> pref2(n+1);

        for (size_t i=0; i<n; ++i)
        {
            pref1[i+1] += pref1[i] + ((a[i] > 1) ? -1 : 1);
            pref2[i+1] += pref2[i] + ((a[i] > 2) ? -1 : 1);
        }

        /*
        Conditions:
        pref1[x] >= 0 && pref2[y] - pref2[x] >= 0
         */
        int mn = 1000000001; // min of pref2[x] values such that pref1[x] >= 0
        bool found = false;

        for (size_t i=1; i<n; ++i)
        {
            if (pref2[i] - mn >= 0)
            {
                cout << "YES\n";
                found = true;
                break;
            }

            if (pref1[i] >= 0)
            {
                mn = min(mn, pref2[i]);
            }
        }

        if (!found) cout << "NO\n";
    }

    return 0;
}