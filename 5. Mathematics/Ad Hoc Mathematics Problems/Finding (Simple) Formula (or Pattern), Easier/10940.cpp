#include <iostream>

using namespace std;

// el patrón es de 2 en 2, hasta llegar a una potencia de 2, ahi se resetea a 2.
// 2 2 4 2 4 6 8 2 4 6 8 10 12 14 16 2 4 6 8 10 12 14 16 18 20 22 24 26 28 30 32 2...
int main(int argc, char const *argv[]) {
	int n;
	for (cin >> n; n != 0; cin >> n) {
		// al restar 1 en la formula de abajo corrijo los casos potencia de 2, pero me piteo el caso n == 1
		if (n == 1) {
			cout << 1 << endl;
			continue;
		}
		int exp = 0;
		for (int tmp = n-1; tmp > 0; tmp /= 2) {
			exp++;
		}
		// la mayor potencia de 2 menor que n
		int power = 1 << exp-1;
		// cout << n << " " << exp << " " << (1 << exp) << endl;
		// if (power == n) {
		// 	// no restar, para que no de cero. Debe dar el mismo n en este caso.
		// 	cout << n << endl;
		// }
		// cout << n << ": " << 2*(n - power) << endl;
		cout << 2*(n - power) << endl;
	}
	return 0;
}
