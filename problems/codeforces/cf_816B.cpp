#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	
	int n, k, q;
	cin >> n >> k >> q;
	
	static vector<int> diff(200005);
	
	for (int i=0; i<n; ++i)
	{
		int l, r;
		cin >> l >> r;
		++diff[l];
		--diff[r+1];
	}
	
	static vector<long long> pref(200005);
	
	long long prev=0, admissible=0;
	for (int i=1; i<200005; ++i)
	{
		long long cur = diff[i-1] + prev;
		
		if (cur >= k)
		{
			admissible += 1;
		}
		pref[i] = admissible;
		prev = cur;
	}
	
	for (int i=0; i<q; ++i)
	{
		int a, b;
		cin >> a >> b;
		
		cout << pref[b+1]-pref[a] << "\n";
	}
}