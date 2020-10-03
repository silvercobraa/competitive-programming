#include <iostream>
#include <vector>

using namespace std;

vector<bool> sieve(31624, true);
vector<int> primes;


long long euler_phi(long long n) {
	// cout << "procesando " << n << endl;
	long long ans = n;
	for (auto p: primes) {
		// if (2*p > n) {
		// 	break;
		// }
		if (n % p == 0) {
			// cout << "primo " << p << endl;
			// cout << "restando " << ans/p << endl;
			ans -= ans / p;
		}
	}
	return ans;
}


int phi(int n) {
	int result = n;
	for (int i = 2; i * i <= n; i++) {
		if(n % i == 0) {
			while(n % i == 0)
				n /= i;
			result -= result / i;
		}
	}
	if(n > 1)
		result -= result / n;
	return result;
}


int main(int argc, char const *argv[]) {
	int n;
	sieve[0] = false;
	sieve[1] = false;
	for (int p = 2; p < sieve.size(); p++) {
		if (sieve[p] == true) {
			primes.push_back(p);
			// cout << p << endl;
			for (int c = 2*p; c < sieve.size(); c += p) {
				sieve[c] = false;
			}
		}
	}
	for (cin >> n; n != 0; cin >> n) {
		// long long ans = euler_phi(n);
		long long ans = phi(n);
		cout << ans << endl;
	}
	return 0;
}
