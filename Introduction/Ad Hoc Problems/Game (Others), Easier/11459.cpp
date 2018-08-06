#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int P, SL, R;
		int player = 0;
		cin >> P >> SL >> R;
		vector<int> pos(P, 0);
		vector<int> snakes(100, -1);
		for (int i = 0; i < SL; i++) {
			int a, b;
			cin >> a >> b;
			snakes[a - 1] = b - 1;
		}
		bool finished = false;
		for (int i = 0; i < R; i++) {
			int die;
			cin >> die;
			if (finished) {
				continue;
			}
			pos[player] = min((pos[player] + die), 99);
			if (snakes[pos[player]] != -1) {
				pos[player] = snakes[pos[player]];
			}
			if (pos[player] == 99) {
				finished = true;
			}
			player = (player + 1) % P;
		}
		for (int i = 0; i < P; i++) {
			cout << "Position of player " << i + 1 << " is " << pos[i] + 1 << "." << endl;
		}
	}
	return 0;
}
