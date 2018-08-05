#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	string s;
	getline(cin, s);
	for (size_t i = 0; i < n; i++) {
		getline(cin, s);
		stringstream ss(s);
		string sss;
		int m = 0;
		int f = 0;
		int c = 0;
		for ( ; ss >> sss; c++) {
			if (sss[0] == 'M') {
				m += 1;
			}
			else {
				f += 1;
			}
			if (sss[1] == 'M') {
				m += 1;
			}
			else {
				f += 1;
			}
		}
		if (m != f or c == 1) {
			cout << "NO ";
		}
		cout << "LOOP" << endl;
	}
	return 0;
}
