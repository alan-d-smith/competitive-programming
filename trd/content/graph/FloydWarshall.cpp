/**
 * Author: Alan Smith
 * Source: the clamping and the -INF pass follow KACTL's FloydWarshall.h (Simon Lindholm, CC0)
 * Description: Shortest distances between all pairs of nodes, for n up to about 500.
 *  Before calling, set every d[i][j] = INF and d[i][i] = 0, then d[a][b] = min(d[a][b], w) for each edge
 *  (so parallel edges and negative self-loops count). Afterwards d[i][j] is the shortest distance from i to j, or INF if
 *  unreachable. The loop over k must be the outermost. Negative weights are fine: there is a
 *  negative cycle iff some d[k][k] < 0, and d[i][j] = -INF means the distance is really $-\infty$
 *  (a path from i to j can go round a negative cycle forever).
 * Time: O(n^3)
 */
const int MAXV = 505;
const ll INF = 1e18;
ll d[MAXV][MAXV];
void floydWarshall(int n) {
	rep(k,0,n) rep(i,0,n) rep(j,0,n)
		if (d[i][k] < INF && d[k][j] < INF)
			d[i][j] = max(-INF, min(d[i][j], d[i][k] + d[k][j]));
	rep(k,0,n) if (d[k][k] < 0) rep(i,0,n) rep(j,0,n)
		if (d[i][k] < INF && d[k][j] < INF) d[i][j] = -INF;
}
