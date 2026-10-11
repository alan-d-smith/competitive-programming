#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, last=0, longest=1, current=0;
    cin >> n;

    while (n--)
    {
        cin >> a;

        if (a >= last) longest = max(++current, longest);
        else current = 1;

        last = a;
    }

    cout << longest;
}