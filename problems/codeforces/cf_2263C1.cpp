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

        set<int> allowed;
        for (int i = 0; i < n; ++i) allowed.insert(i);

        for (int k=1; k<=n; ++k)
        {
            cin >> a;

            long long l = 1LL * k*a;
            long long r = min(1LL * n, 1LL*k*(a+1));

            if (l>=n) continue;

            auto it = allowed.lower_bound(l);
            while (it != allowed.end() && *it < r)
            {
                it = allowed.erase(it);
            }
        }

        cout << allowed.size() << '\n';

        bool first_output = false;
        for (auto& i : allowed)
        {
            if (first_output) cout << ' ';
            else first_output = true;

            cout << i;
        }
        cout << '\n';
    }

    return 0;
}