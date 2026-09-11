#include <bits/stdc++.h>
using namespace std;

#define AA11 1
#define RXCY 2

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string coord;

    while (n--)
    {
        cin >> coord;
        int type;
        if (coord[0] != 'R' || ('A' <= coord[1] && coord[1] <= 'Z')) type = AA11;
        else
        {
            size_t i=1;
            while (i<coord.length() && (coord[i] != 'C')) ++i;
            if (i==coord.length())
            {
                type = AA11;
            } else type = RXCY;
        }

        int r=0, c=0;
        if (type == AA11)
        {
            // parse type
            size_t i=0;
            while ('A' <= coord[i] && coord[i] <= 'Z')
            {
                c*=26;
                c+=coord[i]-'A'+1;
                ++i;
            }
            while (i<coord.length())
            {
                r*=10;
                r+=coord[i]-'0';
                ++i;
            }

            // output in alternate type
            cout << 'R' << r << 'C' << c << '\n';
        } else // type == RXCY
        {
            // parse type
            size_t i=1;
            while (coord[i]!='C')
            {
                r*=10;
                r+=coord[i]-'0';
                ++i;
            }
            ++i; // skip 'C'
            while (i<coord.length())
            {
                c*=10;
                c+=coord[i]-'0';
                ++i;
            }

            // output in alternate type
            string aa = "";
            while (c>0)
            {
                c--;
                aa += ('A'+ c%26);
                c/=26;
            }
            reverse(aa.begin(), aa.end());
            cout << aa << r << '\n';
        }
    }

    return 0;
}