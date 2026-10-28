#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    double lon, lat;
    
    cin >> t;
    
    while (t--)
    {
    	cin >> lon >> lat;
    	
    	if ((180>=abs(lon)) && (90>=abs(lat))) cout << "VALID\n";
    	else cout << "INVALID\n";
    }
}