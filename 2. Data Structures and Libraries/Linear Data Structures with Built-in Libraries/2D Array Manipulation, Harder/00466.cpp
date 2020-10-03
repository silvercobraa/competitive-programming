#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> M1;
vector<string> M2;

bool rot90(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (M1[i][j] != M2[j][n-i-1]) {
				return false;
			}
		}
	}
	return true;
}

bool rot270(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (M1[i][j] != M2[n-j-1][i]) {
				return false;
			}
		}
	}
	return true;
}

bool rot180(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (M1[i][j] != M2[n-i-1][n-j-1]) {
				return false;
			}
		}
	}
	return true;
}

bool vflip(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (M1[i][j] != M2[n-i-1][j]) {
				return false;
			}
		}
	}
	return true;
}

bool vflip90(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (M1[i][j] != M2[j][i]) {
				return false;
			}
		}
	}
	return true;
}

bool vflip180(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (M1[i][j] != M2[i][n-j-1]) {
				return false;
			}
		}
	}
	return true;
}

bool vflip270(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (M1[i][j] != M2[n-j-1][n-i-1]) {
				return false;
			}
		}
	}
	return true;
}

int main(int argc, char const *argv[]) {
	int n;
	for (int cas = 1; cin >> n; cas++) {
		M1 = vector<string>(n);
		M2 = vector<string>(n);
		for (int i = 0; i < n; i++) {
			cin >> M1[i] >> M2[i];
		}
		cout << "Pattern " << cas << " was ";
		if (M1 == M2) {
			cout << "preserved." << endl;
		}
		else if (rot90(n)) {
			cout << "rotated 90 degrees." << endl;
		}
		else if (rot270(n)) {
			cout << "rotated 270 degrees." << endl;
		}
		else if (rot180(n)) {
			cout << "rotated 180 degrees." << endl;
		}
		else if (vflip(n)) {
			cout << "reflected vertically." << endl;
		}
		else if (vflip90(n)) {
			cout << "reflected vertically and rotated 90 degrees." << endl;
		}
		else if (vflip180(n)) {
			cout << "reflected vertically and rotated 180 degrees." << endl;
		}
		else if (vflip270(n)) {
			cout << "reflected vertically and rotated 270 degrees." << endl;
		}
		else {
			cout << "improperly transformed." << endl;
		}
	}
	return 0;
}
