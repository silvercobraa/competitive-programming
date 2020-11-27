// César Bolívar Severino
// resuelto propio
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

int main(int argc, char const* argv[])
{
	string s;
	for (cin >> s; s != "#"; cin >> s) {
		s.back() = ';';
		// para que esta wea funcione debo construir un map como el de abajo a partir del input de mierda del problema
		// map<char, vector<char>> g = {
		// 	{'A', {'B', 'C', 'D'}},
		// 	{'B', {'A', 'D'}},
		// 	{'D', {'B', 'G'}},
		// 	{'F', {'H'}},
		// 	{'G', {'D', 'E', 'H'}},
		// 	{'E', {'F', 'G', 'H'}},
		// 	{'H', {'E', 'G'}},
		// 	{'C', {'A', 'D'}},
		// };
		map<char, vector<char>> g;
		for (int i = 0; i < s.size(); i++) {
			char key = s[i];
			i++;
			if (s[i] == ';') {
				continue;
			}
			i++;
			for ( ; i < s.size() && s[i] != ';'; i++) {
				g[key].push_back(s[i]);
			}
		}
		// cout << s << endl;
		char M, T;
		int k = 0;
		cin >> M >> T >> k;
		// M = 'A'; T = 'C'; k = 3;
		// for (auto p: g) {
		// 	cout << p.first << ':';
		// 	for (auto q: p.second) {
		// 		cout << q;
		// 	}
		// 	cout << ';';
		// }
		map<char, bool> lit;
		vector<char> result;
		int i = k;
		while (true) {
			// cout << M << endl;
			if (i == 0) {
				if (!lit[T]) {
					result.push_back(T);
					lit[T] = true;
				}
			}
			bool flag = true;
			for (auto c: g[M]) {
				if (c != T && !lit[c]) {
					flag = false;
					T = M;
					M = c;
					break;
				}
			}
			if (flag) {
				// el minotauro está atrapado
				break;
			}
			assert(k != 0);
			i = (i + 1)%k;
		}
		for (auto r: result) {
			cout << r << ' ';
		}
		cout << '/' << M << endl;
	}
	return 0;
}
