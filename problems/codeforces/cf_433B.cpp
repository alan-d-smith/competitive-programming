#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    vector<long long> pref1(n+1), pref2(n+1);

    for (size_t i=0; i<n; ++i)
    {
        cin >> v[i];
    }

    vector<int> u(v);
    sort(u.begin(), u.end());

    for (size_t i=0; i<n; ++i)
    {
        pref1[i+1] = pref1[i] + v[i];
        pref2[i+1] = pref2[i] + u[i];
    }

    int m, type, l, r;
    cin >> m;

    while (m--)
    {
        cin >> type >> l >> r;

        switch (type)
        {
            case 1:
                cout << pref1[r]-pref1[l-1] << '\n';
                break;
            case 2:
                cout << pref2[r]-pref2[l-1] << '\n';
                break;
            default:
                break;
        }
    }
}