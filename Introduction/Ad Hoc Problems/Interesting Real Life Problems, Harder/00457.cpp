#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	string s = " .xW";
	for (int t = 0; t < n; t++) {
		if (t != 0) {
			cout << endl;
		}
		vector<int> dna(10);
		vector<vector<int>> dish(50, vector<int>(40, 0));
		dish[0][20-1] = 1;
		for (int i = 0; i < 10; i++) {
			cin >> dna[i];
		}
		for (int i = 1; i < 50; i++) {
			for (int j = 0; j < 40; j++) {
				int sum = dish[i - 1][j];
				if (j != 0) {
					sum += dish[i - 1][j - 1];
				}
				if (j != 40-1) {
					sum += dish[i - 1][j + 1];
				}
				dish[i][j] = dna[sum];
			}
		}
		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 40; j++) {
				cout << s[dish[i][j]];
			}
			cout << endl;
		}
	}
	return 0;
}
