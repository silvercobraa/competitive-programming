#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
	string s;
	for (cin >> s; s != "END"; cin >> s) {
		int i = 0;
		for (i = 1; s != to_string(s.size()); i++) {
			s = to_string(s.size());
		}
		cout << i << endl;
	}
	return 0;
}
