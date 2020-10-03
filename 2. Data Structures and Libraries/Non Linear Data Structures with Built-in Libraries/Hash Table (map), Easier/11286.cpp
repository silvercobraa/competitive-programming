// César Bolívar Severino
// resuelto propio
#include <iostream>
#include <set>
#include <map>

using namespace std;

int main(int argc, char const* argv[])
{
	int n;
	cin >> n;
	while (n != 0) {
		map<set<int>, int> m;
		int result = 0;
		int max_popularity = 0;
		for (int i = 0; i < n; i++) {
			set<int> s;
			for (int j = 0; j < 5; j++) {
				int x;
				cin >> x;
				s.insert(x);
				// cout << x << ' ';
			}
			m[s]++;
			// result = max(result, m[s]);
			if (m[s] > max_popularity) {
				max_popularity = m[s];
				result = m[s];
			}
			else if (m[s] == max_popularity) {
				result += m[s];
			}
			// cout << endl;
		}
		// for (auto p : m) {
		// 	cout << p.second << ':';
		// 	for (auto f : p.first) {
		// 		cout << ' ' << f;
		// 	}
		// 	cout << endl;
		//
		// }
		cout << result << endl;
		cin >> n;
	}
	return 0;
}
