// César Bolívar Severino
// resuelto propio
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char const* argv[])
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int B, SG, SB;
		cin >> B >> SG >> SB;
		multiset<int, greater<int>> green;
		multiset<int, greater<int>> blue;
		for (int j = 0; j < SG; j++) {
			int x;
			cin >> x;
			green.insert(x);
		}
		// for (auto y: blue) {
		// 	cout << ' ' << y;
		// }
		// cout << endl;
		for (int j = 0; j < SB; j++) {
			int x;
			cin >> x;
			blue.insert(x);
		}
		while (green.size() != 0 && blue.size() != 0) {
			auto git = green.begin();
			auto bit = blue.begin();
			vector<int> survivors_green;
			vector<int> survivors_blue;
			for (int j = 0; j < B; j++) {
				if (git == green.end() || bit == blue.end()) {
					break;
				}
				int g = *git;
				int b = *bit;
				green.erase(git);
				blue.erase(bit);
				git++;
				bit++;
				if (g > b) {
					survivors_green.push_back(g - b);
				}
				else if (b > g) {
					survivors_blue.push_back(b - g);
				}
			}
			for (auto x: survivors_green) {
				green.insert(x);
				// cout << ' ' << x;
			}
			for (auto x: survivors_blue) {
				blue.insert(x);
				// cout << ' ' << x;
			}
		}
		if (green.size() != 0) {
			cout << "green wins" << endl;
			for (auto x: green) {
				cout << x << endl;
			}
		}
		else if (blue.size() != 0) {
			cout << "blue wins" << endl;
			for (auto x: blue) {
				cout << x << endl;
			}
		}
		else {
			cout << "green and blue died" << endl;
		}
		if (i != N - 1) {
			cout << endl;
		}
		// for (auto y: green) {
		// 	cout << ' ' << y;
		// }
		// cout << endl;
	}
	return 0;
}
