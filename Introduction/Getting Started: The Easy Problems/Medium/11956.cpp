#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		string s;
		cin >> s;
		int ptr = 0;
		vector<int> mem(100, 0);
		for (auto c: s) {
			if (c == '>') {
				ptr = (ptr + 1) % 100;
			}
			else if (c == '<') {
				ptr = (ptr + 100 - 1) % 100;
			}
			else if (c == '+') {
				mem[ptr] = (mem[ptr] + 1) % 256;
			}
			else if (c == '-') {
				mem[ptr] = (mem[ptr] + 256 - 1) % 256;
			}
			else if (c == '.') {
				//
				// printf(" %.2X", mem[ptr]);
			}
		}
		cout << "Case " << t + 1 << ":";
		for (size_t i = 0; i < 100; i++) {
			printf(" %.2X", mem[i]);
		}
		puts("");
	}
	return 0;
}
