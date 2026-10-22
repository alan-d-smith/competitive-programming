#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		
		if (n<k)
		{
			cout << "NO\n";
			continue;
		}
		
		if (n%2 == 1) // odd
		{
			if (k%2 == 1) // odd requires odd sums of odd numbers
			{
				cout << "YES\n";
				rep(i, 0, k-1) cout << 1 << ' ';
				cout << n-(k-1) << '\n';
			} else // even count of anything cant hit an odd n
			{
				cout << "NO\n";
			}
		} else // even
		{
			if (k%2 == 0) // even count of odds sums to even, and n >= k so it fits
			{
				cout << "YES\n";
				rep(i, 0, k-1) cout << 1 << ' ';
				cout << n-(k-1) << '\n';
			} else // odd count of odds would be odd, so has to be all even
			{
				if (2*k <= n)
				{
					cout << "YES\n";
					rep(i, 0, k-1) cout << 2 << ' ';
					cout << n-2*(k-1) << '\n';
				} else
				{
					cout << "NO\n";
				}
			}
		}
	}
}