#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int value(string& s) {
	if ('2' <= s[0] and s[0] <= '9') {
		return int(s[0] - '0');
	}
	else return 10;
}

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cout << "Case " << t + 1 << ": ";
		vector<string> pile(52 - 25);
		for (int i = 0; i < 52 - 25; i++) {
			cin >> pile[i];
		}
		vector<string> hand(25);
		for (int i = 0; i < 25; i++) {
			cin >> hand[i];
		}
		int y = 0;
		for (int i = 0; i < 3; i++) {
			int x = value(pile.back());
			// cout << "x" << x << endl;
			// cout << "back" << pile.back() << endl;
			pile.pop_back();
			// cout << "back" << pile.back() << endl;
			y += x;
			for (int j = 0; j < 10 - x; j++) {
				pile.pop_back();
			}
		}
		y--; // correcion para evitar off by 1
		if (y < int(pile.size())) {
			cout << pile[y] << endl;
		}
		else {
			cout << hand[y - int(pile.size())] << endl;
		}
	}
	return 0;
}
