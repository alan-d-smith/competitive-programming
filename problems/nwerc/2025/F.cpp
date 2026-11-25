#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    int ta=0, tb=0;

    for (int i=0; i<n; ++i)
    {
        cin >> a[i] >> b[i];

        ta+=a[i];
        tb+=b[i];
    }

    for (int i=0; i<n; ++i)
    {
        if (b[i] + (ta - a[i]) >= tb)
        {
            cout << i+1;
        }
        return 0;
    }

    cout << "impossible\n";

    return 0;
}
