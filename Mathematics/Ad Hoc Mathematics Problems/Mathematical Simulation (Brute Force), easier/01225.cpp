#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		vector<int> v(10, 0);
		for (int i = 1; i <= n; i++) {
			for (int j = i; j > 0; j /= 10) {
				v[j%10]++;
			}
		}
		cout << v[0];
		for (int i = 1; i < 10; i++) {
			cout << " " << v[i];
		}
		cout << endl;
	}
	return 0;
}
