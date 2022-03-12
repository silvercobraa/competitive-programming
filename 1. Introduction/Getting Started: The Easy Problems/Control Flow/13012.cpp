#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int tea;
	while (cin >> tea) {
		int ans = 0;
		for (int i = 0; i < 5; i++) {
			int guess;
			cin >> guess;
			ans += guess == tea;
		}
		cout << ans << endl;
	}
	return 0;
}
