// Algo muy raro sucedió acá. en el último if, me equivoque en poner "des",
// lo puse como "dec". La condición "asc or dec" siempre evaluaba verdadera,
// y pensé que era por que el compilador erroneamente estaba suponiendola verdadera
// (ya que ambas se inicializaban a true). Resultó ser que std::dec es un flag
// para formatear la salida de los streams (y ni gcc ni clang se quejaron al respecto).
// Moraleja: no usar nombres weones para las variables.
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	cout << "Lumberjacks:" << endl;
	for (int t = 0; t < T; t++) {
		int x;
		cin >> x;
		bool asc = true;
		bool des = true;
		for (size_t i = 1; i < 10; i++) {
			int aux;
			cin >> aux;
			if (aux > x) {
				des = false;
				// cout << des << endl;
			}
			if (aux < x) {
				asc = false;
				// cout << asc << endl;
			}
			x = aux;
		}
		// cout << asc << " " << des << " " << (asc or des) << endl;
		if (asc or des) {
			cout << "Ordered" << endl;
		}
		else {
			cout << "Unordered" << endl;
		}
	}
	return 0;
}
