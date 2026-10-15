/**
 * Author: Lukas Polacek
 * Date: 2009-10-26
 * License: CC0
 * Source: folklore
 * Description: Disjoint-set data structure. Keeps track of groups (e.g. connected components) as they are merged.
 * join(a, b) merges the groups of a and b, and returns false if they were already the same group.
 * find(x) returns the representative of x's group, size(x) the group's size.
 * Internally, e[x] is the parent of x, or minus the group's size if x is the representative.
 * Usage: UF uf(n); uf.join(a, b); uf.sameSet(a, b);
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
