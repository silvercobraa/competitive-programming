#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<string>> digits {
	{
		".*.",
		".*.",
		".*.",
		".*.",
		".*.",
	},
	{
		"***",
		"..*",
		"***",
		"*..",
		"***",
	},
	{
		"***",
	    "..*",
	    "***",
	    "..*",
	    "***",
	}
};

bool compare(const vector<string>& grid, const vector<string>& digit, int offset) {
	for (int row = 0; row < 5; row++) {
		if (digit[row] != grid[row].substr(offset, 3)) {
			return false;
		}
	}
	return true;
}


int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<string> grid(5);
	for (int k = 0; k < 5; k++) {
		cin >> grid[k];
	}
	for (int offset = 0; offset < 4*n; offset += 4) {
		for (int digit = 1; digit <= 3; digit++) {
			if (compare(grid, digits[digit-1], offset)) {
				cout << digit;
			}
		}
	}
	cout << endl;
	return 0;
}
