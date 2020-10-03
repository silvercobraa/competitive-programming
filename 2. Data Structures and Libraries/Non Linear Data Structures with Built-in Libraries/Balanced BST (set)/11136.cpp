// César Bolívar Severino
// resuelto propio
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(int argc, char const* argv[])
{
	// habia que usar long, no bastaba con int
	long n;
	cin >> n;
	for ( ; n != 0; cin >> n) {
		multiset<long> ms;
		long cost = 0;
		for (long i = 0; i < n; i++) {
			long k;
			cin >> k;
			for (long j = 0; j < k; j++) {
				long x;
				cin >> x;
				ms.insert(x);
			}
			long minimum = *(ms.begin());
			long maximum = *(ms.rbegin());
			cost += maximum - minimum;
			// ms.erase(ms.begin()); // debo pasarle el iterador y no la clave, de lo contrario me borra todos los elementos con la misma clave
			ms.erase(ms.find(minimum));
			// ms.erase(maximum);
			// ms.erase(ms.rbegin()); // C++ de mierda no me deja hacer lo mismo que hice arriba porque esta wea es un iterador reverso, asi que debo hacer la estupidez de aca abajo
			ms.erase(ms.find(maximum));
		}
		cout << cost << endl;
	}
	return 0;
}
