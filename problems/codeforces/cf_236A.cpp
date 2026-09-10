#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string user;
    cin >> user;

    set<char> seen;
    for (char c : user) seen.insert(c);

    cout << ((seen.size() % 2 == 0) ? "CHAT WITH HER!" : "IGNORE HIM!");

    return 0;
}