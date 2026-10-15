/**
 * Author: Alan Smith
 * Description: Steady state of a Markov chain, where P.d[i][j] $= \Pr(j \to i)$.
 *  stationary finds $\pi$ exactly if it is unique (one closed class, e.g. irreducible; periodic is fine),
 *  and returns false otherwise. It solves $(P - I)\pi = 0$.
 *  longRun works for any chain and returns the long-run distribution from p0:
 *  the average over time if periodic, and depending on p0 if there are several closed classes.
 *  It computes $((P + I)/2)^{2^{60}}$, which is aperiodic with the same stationary distributions,
 *  and rescales each column to sum 1 against round-off.
 * Time: O(S^3)
 */
#include "../data-structures/Matrix.h"
#include "../numerical/SolveLinear.h"

const int S = 3; // number of states
typedef array<double, S> V;
V longRun(Matrix<double, S> P, V p0) {
	rep(i,0,S) rep(j,0,S) P.d[i][j] = (P.d[i][j] + (i == j)) / 2;
	rep(k,0,60) {
		P = P * P;
		rep(j,0,S) {
			double t = 0;
			rep(i,0,S) t += P.d[i][j];
			rep(i,0,S) P.d[i][j] /= t;
		}
	}
	return P * p0;
}
bool stationary(Matrix<double, S> P, V& pi) {
	vector<vd> A(S, vd(S)); vd b(S), x(S);
	rep(i,0,S) rep(j,0,S) A[i][j] = P.d[i][j] - (i == j);
	rep(j,0,S) A[S-1][j] = 1; // last row: sum(pi) = 1
	b[S-1] = 1;
	if (solveLinear(A, b, x) < S) return false;
	rep(i,0,S) pi[i] = x[i];
	return true;
}
