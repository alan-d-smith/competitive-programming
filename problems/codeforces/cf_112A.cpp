#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    int n = a.length();
    int i = 0;

    char c1, c2;

    while (n--)
    {
        c1 = tolower(a[i]);
        c2 = tolower(b[i]);

        if (c1 < c2)
        {
            cout << -1;
            return 0;
        } else if (c1 > c2)
        {
            cout << 1;
            return 0;
        }

        i++;
    }

    cout << 0;
    return 0;
}