/**
 * Author: Alan Smith
 * Description: The template's cin.exceptions(cin.failbit) crashes on a failed read, which catches misread input,
 *  but also at the end of the input: delete it to read until the input ends. After cin >>, read a line with
 *  getline(cin >> ws, s). End lines with '\textbackslash n' (endl is slow); do not mix cin/cout with scanf/printf.
 */
while (cin >> x) {}               // until the input ends
string s; getline(cin >> ws, s);  // a whole line
vector<string> g(h);
for (auto& row : g) cin >> row;   // a grid without spaces
cout << fixed << setprecision(9) << ans << '\n';
cout << (ok ? "YES" : "NO") << '\n';
rep(i,0,n) cout << v[i] << " \n"[i == n-1]; // spaces, then a newline
