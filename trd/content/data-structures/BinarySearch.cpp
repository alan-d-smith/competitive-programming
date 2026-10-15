/**
 * Author: Alan Smith
 * Description: Binary search on a sorted vector v. lower\_bound and upper\_bound return v.end() if there is
 *  no such element (then the index is v.size()), so check before using *it.
 *  x occurs $j - i$ times, the last element $< x$ is at $i - 1$ and the last $\le x$ at $j - 1$.
 *  partition\_point returns the first element for which the condition is false;
 *  the condition must be true on a prefix of v and false after it.
 *  For a vector sorted in descending order, pass greater().
 * Time: O(\log n)
 */
sort(all(v));
auto it = lower_bound(all(v), x);  // first >= x
auto it2 = upper_bound(all(v), x); // first > x
if (it != v.end() && *it == x) {}  // x is at it - v.begin()
if (it2 != v.end()) {}             // smallest > x is *it2
auto i = it - v.begin(), j = it2 - v.begin();
bool found = binary_search(all(v), x);
auto k = partition_point(all(vp),  // first p.first >= x
	[&](auto& p) { return p.first < x; }) - vp.begin();
auto i2 = lower_bound(all(desc), x, greater()) - desc.begin();
