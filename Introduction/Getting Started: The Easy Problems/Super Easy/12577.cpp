#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	string s;
	int cas = 1;
	for (cin >> s; s != "*"; cin >> s, cas++) {
		cout << "Case " << cas << ": ";
		if (s == "Hajj") {
			cout << "Hajj-e-Akbar" << endl;
		}
		else {
			cout << "Hajj-e-Asghar" << endl;
		}
	}
	return 0;
}
