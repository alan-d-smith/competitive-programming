#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<int, long long> counts;
    int ai;

    while (n--)
    {
        cin >> ai;
        counts[ai] += ai;
    }

    vector<long long> dp = {0};
    int i=1, prev=-2;

    for (const auto& [key, value]: counts)
    {
        if (i==1) dp.push_back(value);
        else if (prev == key-1)
        {
            dp.push_back(max(value+dp[i-2], dp[i-1]));
        } else dp.push_back(value+dp[i-1]);

        prev=key;
        ++i;
    }

    cout << dp[i-1];

    return 0;
}