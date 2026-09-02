#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s, taxis;
    cin >> n;

    int mp[] = {0, 0, 0, 0};

    while (n--)
    {
        cin >> s;
        mp[s-1]++;
    }

    taxis = mp[3] + mp[2];
    mp[0] = max(0, mp[0]-mp[2]);

    taxis += mp[1]/2;
    mp[1] -= (mp[1]/2)*2;
    if (mp[1]==1)
    {
        taxis++;
        mp[0] = max(0, mp[0]-2);
    }
    taxis += ceil(static_cast<double>(mp[0])/4);

    cout << taxis;

    return 0;
}