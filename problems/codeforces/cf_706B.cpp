#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n;

    vector<int>x(n);

    int i=0;
    while (n--) cin >> x[i++];
    sort(x.begin(), x.end());

    cin >> q;
    int m;

    while (q--)
    {
        cin >> m;
        cout << distance(x.begin(), upper_bound(x.begin(), x.end(), m)) << "\n";
    }

    return 0;
}