#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, y, z;
    long long xr=0, yr=0, zr=0;
    cin >> n;

    while(n--)
    {
        cin >> x >> y >> z;
        xr+=x;
        yr+=y;
        zr+=z;
    }

    cout << (!(xr || yr || zr) ? "YES" : "NO");

    return 0;
}