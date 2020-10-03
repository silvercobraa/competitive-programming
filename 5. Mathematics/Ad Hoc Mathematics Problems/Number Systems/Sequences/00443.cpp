#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void search(vector<long long>& humble, vector<long long>& p, vector<int>& ans, long long prod, int k) {
	for (int i = k; i < p.size(); i++) {
		int x = p[i];
		if (x*prod <= 2000000000LL) {
			ans.push_back(x);
			search(humble, p, ans, x*prod, i);
			ans.pop_back();
		}
	}
	// for (auto x: ans) {
	// 	cout << x << " ";
	// }
	// cout << prod << endl;
	humble.push_back(prod);
}

int main(int argc, char const *argv[]) {
	vector<long long> p = {2, 3, 5, 7};
	vector<int> ans;
	vector<long long> v;
	// el elemento mas grande es 2'000'000'000 = 2^10 * 5^9, basta con 10 de cada uno
	search(v, p, ans, 1, 0);
	// cout << v.size() << endl;

	sort(v.begin(), v.end());
	// for (auto x: v) {
	// 	cout << x << endl;
	// }
	int n;
	for (cin >> n; n != 0; cin >> n) {
		printf("The %d", n);
		if (n % 10 == 1 and not (n % 100 == 11)) {
			printf("st");
		}
		else if (n % 10 == 2 and not (n % 100 == 12)) {
			printf("nd");
		}
		else if (n % 10 == 3 and not (n % 100 == 13)) {
			printf("rd");
		}
		else {
			printf("th");
		}
		printf(" humble number is %d.\n", v[n-1]);
	}
	return 0;
}
