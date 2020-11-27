#include <iostream>
#include <vector>

using namespace std;

// using namespace std;
//
// std::vector<int> tablero;
// std::vector<bool> diag1;
// std::vector<bool> diag2;
//
// int ans;
//
// void comb(int l, int r, int k, int n) {
// 	if (k == 0) {
// 		ans++;
// 		return;
// 	}
// 	for (int i = l; i < r; i++) {
// 		int fila = i / n;
// 		int columna = i % n;
// 		if (!diag1[fila + columna] && !diag2[fila - columna + n - 1]) {
// 			diag1[fila + columna] = true;
// 			diag2[fila - columna + n - 1] = true;
// 			tablero[i] = 1;
// 			comb(i + 1, r + 1, k - 1, n);
// 			tablero[i] = 0;
// 			diag1[fila + columna] = false;
// 			diag2[fila - columna + n - 1] = false;
// 		}
// 	}
// }
//
// void comb(vector<int>& tablero, int n, int k) {
// 	// if (k == 0) {
// 	// 	ans++;
// 	// 	return;
// 	// }
// 	if (k > 2*n - 1) {
// 		return;
// 	}
// 	comb(0, n*n - k + 1, k, n);
// }
//
// int main(int argc, char const *argv[]) {
// 	int n, k;
// 	for (cin >> n >> k; n != 0 || k != 0; cin >> n >> k) {
// 		tablero = vector<int>(n*n, 0);
// 		diag1 = vector<bool>(2*n - 1, false);
// 		diag2 = vector<bool>(2*n - 1, false);
// 		comb(tablero, n, k);
// 		cout << ans << endl;
// 		ans = 0;
// 	}
// 	return 0;
// }


int main() {
	vector<vector<int>> solucion_precomputada = {
		{},
		{1, 1},
		{1, 4, 4, 0, 0},
		{1, 9, 26, 26, 8, 0, 0, 0, 0, 0},
		{1, 16, 92, 232, 260, 112, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{1, 25, 240, 1124, 2728, 3368, 1960, 440, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{1, 36, 520, 3896, 16428, 39680, 53744, 38368, 12944, 1600, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{1, 49, 994, 10894, 70792, 282248, 692320, 1022320, 867328, 389312, 81184, 5792, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{1, 64, 1736, 26192, 242856, 1444928, 5599888, 14082528, 22522960, 22057472, 12448832, 3672448, 489536, 20224, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};
	int n, k;
	for (cin >> n >> k; n != 0 || k != 0; cin >> n >> k) {
		cout << solucion_precomputada[n][k] << endl;
	}
	return 0;
}
