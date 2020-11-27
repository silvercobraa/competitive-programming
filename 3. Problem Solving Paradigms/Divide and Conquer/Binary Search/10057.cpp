// César Bolívar Severino
// resuelto propio
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const* argv[])
{
	int n;
	while (cin >> n) {
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		// la mediana minimiza suma de las distancias
		int mid = (v.size() - 1)/2;
		int minimum_A = v[mid];
		int another_A;
		int diff = 0;
		auto lb1 = lower_bound(v.begin(), v.end(), minimum_A);
		auto ub1 = upper_bound(v.begin(), v.end(), minimum_A);
		int how_many_in_input = distance(lb1, ub1);
		// si hay una cantidad par de elementos hay 2 medianas
		if (v.size() % 2 == 0) {
			another_A = v[mid + 1];
			// verificamos que sean distintas
			if (another_A != minimum_A) {
				auto lb2 = lower_bound(v.begin(), v.end(), another_A);
				auto ub2 = upper_bound(v.begin(), v.end(), another_A);
				how_many_in_input += distance(lb2, ub2);
			}
			// todos los elementos entre las 2 medianas satisfacen que la suma de las distancias es mínima
			diff = another_A - minimum_A;
		}
		cout << minimum_A << ' ' << how_many_in_input << ' ' << diff + 1 << endl;
	}
	return 0;
}
