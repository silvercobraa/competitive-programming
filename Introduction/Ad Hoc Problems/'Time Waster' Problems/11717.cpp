#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int n, i_, k;
		cin >> n >> i_ >> k;
		// bool active = true;
		int ignored = 0;
		int idled = 0;
		int time = 0;
		vector<int> instruction(n);
		for (int i = 0; i < n; i++) {
			cin >> instruction[i];
		}
		int ins = 0;
		while (ins < instruction.size()) {
			// cout << time << endl;
			if (time + i_ <= instruction[ins]) {
				idled++;
				time = instruction[ins] + k;
				for (ins = ins+1; ins < instruction.size() and time > instruction[ins]; ins++) {
					ignored++;
				}
			}
			else {
				time = instruction[ins];
				ins++;
			}
		}
		printf("Case %d: %d %d\n", t, idled, ignored);
	}
	return 0;
}
