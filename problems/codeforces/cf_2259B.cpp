#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, a, odd, evenodd, eveneven;
    cin >> t;

    while (t--)
    {
        odd=0, evenodd=0, eveneven=0;
        cin >> n;

        while (n--)
        {
            cin >> a;
            if (a%2 == 1)
            {
                ++odd;
            } else if ((a/2)%2 == 1)
            {
                ++evenodd;
            } else
            {
                ++eveneven;
            }
        }
        cout << max(odd, max(evenodd, eveneven)) << "\n";
    }

    return 0;
}