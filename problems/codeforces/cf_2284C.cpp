#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<bool> is_prime(100005, true);
    for (int p=2; p*p<=100005; ++p)
    {
        if (is_prime[p])
        {
            for (int i=p*p; i<100005; i+=p) is_prime[i] = false;
        }
    }
    is_prime[0] = false;
    is_prime[1] = false;

    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i=0; i<n; ++i)
        {
            int x;
            cin >> x;

            while (!is_prime[x]) ++x;
            cout << x << " ";
        }
        cout << "\n";
    }
}