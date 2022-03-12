#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int s;
	cin >> s;
	for (size_t t = 1; t <= s; t++) {
		bool ans = true;
		for (int i = 0; i < 13; i++) {
			int x;
			cin >> x;
			ans &= x != 0;
		}
		if (ans) {
			printf("Set #%d: Yes\n", t);
		}
		else {
			printf("Set #%d: No\n", t);
		}
	}
	return 0;
}
