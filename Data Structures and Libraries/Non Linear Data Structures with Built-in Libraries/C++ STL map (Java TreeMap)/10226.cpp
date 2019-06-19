// César Bolívar Severino
// resuelto propio
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char const* argv[])
{
	int n;
	string s;
	cin >> n;
	getline(cin, s);
	getline(cin, s);
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		map<string, int> m;
		int total_trees = 0;
		while (s != "") {
			m[s] += 1;
			total_trees++;
			getline(cin, s);
		}
		for (auto t: m) {
			cout << t.first << ' ';
			printf("%.4f\n", 100.0*t.second / total_trees);
		}
		if (i != n - 1) cout << endl;
	}
	return 0;
}
