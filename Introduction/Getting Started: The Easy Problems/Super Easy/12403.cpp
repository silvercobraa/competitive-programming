#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	int amount = 0;
	for (size_t i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "donate") {
			int x;
			cin >> x;
			amount += x;
		}
		else {
			cout << amount << endl;
		}
	}
	return 0;
}
