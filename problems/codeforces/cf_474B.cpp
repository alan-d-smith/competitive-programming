#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a_i;
    cin >> n;
    vector<int> a(n);
    int sum=0;

    for (size_t i=0; i<n; ++i)
    {
        cin >> a_i;
        sum+=a_i;
        a[i] = sum;
    }

    int m, q;
    cin >> m;

    for (size_t i=0; i<m; ++i)
    {
        cin >> q;
        auto idx = lower_bound(a.begin(), a.end(), q);
        cout << (idx - a.begin() + 1) << '\n';
    }

    return 0;
}