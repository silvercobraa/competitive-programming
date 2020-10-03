#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	string s;
	getline(cin, s);
	for (size_t t = 0; t < n; t++) {
		getline(cin, s);
		string ss;
		for (auto c: s) {
			if ('a' <= c and c <= 'z') {
				ss.push_back(c);
			}
		}
		int size = 0;
		for (size = 0; size*size < ss.size(); size++) {

		}
		cout << "Case #" << t + 1 << ":" << endl;
		// cout << ss << " " << ss.size() << endl;
		if (size*size == ss.size()) {
			vector<vector<char>> sq = vector<vector<char>>(size, vector<char>(size));
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					sq[i][j] = ss[i*size + j];
				}
			}
			bool magic = true;
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					if (sq[i][j] != sq[j][i]
						or sq[i][j] != sq[size - i - 1][size - j - 1]
						or sq[i][j] != sq[size - j - 1][size - i - 1]
					) {
						magic = false;
						break;
					}
				}
				if (! magic) {
					break;
				}
			}
			if (magic) {
				cout << size << endl;
			}
			else {
				cout << "No magic :(" << endl;
			}
		}
		else {
			cout << "No magic :(" << endl;
		}
	}
	return 0;
}
