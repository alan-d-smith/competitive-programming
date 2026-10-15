/**
 * Author: Alan Smith
 * Description: set, multiset and map are sorted, with everything $O(\log n)$.
 *  Use their own s.lower\_bound(x), as lower\_bound(all(s), x) is $O(n)$ on them.
 *  unordered\_set/map are $O(1)$ on average, but slow on anti-hash tests.
 *  pair and tuple compare lexicographically.
 */
vector<T> v(n, val);
v.push_back(x); v.pop_back(); v.back(); v.resize(n);
v.insert(v.begin() + i, x); v.erase(v.begin() + i); // O(n)
sort(all(v)); v.erase(unique(all(v)), v.end());     // dedupe

set<T> s; multiset<T> ms;
s.insert(x); s.erase(x); s.count(x); s.contains(x);
*s.begin(); *s.rbegin();            // min, max
s.lower_bound(x); s.upper_bound(x);
ms.erase(x);                        // erases ALL copies of x
ms.erase(ms.find(x));               // one copy, x must exist

map<K, V> m;
m[k]++;                             // inserts V() if missing
m.count(k); m.erase(k); m.lower_bound(k);
for (auto& [key, val] : m) {}       // in key order
unordered_set<T> us; unordered_map<K, V> um;

priority_queue<T> pq;               // max-heap
pq.push(x); pq.top(); pq.pop(); pq.size();
priority_queue<T, vector<T>, greater<T>> minpq;
deque<T> dq;                        // dq[i] O(1)
dq.push_front(x); dq.pop_front(); dq.push_back(x); dq.front();
queue<T> q; q.push(x); q.front(); q.pop();
stack<T> st; st.push(x); st.top(); st.pop();

bitset<N> b;                        // operations O(N / 64)
b[i] = 1; b.count(); b.set(); b.reset(); b.flip(); b <<= k;
b._Find_first(); b._Find_next(i);   // next set bit, N if none

string str;
str.substr(pos, len); str.find(t) == string::npos;
to_string(x); stoi(str); stoll(str);
auto [fst, snd] = pr;
