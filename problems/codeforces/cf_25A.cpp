#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x1, x2, x3;
    cin >> n >> x1 >> x2 >> x3;
    n-=3;

    if (!(x1 % 2 == x2 % 2 && x2 % 2 == x3 % 2))
    {
        if (x1%2 == x2%2)
        {
            cout << 3;
        } else if (x2%2 == x3%2)
        {
            cout << 1;
        }
        else cout << 2;

        return 0;
    }

    int i=4;
    while(n--)
    {
        cin >> x2;
        if (x2%2 != x1%2)
        {
            cout << i;
            break;
        }
        ++i;
    }

    return 0;
}