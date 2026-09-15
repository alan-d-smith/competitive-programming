#include <bits/stdc++.h>
using namespace std;

/*

let n=4, k=8

Z+ = {1, 2, 3, [4], 5, 6, 7, [8]} // multiples of n indicated by square brackets
     (1, 2, 3),    (5, 6, 7)

(floor of:)

8-1    7
--- = --- = 2 groups of (n-1) valid nums before k=8 - so 2 multiples of n skipped
4-1    3

let i be the kth positive integer that is not divisibly by n
i = k valid numbers + floor( (k-1) / (n-1) ) invalid numbers
i = k + floor( (k-1) / (n-1) )

*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int t, n, k;
    cin >> t;

    while (t--)
    {
        cin >> n >> k;
        cout << (k + (k-1)/(n-1)) << '\n';
    }

    return 0;
}