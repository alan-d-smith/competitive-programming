#include <bits/stdc++.h>
using namespace std;

static int bfs(int n, int m)
{
    priority_queue<
        tuple<int, int>,
        vector<tuple<int, int>>,
        greater<tuple<int, int>>
    > q;
    q.emplace(0, n);

    unordered_map<int, int> best_mp;

    while (q.size() > 0)
    {
        auto [presses, n] = q.top();
        q.pop();

        if (best_mp.contains(n) && best_mp[n] < presses) continue;

        if (n==m) return presses;
        if (n>m && (!best_mp.contains(m) || (n-m+presses)<best_mp[m]))
        {
            best_mp[m] = n-m+presses;
            q.emplace(best_mp[m], m);
            continue;
        }

        if (!best_mp.contains(n) || best_mp[n] > presses) best_mp[n] = presses;
        if (n>1 && (!best_mp.contains(n-1) || best_mp[n-1]>presses+1))
        {
            best_mp[n-1] = presses+1;
            q.emplace(presses+1, n-1);
        }
        if (2*n < 2*m && (!best_mp.contains(2*n) || best_mp[2*n]>presses+1))
        {
            best_mp[2*n] = presses+1;
            q.emplace(presses+1, n*2);
        }
    }

    return best_mp[m];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    if (m<=n) cout << n-m;
    else cout << bfs(n, m);

    return 0;
}