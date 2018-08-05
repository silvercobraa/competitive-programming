// PERO CONCHETUMARE WEON, PORQUE NUNCA PIENSO EN TODOS LOS CASOS POSIBLES?
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int C;
	cin >> C;
	for (int cas = 0; cas < C; cas++) {
		int T, N;
		cin >> T >> N;
		for (int t = 0; t < T; t++) {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			int diagi1 = a + b;
			int diagi2 = a - b + N;
			int diagf1 = c + d;
			int diagf2 = c - d + N;
			// quien hubiera pensado que podian caer en la misma posicion?
			if (a == c and b == d) {
				cout << 0 << endl;
			}
			else if (diagi1 % 2 != diagf1 % 2) {
				cout << "no move" << endl;
 			}
			else if (diagi1 == diagf1 or diagi2 == diagf2) {
				cout << 1 << endl;
			}
			else {
				cout << 2 << endl;
			}
		}
	}
	return 0;
}
