#include <iostream>
#include <queue>
#include <utility>

#define INF 99999999

using namespace std;

long long MAX = 4294967295;
// long long MAX = 17;
// long long MAX = 162;

int minimax(int player=1, long long value=1, int depth=0) {
	// cout << depth << " " << value << endl;
	if (value >= MAX) {
		// cout << "retornando " << -player << endl;
		return -player;
	}
	int best = -INF * player;
	for (int i = 2; i <= 9; i += 7) {
		int rec = minimax(-player, i*value, depth+1);
		best = player*max(player*best, player*rec);
	}
	// printf("depth: %d, player %d, value: %Ld, best: %d\n", depth, player, value, best);
	return best;
}

int main(int argc, char const *argv[]) {
	while (cin >> MAX) {
		// cout << MAX << endl;
		int ans = minimax();
		if (ans == 1) {
			puts("Stan wins.");
		}
		else {
			puts("Ollie wins.");
		}
	}
	return 0;
}
