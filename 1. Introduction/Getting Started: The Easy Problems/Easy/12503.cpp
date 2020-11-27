#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		int p = 0;
		vector<int> v(n, 0);
		for (size_t i = 0; i < n; i++) {
			string s;
			cin >> s;
			if (s == "LEFT") {
				v[i] = -1;
			}
			else if (s == "RIGHT") {
				v[i] = 1;
			}
			else {
				cin >> s;
				int x;
				cin >> x;
				v[i] = v[x - 1];
			}
			p += v[i];
		}
		cout << p << endl;
	}
	return 0;
}
