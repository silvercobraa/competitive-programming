// porque me enredo tanto con este tipo de problemas?
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	int t = 1;
	for ( ; cin >> n; t++) {
		if (t != 1) {
			cout << endl;
		}
		vector<string> name(n);
		map<string, int> money;
		map<string, int> give;
		map<string, int> take;
		for (size_t i = 0; i < n; i++) {
			cin >> name[i];
		}
		for (size_t i = 0; i < n; i++) {
			string s;
			int amount;
			int nn;
			cin >> s >> amount >> nn;
			money[s] = amount;
			for (size_t j = 0; j < nn; j++) {
				string ss;
				cin >> ss;
				give[s] += amount / nn;
				take[ss] += amount / nn;
			}
		}
		for (auto nam : name) {
			// cout << nam << " " << money[nam] + take[nam] - give[nam] << endl;
			cout << nam << " " << take[nam] - give[nam] << endl;
		}
	}
	return 0;
}
