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
        int count=0;
        for (size_t i=0; i<n; ++i)
        {
            cin >> a;
            if (a==1) ++count;
        }
        if (count >= (n+1)/2)
        {
            cout << "Bessie\n";
        } else cout << "Elsie\n";
    }

    return 0;
}