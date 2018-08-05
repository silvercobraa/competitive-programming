#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		int x = 0;
		int high = 0;
		int low = 0;
		cin >> x;
		for (size_t i = 1; i < n; i++) {
			int aux;
			cin >> aux;
			if (aux > x) {
				high++;
			}
			else if (aux < x) {
				low++;
			}
			x = aux;
		}
		cout << "Case " << t + 1 << ": " << high << " " << low << endl;
	}
	return 0;
}
