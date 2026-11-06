#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;

        unsigned int a, b;

        a = n/2 + ((n%2 == 1) ? 1 : 0);
        b = n/2;

        cout << a*b << "\n";
    }
}