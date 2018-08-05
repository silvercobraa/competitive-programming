#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int a, b, c, d;
	for (cin>>a>>b>>c>>d; a!=0 or b != 0 or c != 0 or d != 0; cin>>a>>b>>c>>d) {
		int diagi1 = a + b;
		int diagi2 = a - b;
		int diagf1 = c + d;
		int diagf2 = c - d;
		if (a == c and b == d) {
			cout << 0 << endl;
		}
		else if (a == c or b == d or diagi1 == diagf1 or diagi2 == diagf2) {
			cout << 1 << endl;
		}
		else {
			cout << 2 << endl;
		}
	}
	return 0;
}
