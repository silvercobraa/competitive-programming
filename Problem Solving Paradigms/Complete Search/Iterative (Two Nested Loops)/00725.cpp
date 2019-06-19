#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>

using namespace std;

map<int, set<pair<int, int>>> m;

void swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
	return;
}

void perm(int v[], int k, int n) {
	if (k == n) {
		int num = 10000*v[0] + 1000*v[1] + 100*v[2] + 10*v[3] + v[4];
		int den = 10000*v[5] + 1000*v[6] + 100*v[7] + 10*v[8] + v[9];
		if (num % den == 0) {
			// printf("%d %d\n", num, den);
			m[num/den].insert({num, den});
		}
	}
	for (int i = k; i < n; i++) {
		swap(&v[k], &v[i]);
		perm(v, k + 1, n);
		swap(&v[k], &v[i]);
	}
	return;
}

void print(int n) {
	if (n < 10) {
		cout << "0000" << n;
	}
	else if (n < 100) {
		cout << "000" << n;
	}
	else if (n < 1000) {
		cout << "00" << n;
	}
	else if (n < 10000) {
		cout << "0" << n;
	}
	else {

		cout << n;
	}
}

int main(int argc, char const* argv[])
{
	// vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	perm(v, 0, 10);
	int n;
	int count = 0;
	for (cin >> n; n != 0; cin >> n, count++) {
		if (count != 0) {
			cout << endl;
		}
		if (m.find(n) == m.end()) {
			cout << "There are no solutions for " << n << ".\n";
		}
		else {
			for (auto p: m[n]) {
				print(p.first);
				cout << " / ";
				print(p.second);
				cout << " = ";
				cout << n << endl;
			}
		}
	}
	return 0;
}
