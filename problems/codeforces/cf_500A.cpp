#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, t;
    cin >> n >> t;
    int next;
    
    cin >> next;
    ++next;

    bool possible = (t==1 || next == t);

    for (int i=2; i<n; ++i)
    {
        int tmp;
        cin >> tmp;

        if (i==next)
        {
            next=i+tmp;
            if (next == t) possible = true;
        }
    }

    cout << (possible ? "YES" : "NO" );
}