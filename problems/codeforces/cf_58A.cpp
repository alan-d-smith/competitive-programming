#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int i=0;
    string s, hello="hello";
    cin >> s;

    for (char& c: s)
    {
        if (c == hello[i]) i++;
    }

    cout << ((i==hello.size()) ? "YES": "NO");

    return 0;
}