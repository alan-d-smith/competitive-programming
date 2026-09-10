#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int count[4] = {};

    for (size_t i = 0; i < s.size(); i+=2) ++count[s[i]-'0'];

    bool first = true;
    for (int i=1; i<=3; ++i)
    {
        if (count[i]==0) continue;
        if (!first)
        {
            cout << '+';
        }
        first = false;

        cout << i;
        --count[i];

        while (count[i]--) cout << '+' << i;
    }

    return 0;
}