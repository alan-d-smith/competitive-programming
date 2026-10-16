/**
 * Author: Lukas Polacek
 * Date: 2009-10-26
 * License: CC0
 * Source: folklore
 * Description: Disjoint-set data structure (union-find). Keeps track of groups (e.g. connected components) as they are merged.
 * UF uf(n) starts with n elements, numbered 0 to n - 1, each in a group of its own
 * (for input numbered 1 to n, subtract 1 from each, or use UF uf(n + 1)).
 * join(a, b) merges the groups of a and b, and returns false if they were already the same group,
 * so the number of groups is n minus the number of joins that returned true.
 * sameSet(a, b) says whether a and b are in the same group, size(x) is the size of x's group,
 * and find(x) is its representative. Internally, e[x] is the parent of x, or minus the group's size
 * if x is the representative.
 * Usage: UF uf(5); // 0 1 2 3 4, each alone
 * uf.join(0, 1); // groups {0,1} {2} {3} {4}
 * uf.join(3, 4); // groups {0,1} {2} {3,4}
 * uf.sameSet(1, 0); // true
 * uf.sameSet(1, 3); // false
 * uf.size(4); // 2
 * uf.join(1, 0); // false, already together
 * Time: $O(\alpha(N))$, which is basically constant
 */
#pragma once

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};
