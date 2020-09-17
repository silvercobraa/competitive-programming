#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
	vector<unsigned long long> v;
	unsigned long long diags = 0;
	for (unsigned long long n = 3; diags <= 1000000000000000LL; n++) {
		diags = n * (n - 3) / 2;
		v.push_back(diags);
	}
	long long n;
	int case_ = 1;
	for (cin >> n; n != 0; cin >> n) {
		cout << "Case " << case_ << ": ";
		auto lb = lower_bound(v.begin(), v.end(), n);
		int dist = distance(v.begin(), lb);
		cout << dist+3 << endl;
		case_++;
	}
	return 0;
}
