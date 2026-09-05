#include <bits/stdc++.h>
using namespace std;

#define WAITING 0
#define BEGUN 1
#define MID 2

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;

        vector<int> a(n);
        int last_nonzero=-1;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];

            if (a[i] != 0)
                last_nonzero = i;
        }

        int state = WAITING;
        bool first_outputed = false;

        int i=0, ai;
        while (n--)
        {
            ai = a[i++];

            if (ai==-1)
            {
                if (state==WAITING)
                {
                    cout << (first_outputed ? " 1" : "1");
                    if (!first_outputed) first_outputed = true;

                    state = BEGUN;
                    continue;
                }

                if (i - 1 < last_nonzero) cout << " 0";
                else cout << " 1";
                continue;
            }

            if (ai==0)
            {
                if (state==BEGUN || state==MID)
                {
                    state = MID;
                    cout << " 0";
                    continue;
                }

                cout << (first_outputed ? " 0" : "0");
                if (!first_outputed) first_outputed = true;
                continue;
            }

            if (ai==1)
            {
                state = BEGUN;
                cout << (first_outputed ? " 1" : "1");
                if (!first_outputed) first_outputed = true;
            }
        }
        cout << "\n";
    }

    return 0;
}