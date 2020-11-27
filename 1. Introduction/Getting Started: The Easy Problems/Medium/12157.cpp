#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		int mile = 0;
		int juice = 0;
		for (size_t i = 0; i < n; i++) {
			int x;
			cin >> x;
			mile += 10*((x / 30) + 1);
			juice += 15*((x / 60) + 1);
		}
		cout << "Case " << t + 1 << ": ";
		if (mile < juice) {
			cout << "Mile " << mile << endl;
		}
		else if (juice < mile) {
			cout << "Juice " << juice << endl;
		}
		else {
			cout << "Mile Juice " << mile << endl;
		}
	}
	return 0;
}
