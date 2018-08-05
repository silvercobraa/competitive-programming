#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	string ONE = "one";
	string TWO = "two";
	for (size_t i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s.size() == 5) {
			cout << 3 << endl;
		}
		else {
			int one = 0;
			int two = 0;
			for (size_t j = 0; j < 3; j++) {
				one += s[j] != ONE[j];
				two += s[j] != ONE[j];
			}
			if (one <= 1) {
				cout << 1 << endl;
			}
			else {
				cout << 2 << endl;
			}
		}
	}
	return 0;
}
