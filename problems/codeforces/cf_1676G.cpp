#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef vector<int> vi;

struct counter
{
    int white;
    int black;
    int nbalanced;
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        vi par(n);
        vector<struct counter> wbn(n);

        rep(i, 1, n) {cin >> par[i]; --par[i];}
        
        string col;
        cin >> col;
        rep(i, 0, n)
        {
            wbn[i] = {0, 0, 0};
            if (col[i] == 'W') wbn[i].white = 1;
            else wbn[i].black = 1;
        }

        for (int i=n-1; i>0; --i)
        {
            struct counter& curstruct = wbn[i];
            struct counter& parstruct = wbn[par[i]];

            if (curstruct.black == curstruct.white) ++curstruct.nbalanced;
            
            parstruct.white += curstruct.white;
            parstruct.black += curstruct.black;
            parstruct.nbalanced += curstruct.nbalanced;
        }

        struct counter& rootstruct = wbn[0];
        if (rootstruct.black == rootstruct.white) ++rootstruct.nbalanced;

        cout << rootstruct.nbalanced << '\n';
    }
}