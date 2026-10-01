#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    static int boys[102], girls[102];

    cin >> n;
    for (size_t i=0; i<n; ++i)
    {
        int tmp;
        cin >> tmp;
        ++boys[tmp];
    }

    int count = 0;
    cin >> m;
    for (size_t i=0; i<m; ++i)
    {
        int tmp;
        cin >> tmp;
        ++girls[tmp];
    }

    for (size_t i=1; i<=100; ++i)
    {
        if (girls[i]==0) continue;
        int delta;

        for (int j = -1; j <= 1; ++j)
        {
            if (boys[i + j] > 0 && girls[i] > 0)
            {
                delta = min(boys[i + j], girls[i]);
                count += delta;
                boys[i + j] -= delta;
                girls[i] -= delta;
            }
        }
    }

    cout << count;

    return 0;
}