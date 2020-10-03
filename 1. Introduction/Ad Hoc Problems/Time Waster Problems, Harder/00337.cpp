#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int n, t = 1;
	for (cin >> n; n != 0; cin >> n, t++) {
		string line;
		getline(cin, line);
		vector<string> screen(10, "          ");
		int row = 0, col = 0;
		bool overwrite = true;
		for (int l = 0; l < n; l++) {
			getline(cin, line);
			// cout << line << endl;
			for (int i = 0; i < line.size(); i++) {
				char c1 = line[i];
				if (c1 == '^') {
					char c2 = line[i+1];
					if (isdigit(c2)) {
						row = line[i+1] - '0';
						col = line[i+2] - '0';
						i += 2;
					}
					else if (c2 == 'b') {
						col = 0;
						i++;
					}
					else if (c2 == 'c') {
						screen = vector<string>(10, "          ");
						i++;
					}
					else if (c2 == 'd') {
						row += row != 9;
						i++;
					}
					else if (c2 == 'e') {
						for (int j = col; j < 10; j++) {
							screen[row][j] = ' ';
						}
						i++;
					}
					else if (c2 == 'h') {
						row = 0;
						col = 0;
						i++;
					}
					else if (c2 == 'i') {
						overwrite = false;
						i++;
					}
					else if (c2 == 'l') {
						col -= col != 0;
						i++;
					}
					else if (c2 == 'o') {
						overwrite = true;
						i++;
					}
					else if (c2 == 'r') {
						col += col != 9;
						i++;
					}
					else if (c2 == 'u') {
						row -= row != 0;
						i++;
					}
					else if (c2 == '^') {
						if (overwrite) {
							screen[row][col] = '^';
							col += col != 9;
						}
						else {
							for (int j = 9; j > col; j--) {
								screen[row][j] = screen[row][j-1];
							}
							screen[row][col] = '^';
							col += col != 9;
						}
						i++;
					}
				}
				else if (overwrite) {
					screen[row][col] = c1;
					col += col != 9;
				}
				else {
					for (int j = 9; j > col; j--) {
						screen[row][j] = screen[row][j-1];
					}
					screen[row][col] = c1;
					col += col != 9;
				}
			}
		}
		cout << "Case " << t << "\n+----------+" << endl;
		for (auto l: screen) {
			cout << "|" << l << "|" << endl;
		}
		cout << "+----------+" << endl;
	}
	return 0;
}
