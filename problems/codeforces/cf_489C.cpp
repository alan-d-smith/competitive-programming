#include <bits/stdc++.h>
using namespace std;

string ret(int m, int s)
{
    if (s == 0)
    {
        return ((m==1) ? "0 0" : "-1 -1");
    }
    if (9 * m < s) return "-1 -1";

    int bsum=0;
    string big(m, '0');

    // BIG
    int i=0;
    while (bsum < s)
    {
        int a = min(s-bsum, 9);
        bsum += a;
        big[i++] = '0'+a;
    }

    // SMALL
    string small = string(big);
    reverse(small.begin(), small.end());

    if (small[0]=='0')
    {
        small[0]='1';

        int i=1;
        while (small[i]=='0') i++;
        small[i]='0' + ((small[i]-'0')-1);
    }

    return small + " " + big;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, s;
    cin >> m >> s;

    cout << ret(m, s);
}