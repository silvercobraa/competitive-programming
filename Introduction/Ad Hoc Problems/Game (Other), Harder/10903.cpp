#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
	int p;
	bool first = true;
	for (cin >> p; p != 0; cin >> p) {
		if (first) {
			first = false;
		}
		else {
			cout << endl;
		}
		int n;
		cin >> n;
		// cout << p << endl;
		// cout << n << endl;
		int N = n*p*(p - 1) / 2;
		vector<int> won(p, 0);
		vector<int> lost(p, 0);
		for (size_t i = 0; i < N; i++) {
			int p1, p2;
			string m1, m2;
			cin >> p1 >> m1 >> p2 >> m2;
			// cout << p1 << m1 << p2 << m2 << endl;
			if ((m1 == "rock" and m2 == "paper")
				or (m1 == "paper" and m2 == "scissors")
				or (m1 == "scissors" and m2 == "rock")
			) {
				lost[p1 - 1]++;
				won[p2 - 1]++;
			}
			else if ((m2 == "rock" and m1 == "paper")
				or (m2 == "paper" and m1 == "scissors")
				or (m2 == "scissors" and m1 == "rock")
			) {
				lost[p2 - 1]++;
				won[p1 - 1]++;
			}
		}
		for (size_t i = 0; i < p; i++) {
			// cout << won[i] << " " << lost[i] << endl;
			if (won[i] + lost[i] == 0) {
				printf("-\n");
			}
			else {
				printf("%.3lf\n", double(won[i]) / (won[i] + lost[i]));
			}
		}
	}
	return 0;
}
