#include <bits/stdc++.h>
using namespace std;

int main()
{
    const int t4 = 10000;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int xs, ys, xt, yt, xp, yp;
    cin >> xs >> ys >> xt >> yt >> xp >> yp;

    cout << 3 << '\n';
    int xm=xs, ym=ys;

    // step 1: border along x
    if (xm < xp)
    {
        xm = -t4-1;
    } else
    {
        xm = t4+1;
    }
    cout << xm << ' ' << ym << '\n';

    // step 2: corner along y
    if (yt < yp)
    {
        ym = -t4-1;
    } else
    {
        ym = t4+1;
    }
    cout << xm << ' ' << ym << '\n';

    // step 3: match target x
    cout << xt << ' ' << ym;
}