#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector<vector<char>> page(60, vector<char>(60, '.'));

map<char, vector<string>> m = {
	{'A', {
		" ***  ",
		"*   * ",
		"***** ",
		"*   * ",
		"*   * ",
	}, },
	{'B', {
		"****  ",
		"*   * ",
		"****  ",
		"*   * ",
		"****  ",
	}, },
	{'C', {
		" **** ",
		"*   * ",
		"*     ",
		"*     ",
		" **** ",
	}, },
	{'D', {
		"****  ",
		"*   * ",
		"*   * ",
		"*   * ",
		"****  ",
	}, },
	{'E', {
		"***** ",
		"*     ",
		"***   ",
		"*     ",
		"***** ",
	}, },
	{'F', {
		"***** ",
		"*     ",
		"***   ",
		"*     ",
		"*     ",
	}, },
	{'G', {
		" **** ",
		"*     ",
		"*  ** ",
		"*   * ",
		" ***  ",
	}, },
	{'H', {
		"*   * ",
		"*   * ",
		"***** ",
		"*   * ",
		"*   * ",
	}, },
	{'I', {
		"***** ",
		"  *   ",
		"  *   ",
		"  *   ",
		"***** ",
	}, },
	{'J', {
		"  *** ",
		"   *  ",
		"   *  ",
		"*  *  ",
		" **   ",
	}, },
	{'K', {
		"*   * ",
		"*  *  ",
		"***   ",
		"*  *  ",
		"*   * ",
	}, },
	{'L', {
		"*     ",
		"*     ",
		"*     ",
		"*     ",
		"***** ",
	}, },
	{'M', {
		"*   * ",
		"** ** ",
		"* * * ",
		"*   * ",
		"*   * ",
	}, },
	{'N', {
		"*   * ",
		"**  * ",
		"* * * ",
		"*  ** ",
		"*   * ",
	}, },
	{'O', {
		" ***  ",
		"*   * ",
		"*   * ",
		"*   * ",
		" ***  ",
	}, },
	{'P', {
		"****  ",
		"*   * ",
		"****  ",
		"*     ",
		"*     ",
	}, },
	{'Q', {
		" ***  ",
		"*   * ",
		"*   * ",
		"*  ** ",
		" **** ",
	}, },
	{'R', {
		"****  ",
		"*   * ",
		"****  ",
		"*  *  ",
		"*   * ",
	}, },
	{'S', {
		" **** ",
		"*     ",
		" ***  ",
		"    * ",
		"****  ",
	}, },
	{'T', {
		"***** ",
		"* * * ",
		"  *   ",
		"  *   ",
		" ***  ",
	}, },
	{'U', {
		"*   * ",
		"*   * ",
		"*   * ",
		"*   * ",
		" ***  ",
	}, },
	{'V', {
		"*   * ",
		"*   * ",
		" * *  ",
		" * *  ",
		"  *   ",
	}, },
	{'W', {
		"*   * ",
		"*   * ",
		"* * * ",
		"** ** ",
		"*   * ",
	}, },
	{'X', {
		"*   * ",
		" * *  ",
		"  *   ",
		" * *  ",
		"*   * ",
	}, },
	{'Y', {
		"*   * ",
		" * *  ",
		"  *   ",
		"  *   ",
		"  *   ",
	}, },
	{'Z', {
		"***** ",
		"   *  ",
		"  *   ",
		" *    ",
		"***** ",
	}, },
	{' ', {
		"      ",
		"      ",
		"      ",
		"      ",
		"      ",
	}, },
};

void write_if_valid(char c, int i, int j) {
	if (0 <= i and i < 60 and 0 <= j and j < 60 and c != ' ') {
		page[i][j] = c;
	}
}

void write_c1(string& s, int row, int col) {
	// cout << row << " " << col << endl;
	// cout << s << endl;
	for (int j = 0; j < s.size(); j++) {
		write_if_valid(s[j], row, j + col);
	}
}

void write_c5(string& s, int row, int col) {
	// cout << row << " " << col << endl;
	for (int k = 0; k < s.size(); k++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 6; j++) {
				write_if_valid(m[s[k]][i][j], row + i, col + 6*k + j);
			}
		}
	}
}

void write_string(string cmd, string font, int row, string& s) {
	// cout << cmd << " " << font << endl;
	if (font == "C1") {
		if (cmd == ".L") {
			write_c1(s, row-1, 0);
		}
		if (cmd == ".R") {
			write_c1(s, row-1, 60 - (int)s.size());
		}
		if (cmd == ".C") {
			write_c1(s, row-1, 30 - (int)s.size()/2);
		}
	}
	else if (font == "C5") {
		if (cmd == ".L") {
			write_c5(s, row-1, 0);
		}
		if (cmd == ".R") {
			write_c5(s, row-1, 60 - 6*(int)s.size());
		}
		if (cmd == ".C") {
			write_c5(s, row-1, 30 - 6*(int)s.size()/2);
		}
	}
}

int main(int argc, char const *argv[]) {
	string cmd;
	while (cin >> cmd) {
		if (cmd == ".EOP") {
			for (int i = 0; i < 60; i++) {
				for (int j = 0; j < 60; j++) {
					cout << page[i][j];
				}
				cout << endl;
			}
			cout << endl;
			for (int i = 0; i < 60; i++) {
				cout << '-';
			}
			cout << endl << endl;
			page = vector<vector<char>>(60, vector<char>(60, '.'));
			continue;
		}
		string font;
		int row = 0, col = -1;
		char c; // pipe inicial
		cin >> font >> row;
		if (cmd == ".P") {
			cin >> col;
		}
		cin >> c;
		string s;
		getline(cin, s);
		s.pop_back(); // pipe final
		if (cmd != ".P") {
			write_string(cmd, font, row, s);
		}
		else {
			if (font == "C1") {
				write_c1(s, row-1, col-1);
			}
			else if (font == "C5") {
				write_c5(s, row-1, col-1);
			}
		}
	}
	return 0;
}
