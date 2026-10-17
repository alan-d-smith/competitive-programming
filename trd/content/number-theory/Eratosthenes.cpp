/**
 * Author: Alan Smith
 * Description: Sieve of Eratosthenes. Call sieve() once; then isPrime[x] says whether $x \le$ MAXP is prime, and
 *  primes lists the primes in increasing order. There are 664\,579 primes below $10^7$.
 * Time: O(N \log \log N)
 */
const int MAXP = 1e7;
vector<bool> isPrime(MAXP + 1, true);
vi primes;
void sieve() {
	isPrime[0] = isPrime[1] = false;
	rep(i,2,MAXP+1) if (isPrime[i]) {
		primes.push_back(i);
		for (ll j = (ll)i * i; j <= MAXP; j += i)
			isPrime[j] = false;
	}
}
