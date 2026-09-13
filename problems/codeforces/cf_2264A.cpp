#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, p;
    cin >> t;

    while (t--)
    {
        cin >> n;
        stack<int> s;
        queue<int> q;

        for (int i=1; i<=n; ++i)
        {
            cin >> p;
            if (p!=i)
            {
                q.push(i);
                s.push(p);
            }
        }

        bool possible = true;
        while (!q.empty())
        {
            if (q.front() != s.top())
            {
                possible = false;
                break;
            }
            q.pop();
            s.pop();
        }

        if (possible) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}