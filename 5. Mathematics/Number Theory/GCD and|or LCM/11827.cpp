#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	string line;
	getline(cin, line);
	for (size_t i = 0; i < n; i++) {
		getline(cin, line);
		stringstream ss(line);
		int x;
		vector<int> v;
		while (ss >> x) {
			v.push_back(x);
		}
		int ans = -1;
		for (int i = 0; i+1 < v.size(); i++) {
			for (int j = i+1; j < v.size(); j++) {
				ans = max(ans, gcd(v[i], v[j]));
			}
		}
		cout << ans << endl;
	}
	return 0;
}
