// César Bolívar Severino
// resuelto propio
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char const* argv[])
{
	int k;
	string s;
	while (cin >> k) {
		map<string, int> m;
		cin >> s;
		for (size_t i = 0; i <= s.size() - k; i++) {
			string s2 = s.substr(i, k);
			m[s2]++;
		}
		string password = s.substr(0, k);
		int max = 0;
		for (auto p: m) {
			if (p.second > max) {
				password = p.first;
				max = p.second;
			}
		}
		cout << password << endl;
	}
	return 0;
}
