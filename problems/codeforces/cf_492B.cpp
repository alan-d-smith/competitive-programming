#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l;
    cin >> n >> l;
    vector<int>a(n);

    int i=n;
    while (i--)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    double d = a[0];
    for (int i=1; i<n; ++i)
    {
        d = max(d, static_cast<double>(a[i]-a[i-1])/2);
    }
    if (l-a[n-1] > d) d = l-a[n-1];

    int dec = 10;
    std::printf("%.*f\n", dec, d);

    return 0;
}