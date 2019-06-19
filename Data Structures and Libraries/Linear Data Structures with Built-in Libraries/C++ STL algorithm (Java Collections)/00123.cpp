// César Bolívar Severino
// resuelto propio
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

int main(int argc, char const* argv[])
{
	string word;
	set<string> ignored;
	set<string> keyword;
	vector<string> title;
	map<string, set<int>> ocurrence;
	while (true) {
		// cin >> word;
		getline(cin, word);
		if (word == "::") {
			break;
		}
		ignored.insert(word);
	}
	// for (auto k: ignored) {
	// 	cout << k << endl;
	// }
	string line;
	while (getline(cin, line)) {
		for (int i = 0; i < line.size(); i++) {
			line[i] = tolower(line[i]);
		}
		stringstream ss(line);
		string lowercase_keyword;
		while (ss >> lowercase_keyword) {
			// cout << lowercase_keyword << endl;
			if (ignored.find(lowercase_keyword) == ignored.end()) {
				keyword.insert(lowercase_keyword);
				ocurrence[lowercase_keyword].insert(title.size());

			}
		}
		title.push_back(line);
	}
	// for (auto l: title) {
	// 	cout << l << endl;
	// }
	for (auto k: keyword) {
		// cout << k << endl;
		for (auto o: ocurrence[k]) {
			string& t = title[o];
			int here = 0;
			int pos = t.find(k, here);
			// este while esta para capturar todas las ocurrencias de una misma palabra en el titulo
			while (pos != string::npos) {
				// caso de mierda en el que la palabra que busco es prefijo de otra palabra en el titulo
				if (pos + k.size() < t.size() && t[pos + k.size()] != ' ') {
					here = pos + 1;
					pos = t.find(k, here);
					continue;
				}
				for (int i = pos; t[i] != '\0' && t[i] != ' '; i++) {
					t[i] = toupper(t[i]);
				}
				cout << t << endl;
				for (int i = pos; t[i] != '\0' && t[i] != ' '; i++) {
					t[i] = tolower(t[i]);
				}
				here = pos + 1;
				pos = t.find(k, here);
			}
		}
	}
	return 0;
}
