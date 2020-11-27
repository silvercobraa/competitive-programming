#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	map<string, int> value = {{"left", 0}, {"right", 1}};
	for (size_t t = 0; t < T; t++) {
		int L, M;
		cin >> L >> M;
		L *= 100;
		int side = 0; // 0 left, 1 right
		int loaded = 0;
		int trips = 0;
		vector<queue<int>> q(2);
		for (size_t i = 0; i < M; i++) {
			int length;
			string s;
			cin >> length >> s;
			q[value[s]].push(length);
		}
		while ((not q[0].empty()) or (not q[1].empty())) {
			while ((not q[side].empty()) and q[side].front() + loaded <= L) {
				loaded += q[side].front();
				q[side].pop();
			}
			if (loaded > 0) {
				loaded = 0;
			}
			trips++;
			side = 1 - side;
		}
		// cout << "size: " << q[0].size() << " " << q[1].size() << endl;
		// cout << trips << " " << loaded << endl;
		cout << trips << endl;
	}
	return 0;
}
