#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

bool test(vector<string>& v, int X, int Y, int p) {
	int x = p;
	int y = 0;
	// cout << X << " " << Y << endl;
	for (int i = 0; i < v.size(); i++) {
		stringstream ss(v[i]);
		string word;
		while (ss >> word) {
			// si es la primera palabra
			if (y == 0) {
				// si la palabra NO cabe en la linea
				if (p*word.size() > Y) {
					return false;
				}
				// si la palabra cabe en la linea
				else {
					y = p*word.size();
				}
			}
			// si no es la primera palabra
			else {
				// si cabe en la linea (+1 por el espacio)
				if (y + p*(1+word.size()) <= Y) {
					y += p*(1+word.size());
				}
				else {
					y = 0;
					x += p;
					if (p*word.size() > Y) {
						return false;
					}
					// si la palabra cabe en la linea
					else {
						y = p*word.size();
					}
				}
			}
			// cout << word << " " << x << " " << y << endl;
		}
		if (i + 1 != v.size()) {
			x += p;
			y = 0;
		}
	}
	return x <= X;
}

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		string line;
		getline(cin, line);
		vector<string> lines;
		for (int i = 0; i < n; i++) {
			getline(cin, line);
			lines.push_back(line);
		}
		int X, Y;
		cin >> X >> Y;
		int ans = 0;
		for (int p = 28; p >= 8; p--) {
			bool ret = test(lines, Y, X, p);
			if (ret) {
				ans = p;
				break;
			}
		}
		if (ans == 0) {
			cout << "No solution" << endl;
		}
		else {
			cout << ans << endl;
		}
	}
	return 0;
}
