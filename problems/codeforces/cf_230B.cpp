#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

vector<bool> prime(MAX, true);
void sieve()
{
    prime[0] = false;
    prime[1] = false;
    prime[4] = false;

    for (int i = 4; i < MAX; i += 2) prime[i] = false;
    for (int i = 9; i < MAX; i += 3) prime[i] = false;

    for (long long i=5; i*i<MAX; i+=6)
    {
        // 6k-1
        if (prime[i])
        {
            for (long long j = i * i; j < MAX; j += i) prime[j] = false;
        }

        // 6k+1
        if ((i+2)*(i+2) <= MAX && prime[i + 2])
        {
            for (long long j = (i + 2) * (i + 2); j < MAX; j += (i + 2)) prime[j] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n;

    sieve();

    while (n--)
    {
        cin >> x;

        long long root = sqrt(x);
        if (root*root == x && prime[root])
        {
            cout << "YES\n";
        } else
        {
            cout << "NO\n";
        }
    }

    return 0;
}