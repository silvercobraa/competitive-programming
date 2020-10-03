#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
	vector<int> v;
	for (int i = 1, count = 0; count < 10000000; i++) {
		count += i;
		v.push_back(count);
	}
	int n;
	// for (int i = 0; i < 10; i++) {
	// 	cout << v[i] << " ";
	// }
	// cout << endl;
	while (cin >> n) {
		auto ans = upper_bound(v.begin(), v.end(), n-1);
		int dist = distance(v.begin(), ans);
		int delta = *ans - n;
		// si la diagonal es de indice PAR, recorremos de arriba hacia abajo
		if (dist % 2 == 0) {
			int num = delta+1;
			int den = dist - delta+1;
			cout << "TERM " << n << " IS " << num << "/" << den << endl;
		}
		// si la diagonal es de indice IMPAR, recorremos de abajo hacia arriba
		else {
			int num = dist - delta+1;
			int den = delta+1;
			cout << "TERM " << n << " IS " << num << "/" << den << endl;

		}
		// cout << n << " " << *ans << " " << delta << endl;
	}
	return 0;
}
