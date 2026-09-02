#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, i;
    cin >> n;

    string s, s1;
    set<string> st = {};
    unordered_map<string, int> mp;

    while (n--)
    {
        cin >> s;
        if (st.contains(s))
        {
            mp[s]++;
            cout << s << mp[s] << endl;
        }
        else
        {
            cout << "OK" << endl;
            st.insert(s);
        }
    }

    return 0;
}