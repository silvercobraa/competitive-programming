#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long Int;

bool check(vector<Int>& v, Int d) {
	for (size_t i = 0; i < v.size(); i++) {
		if (v[i] == d) {
			continue;
		}
		for (size_t j = i+1; j < v.size(); j++) {
			Int diff = d - v[i] - v[j];
			if (diff == v[i] or diff == v[j] or diff == d or v[j] == d) {
				continue;
			}
			// esto es necesario porque si no podemos repetir un elemento
			bool left = binary_search(v.begin(), v.begin()+i, diff);
			bool mid = binary_search(v.begin()+i+1, v.begin()+j, diff);
			bool right = binary_search(v.begin()+j+1, v.end(), diff);
			if (left or mid or right) {
				// printf("%d + %d + %d = %d\n", v[i], v[j], diff, d);
				return true;
			}
		}
	}
	return false;
}

int main(int argc, char const *argv[]) {
	int n;
	for (cin >> n; n != 0; cin >> n) {
		std::vector<Int> v(n);
		for (size_t i = 0; i < n; i++) {
			cin >> v[i];
		}
		if (n <= 3) {
			puts("no solution");
			continue;
		}
		sort(v.begin(), v.end());
		bool solution = false;
		for (auto it=v.rbegin(); it != v.rend(); ++it) {
			if (check(v, *it)) {
				cout << *it << endl;
				solution = true;
				break;
			}
		}
		if (not solution) {
			puts("no solution");
		}
	}
	return 0;
}
