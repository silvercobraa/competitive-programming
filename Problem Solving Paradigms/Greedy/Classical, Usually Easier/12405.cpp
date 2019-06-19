#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int scarecrows(string s, int l, int r) {
	int diff = r - l;
	if (diff <= 0) {
		return 0;
	}
	int sum = 0;
	for (int i = 0; i < diff && i < 3 ; i++)
	{
		sum *= 2;
		sum += s[l + i] == '.' ? 1 : 0;
	}
	if (diff == 1) {
		if (sum == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	if (diff == 2) {
		if (sum > 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	switch (sum) {
		case 0:
			return scarecrows(s, l + 3, r);
		case 1:
			return 1 + scarecrows(s, l + 5, r);
		case 2:
		case 3:
			return 1 + scarecrows(s, l + 4, r);
		case 4:
		case 5:
		case 6:
		case 7:
			return 1 + scarecrows(s, l + 3, r);
	}
}

int main(int argc, char const* argv[])
{
	int T = 0;
	cin >> T;
	for (int case_ = 1; case_ <= T; case_++) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		cout << "Case " << case_ << ": " << scarecrows(s, 0, s.size()) << endl;

	}
	return 0;
}
