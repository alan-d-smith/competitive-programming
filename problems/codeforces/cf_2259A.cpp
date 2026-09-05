#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, k, n, count;
    cin >> t;

    string s;

    while (t--)
    {
        count = 0;
        cin >> n >> k >> s;

        for (int farm=0; farm < n/k; ++farm)
        {
            int low = farm*k;

            ++count;
            for (int i=low; i<low+k; ++i)
            {
                if (s[i] == '0')
                {
                    --count;
                    break;
                }
            }
        }
        cout << count << "\n";
    }

    return 0;
}