#include <iostream>
#include <string>

using namespace std;

bool pal(int M) {
	int h = M / 60;
	int m = M % 60;
	if (h == 0) {
		if (m < 10) {
			return true;
		}
		else {
			return m / 10 == m % 10;
		}
	}
	else if (h < 10) {
		return h == m % 10;
	}
	else {
		return h / 10 == m % 10 and h % 10 == m / 10;
	}
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	for (size_t i = 0; i < n; i++) {
		string t;
		cin >> t;
		int h = 10*int(t[0] - '0') + int(t[1] - '0');
		int m = 10*int(t[3] - '0') + int(t[4] - '0');
		int M = 60*h + m;
		do {
			M = (M + 1) % 1440;
		} while (!pal(M));
		printf("%02d:%02d\n", M / 60, M % 60);
	}
	return 0;
}
