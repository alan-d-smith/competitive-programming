#include <bits/stdc++.h>
using namespace std;

int memo[4001];
int max_ribbons(int n, vector<int>& a)
{
    if (n == 0) return 0;
    if (n < a[0]) return -1;
    if (memo[n] != 0) return memo[n];

    int best=-1;
    for (int elem : a)
    {
        int cut = max_ribbons(n-elem, a);
        if (cut >= 0)
        {
            best = max(best, cut+1);
        }
    }

    memo[n] = best;
    return best;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    vector<int> a(3);
    cin >> n >> a[0] >> a[1] >> a[2];
    sort(a.begin(), a.end());

    cout << max_ribbons(n, a);

    return 0;
}