#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

vi topoSort(const vector<vi>& gr)
{
    vi indeg(sz(gr)), q;
    for (auto& li : gr) for (int x: li) indeg[x]++;
    rep(i,0,sz(gr)) if (indeg[i] == 0) q.push_back(i);
    rep(j,0,sz(q)) for (int x : gr[q[j]])
        if (--indeg[x] == 0) q.push_back(x);
    return q;
}

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;
    vector<vi> gr(26);

    while (n--)
    {
        char a, sig, b, mn, mx;
        cin >> a >> sig >> b;
        mn = a, mx = b;

        if (sig=='>') {mn=b, mx=a;} 

        gr[mn-'a'].push_back(mx-'a');
    }

    vi ord = topoSort(gr);
    if (sz(ord) < 26) { cout << "IMPOSSIBLE"; return 0; }

    string str;
    cin >> str;

    int count[26] = {};
    for (char c : str) ++count[c-'a'];

    rep(i,0,26) if (count[ord[i]]>0) cout << string(count[ord[i]], (char) ('a' + ord[i]));
}