#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, k;
    cin >> t;

    static int arr[1000][1000];

    while (t--)
    {
        cin >> n >> k;
        if (k<n || k==2*n)
        {
            cout << "-1\n";
            continue;
        }

        int cur = 0, i=0, j=0;
        int sidesteps = k-n;
        while (cur < k)
        {
            arr[i][j] = ++cur;
            ++i;
            ++j;

            if (sidesteps)
            {
                --j;
                --sidesteps;
            }
            if (i>=n) i=n-1;
        }

        int skip=k-n;
        i=k-n+1, j=0;
        while (cur < n*n)
        {
            while (i<n)
            {
                if (i!=skip) arr[i][j] = ++cur;
                ++i;
            }
            i=0;
            ++j;
            if (skip<n-1) ++skip;
        }

        // output matrix
        for (size_t y=0; y<n; ++y)
        {
            cout << arr[0][y];
            for (size_t x=1; x<n; ++x)
            {
                cout << ' ' << arr[x][y];
            }
            cout << '\n';
        }
    }

    return 0;
}