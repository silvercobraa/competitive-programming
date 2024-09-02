#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int a, b, c;
	string s = "*CBAABC*";
	while (cin >> a >> b >> c) {
		cout << s[4*a + 2*b + c] << endl;
	}
	return 0;
}
