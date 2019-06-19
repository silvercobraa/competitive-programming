#include <iostream>
#include <string>
#include <vector>

using namespace std;

int COLS;

string btod(string& bitmap, int x, int y, int rows, int cols) {
	// printf("%d %d %d %d: ", x, y, rows, cols);
	if (rows == 0 || cols == 0) {
		// cout << "\"\"" << endl;
		return "";
	}
	if (rows == 1 && cols == 1) {
		// return bitmap[x][y]; // castear esta wea a string
		// cout << string(1, bitmap[COLS*x + y]) << endl;
		return string(1, bitmap[COLS*x + y]);
	}
	int hr = rows / 2;
	int hc = cols / 2;
	string s11 = btod(bitmap, x, y, rows - hr, cols - hc);
	string s12 = btod(bitmap, x, y + cols - hc, rows - hr, hc);
	string s21 = btod(bitmap, x + rows - hr, y, hr, cols - hc);
	string s22 = btod(bitmap, x + rows - hr, y + cols - hc, hr, hc);
	if (s11.size() == 1) {
		if ((s12 == "" || s12 == s11) && (s21 == "" || s21 == s11) && (s22 == "" || s22 == s11)) {
			return s11;
		}
	}
	// else {
		// cout << "D " + s11 + " " + s12 + " " + s21 + " " + s22 << endl;
		return "D" + s11 + s12 + s21 + s22;
	// }
}

int pos = 0;
void dtob(string& M, string& bitmap, int x, int y, int rows, int cols) {
	// cout << pos << ' ' << bitmap << ' ' << x << ' ' << y << ' ' << rows << ' ' << cols << endl;
	if (pos == bitmap.size()) {
		return;
	}
	char c = bitmap[pos];
	if (c == '0' || c == '1') {
		for (size_t i = x; i < x + rows; i++) {
			for (size_t j = y; j < y + cols; j++) {
				// cout << i << ' ' << j << endl;
				M[i*COLS + j] = c;
			}
		}
		// cout << "returning" << endl;
		return;
	}
	int hr = rows / 2;
	int hc = cols / 2;
	pos++;
	dtob(M, bitmap, x, y, rows - hr, cols - hc);
	if (hc != 0) {
		pos++;
		dtob(M, bitmap, x, y + cols - hc, rows - hr, hc);
	}
	if (hr != 0) {
		pos++;
		dtob(M, bitmap, x + rows - hr, y, hr, cols - hc);
		if (hc != 0) {
			pos++;
			dtob(M, bitmap, x + rows - hr, y + cols - hc, hr, hc);
		}

	}
}

int main(int argc, char const* argv[])
{
	string c;
	for (cin >> c; c != "#"; ) {
		// cout << c << endl;
		int rows = 0, cols = 0;
		string s;
		cin >> rows >> cols >> s;
		COLS = cols;
		// cout << "s: " << s << endl;
		string s2 = "";
		while (s2 != "B" && s2 != "D" && s2 != "#") {
			cin >> s2;
			s += s2;
		}
		if (c == "B") {
			cout << "D  ";
			if (rows < 10) {
				cout << " ";
			}
			cout << rows;
			if (cols < 10) {
				cout << " ";
			}
			cout << "  " << cols << endl;
			string ans = btod(s, 0, 0, rows, cols);
			for (int i = 0; i < ans.size(); i += 50) {
				for (int j = i; j < i + 50 && j < ans.size(); j++) {
					cout << ans[j];
				}
				cout << endl;
			}
		}
		else if (c == "D") {
			cout << "B  ";
			if (rows < 10) {
				cout << " ";
			}
			cout << rows;
			if (cols < 10) {
				cout << " ";
			}
			cout << "  " << cols << endl;
			string bitmap;
			bitmap.resize(rows*cols);
			// cout << "BITMAP: " << bitmap  << bitmap.size()<< endl;
			pos = 0;
			dtob(bitmap, s, 0, 0, rows, cols);
			for (int i = 0; i < bitmap.size(); i += 50) {
				for (int j = i; j < i + 50 && j < bitmap.size(); j++) {
					cout << bitmap[j];
				}
				cout << endl;
			}
		}
		c = s2;
	}
	return 0;
}
