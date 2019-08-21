#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
	string s;
	vector<bool> sieve(52*20 + 1, true);
	for (int i = 2; i < sieve.size(); i++) {
		if (sieve[i]) {
			for (int j = 2*i; j < sieve.size(); j += i) {
				sieve[j] = false;
			}
		}
	}
	while (cin >> s) {
		int sum = 0;
		for (auto c: s) {
			if ('a' <= c and c <= 'z') {
				sum += c - 'a' + 1;
			}
			else if ('A' <= c and c <= 'Z') {
				sum += c - 'A' + 27;
			}
		}
		if (sieve[sum]) {
			puts("It is a prime word.");
		}
		else {
			puts("It is not a prime word.");
		}
	}
	return 0;
}
