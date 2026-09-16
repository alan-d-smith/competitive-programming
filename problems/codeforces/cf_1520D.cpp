#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int t, n, a;
    cin >> t;

    while (t--)
    {
        cin >> n;
        unordered_map<int, int> mp;

        unsigned long long count=0;
        for (size_t i=0; i<n; ++i)
        {
            cin >> a;
            if (mp.contains(a-i)) count += mp[a-i];
            ++mp[a-i];
        }

        cout << count << '\n';
    }

    return 0;
}