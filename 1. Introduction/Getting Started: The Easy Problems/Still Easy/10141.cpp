#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
	int n, p;
	int cas = 1;
	for (cin >> n >> p; n != 0 or p != 0; cin >> n >> p, cas++) {
		if (cas != 1) {
			cout << endl;
		}
		vector<string> reqs(n);
		vector<string> props(p);
		getline(cin, reqs[0]);
		for (size_t i = 0; i < n; i++) {
			getline(cin, reqs[i]);
		}
		int best = -1;
		int met = 0;
		double price = 1e9;
		for (size_t i = 0; i < p; i++) {
			getline(cin, props[i]);
			double d;
			int r;
			cin >> d >> r;
			string req;
			getline(cin, req);
			for (size_t i = 0; i < r; i++) {
				getline(cin, req);
			}
			if (r > met or (r == met and d < price)) {
				best = i;
				met = r;
				price = d;
			}
		}
		cout << "RFP #" << cas << endl;
		cout << props[best] << endl;

	}
	return 0;
}
