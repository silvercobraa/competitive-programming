#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	for (cin >> n; n != 0; cin >> n) {
		vector<int> visited(10000, false);
		int k = n;
		int count = 0;
		do {
			visited[k] = true;
			k = (k*k / 100) % 10000;
			count++;
			// cout << k << " ";
		} while (not visited[k]);
		cout << count << endl;
	}
	return 0;
}
