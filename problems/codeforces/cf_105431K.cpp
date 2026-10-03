#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 10, 2
    long long N, P;
    cin >> N >> P;

    long long remaining = N-P; // one centred P
    remaining %= (2*P);
    if (remaining == P) remaining = 0;

    cout << remaining;
}