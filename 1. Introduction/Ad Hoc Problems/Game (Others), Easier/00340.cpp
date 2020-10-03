#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	int game = 1;
	for (cin >> N; N != 0; cin >> N, game++) {
		vector<int> s(N);
		multiset<int> ss;
		for (int i = 0; i < N; i++) {
			cin >> s[i];
			ss.insert(s[i]);
		}
		cout << "Game " << game << ":" << endl;
		while (true) {
			bool zeros = true;
			vector<int> g(N);
			multiset<int> sg;
			int strong = 0;
			for (int i = 0; i < N; i++) {
				cin >> g[i];
				sg.insert(g[i]);
				if (g[i] != 0) {
					zeros = false;
				}
				if (g[i] == s[i]) {
					strong++;
				}
			}
			if (zeros) {
				break;
			}
			multiset<int> inter;
			set_intersection(ss.begin(), ss.end(), sg.begin(), sg.end(), inserter(inter, inter.begin()));
			int matches = inter.size();
			int weak = matches - strong;
			cout << "    (" << strong << "," << weak << ")" << endl;
		}
	}
	return 0;
}
