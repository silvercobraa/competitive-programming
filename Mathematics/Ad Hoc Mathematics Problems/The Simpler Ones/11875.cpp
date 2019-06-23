#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		int half = n/2;
		int x;
		for (int i = 0; i < half; i++) {
			cin >> x;
		}
		cin >> x;
		printf("Case %d: %d\n", t+1, x);
		for (int i = 0; i < half; i++) {
			cin >> x;
		}
	}
	return 0;
}
