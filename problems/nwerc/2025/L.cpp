#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, k, i, t;
    cin >> h >> w >> k >> i >> t;

    string s = "KIT" + string(k-1, 'K') + string(t-1, 'T') + string(i-1, 'I');

    for (int idx=0; idx<h*w; idx+=w)
    {
        cout << s.substr(idx, w) << '\n';
    }


    return 0;
}
