#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, b;
    cin >> a >> b;

    /*
a_n = a*3^{n}
b_n = b*2^(n)

a*3^{n} = b*2^(n)

a/b = (2/3)^{n}

ln(a/b)/ln(2/3) = n

floor(n) + 1 is the first year Limak is bigger
     */

    cout << floor(log(a/b)/log(2.0/3.0) + 1e-9) + 1;

    return 0;
}