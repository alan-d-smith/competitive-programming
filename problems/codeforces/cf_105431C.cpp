#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int K=0;

    bool odd = false;
    if (N % 2 == 1)
    {
        ++K;
        N-=3;
        odd = true;
    }

    K += N/2;

    cout << K << '\n';

    bool first = false;
    if (odd)
    {
        cout << 3;
        first = true;
    }

    while (N>0)
    {
        if (first) cout << ' ';
        else first = true;

        cout << 2;
        N-=2;
    }
}