#include <iostream>
#include <vector>

using namespace std;

bool simulate(vector<int>& v, int k) {
	int pos = 0;
	for (auto x: v) {
		int diff = x - pos;
		if (diff > k) {
			// cout << endl;
			return false;
		}
		else if (diff == k) {
			if (k > 0) {
				k--;
			}
			else {
				// cout << endl;
				return false;
			}
		}
		// cout << k << " ";
		pos = x;
	}
	// cout << endl;
	return true;
}

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (size_t t = 0; t < T; t++) {
		int n;
		cin >> n;
		vector<int> v(n);
		for (size_t i = 0; i < n; i++) {
			cin >> v[i];
		}
		// LOWER BOUND: a diferencia de la busqueda binaria, donde el cursor se gana
		// en la mitad y se mueve a izquierda o derecha dependiendo del resultado de
		// la posición de cursor, en lower_bound siempre nos movemos a la derecha.
		// lo que va cambiando es el tamaño del salto, que se hace exponencialmente
		// mas chico en cada salto
		// pos es la posicion del cursor
		int pos = 0;
		// dist es la distancia del intervalo semiabierto que estamos procesando [pos, pos+dist)
		int dist = v[v.size()-1] + 1;
		while (dist > 0) {
			// revisamos la "mitad"
			int mid = pos + dist/2;
			// si cumple la propiedad no puedo saltar todavia, poues podria haber
			// algun valor anterior que tambien cumpla la propiedad. Para hallarlo,
			// se divide en 2 el salto, para la siguiente iteración.
			if (simulate(v, mid)) {
				dist /= 2;
			}
			// si no cumple la propiedad, ya sabemos que el valor de la mitad y
			// todo lo de la izquierda no nos sirve. Saltamos a la posicion
			// siguiente a la mitad, y acotamos el rango acordemente
			else {
				pos = mid+1;
				dist -= dist/2 + 1;
			}
		}
		printf("Case %d: %d\n", t+1, pos);
	}
	return 0;
}
