#include <bits/stdc++.h>
using namespace std;

bool is_prime(long long x)
{
    if (x <= 1) return false;
    if (x <= 3) return true;
    if (x%3==0 || x%2==0) return false;

    for (int i=5; i*i<=x; i+=6)
    {
        if (x%i==0 || x%(i+2) == 0) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n;

    while (n--)
    {
        cin >> x;

        long long root = sqrt(x);
        if (root*root == x && is_prime(root))
        {
            cout << "YES" << endl;
        } else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}