#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (size_t t = 0; t < T; t++) {
		string s;
		cin >> s;
		int o_count = 0;
		long score = 0;
		for (auto c: s) {
			if (c == 'O') {
				o_count++;
				score += o_count;
			}
			else {
				o_count = 0;
			}
		}
		cout << score << endl;
	}
	return 0;
}
