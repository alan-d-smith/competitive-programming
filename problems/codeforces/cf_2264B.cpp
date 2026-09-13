#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, a, n, m;
    cin >> t;

    while (t--)
    {
        priority_queue<int> maxheap; // keep minimum m-1 elements
        long long score = LLONG_MIN;
        long long sum = 0;
        cin >> n >> m;

        for (size_t i=0; i<n; ++i)
        {
            cin >> a;

            if (maxheap.size() == m-1)
            {
                long long candidate = 1LL * m * a - sum;
                score = max(score, candidate);
            }

            if (maxheap.size()<m-1)
            {
                maxheap.push(a);
                sum += a;
                continue;
            }

            if (!maxheap.empty() && a < maxheap.top())
            {
                sum -= maxheap.top();
                maxheap.pop();
                maxheap.push(a);
                sum += a;
            }
        }

        cout << score << '\n';
    }

    return 0;
}