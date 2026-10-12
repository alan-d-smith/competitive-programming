#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, h;
    cin >> n >> k;
    queue<int> q;

    long long sum=0, mn;

    int i=1, mi=1;
    while (q.size() < k)
    {
        cin >> h;
        q.emplace(h);
        sum += h;
        --n;
    }
    mn = sum;

    while (n--)
    {
        ++i;
        cin >> h;

        sum -= q.front();
        q.pop();

        sum += h;
        q.emplace(h);

        if (sum < mn)
        {
            mn = sum;
            mi = i;
        }
    }

    cout << mi;

    return 0;
}