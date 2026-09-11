#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t, a;
    cin >> n >> t;

    queue<int> q;
    long long max_len=0, len=0;
    int sum=0;

    while (n--)
    {
        cin >> a;

        while (len > 0 && sum+a > t)
        {
            const int tmp = q.front();
            q.pop();
            --len;
            sum-=tmp;
        }

        if (a <= t)
        {
            sum += a;
            ++len;
            if (len > max_len) max_len = len;

            q.push(a);
        }
    }

    cout << max_len;

    return 0;
}