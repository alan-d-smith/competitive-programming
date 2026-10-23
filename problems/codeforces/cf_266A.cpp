#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    char prev, cur;
    cin >> prev;
    --n;
    
    
    int count=0;
    while (n--)
    {
    	cin >> cur;
    	
    	if (cur == prev) ++count;
    	prev = cur;
    }
    
    cout << count;
}
