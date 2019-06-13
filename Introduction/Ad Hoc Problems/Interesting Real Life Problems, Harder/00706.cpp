#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<string>> v = {
	{
		" - ",
		"| |",
		"   ",
		"| |",
		" - ",
	},
	{
		"   ",
		"  |",
		"   ",
		"  |",
		"   ",
	},
	{
		" - ",
		"  |",
		" - ",
		"|  ",
		" - ",
	},
	{
		" - ",
		"  |",
		" - ",
		"  |",
		" - ",
	},
	{
		"   ",
		"| |",
		" - ",
		"  |",
		"   ",
	},
	{
		" - ",
		"|  ",
		" - ",
		"  |",
		" - ",
	},
	{
		" - ",
		"|  ",
		" - ",
		"| |",
		" - ",
	},
	{
		" - ",
		"  |",
		"   ",
		"  |",
		"   ",
	},
	{
		" - ",
		"| |",
		" - ",
		"| |",
		" - ",
	},
	{
		" - ",
		"| |",
		" - ",
		"  |",
		" - ",
	},
};

void print_row(string n, int s, int row) {
	for (int i = 0; i < n.size(); i++) {
		if (i != 0) {
			cout << " ";
		}
		char c = n[i];
		int d = c - '0';
		cout << v[d][row][0];
		for (int j = 0; j < s; j++) {
			cout << v[d][row][1];
		}
		cout << v[d][row][2];
	}
	cout << endl;
}
int main(int argc, char const *argv[]) {
	int s;
	string n;
	for (cin >> s >> n; s != 0 or n != "0"; cin >> s >> n) {
		// cout << n << endl;
		print_row(n, s, 0);
		for (int i = 0; i < s; i++) {
			print_row(n, s, 1);
		}
		print_row(n, s, 2);
		for (int i = 0; i < s; i++) {
			print_row(n, s, 3);
		}
		print_row(n, s, 4);
		cout << endl;
	}
	return 0;
}
