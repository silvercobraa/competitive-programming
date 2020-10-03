#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	while (cin >> n) {
		int m;
		cin >> m;
		vector<bool> awake(26, false);
		vector<vector<bool>> graph(26, vector<bool>(26, false));
		string s;
		cin >> s;
		// cout << s << endl;
		for (char c: s) {
			awake[c - 'A'] = true;
		}
		for (int i = 0; i < m; i++) {
			char a, b;
			cin >> a >> b;
			graph[a - 'A'][b - 'A'] = true;
			graph[b - 'A'][a - 'A'] = true;
		}
		// cout << "  ";
		// for (char c = 'A'; c <= 'Z'; c++) {
		// 	cout << c << " ";
		// }
		// cout << endl;
		// char c = 'A';
		// for (auto v: graph) {
		// 	cout << c << " ";
		// 	for (auto x: v) {
		// 		cout << x << " ";
		// 	}
		// 	cout << endl;
		// 	c++;
		// }
		vector<bool> awake2 = awake;
		int years = 0;
		while (true) {
			for (int i = 0; i < 26; i++) {
				int count = 0;
				for (int j = 0; j < 26; j++) {
					count += graph[i][j] and awake[j];
				}
				if (count >= 3) {
					// cout << "waking " << i << endl;
					awake2[i] = true;
				}
			}
			// cout << endl;
			if (awake2 == awake) {
				break;
			}
			else {
				years += 1;
				awake = awake2;
			}
		}
		// cout << years << endl;
		int count_awake = 0;
		for (int i = 0; i < 26; i++) {
			if (awake[i]) {
				count_awake++;
			}
		}
		// cout << count_awake << endl;
		if (count_awake != n) {
			puts("THIS BRAIN NEVER WAKES UP");
		}
		else {
			printf("WAKE UP IN, %d, YEARS\n", years);
		}
	}
	return 0;
}
