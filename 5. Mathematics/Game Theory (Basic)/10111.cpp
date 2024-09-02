#include <iostream>
#include <vector>

using namespace std;

#define INF 2

enum {X, O, EMPTY};

vector<vector<int>> rows;
vector<vector<int>> cols;
vector<int> diag1;
vector<int> diag2;

void print_winner(int player, int depth=0) {
	for (size_t j = 0; j < depth; j++) {
		cout << "    ";
	}
	cout << "player " << (player == X ? "X" : "O") << " wins!" << endl;
}
void print(const vector<int>& state, int depth=0) {
	const char* players = "xo.";
	for (size_t i = 0; i < 4; i++) {
		for (size_t j = 0; j < depth; j++) {
			cout << "    ";
		}
		for (size_t j = 0; j < 4; j++) {
			cout << players[state[4*i + j]];
		}
		cout << endl;
	}
	cout << endl;
}

bool place(vector<int>& state, int player, int row, int col) {
	state[4*row + col] = player;
	++rows[player][row];
	++cols[player][col];
	if (row == col) ++diag1[player];
	if (row + col == 3) ++diag2[player];
	return rows[player][row] == 4 or cols[player][col] == 4 or diag1[player] == 4 or diag2[player] == 4;
}

void undo(vector<int>& state, int player, int row, int col) {
	state[4*row + col] = EMPTY;
	--rows[player][row];
	--cols[player][col];
	if (row == col) --diag1[player];
	if (row + col == 3) --diag2[player];
}

// // int minimax(vector<int>& state, int player=X, int depth=0) {
// int negamax(vector<int>& state, int player=X, int depth=0, int a=-INF, int b=INF) {
// 	int player_id = player == X ? 1 : -1;
// 	int best = -INF * player_id;
// 	for (int pos = 0; pos < 16; pos++) {
// 		int row = pos/4;
// 		int col = pos%4;
// 		if (state[pos] == EMPTY) {
// 			bool winner = place(state, player, row, col);
// 			print(state, depth);
// 			if (winner) {
// 				// cout << "winner " << player << endl;
// 				undo(state, player, row, col);
// 				last_move = pos;
// 				return player == X ? INF : -INF;
// 			}
// 			// int rec = minimax(state, player == X ? O : X, depth + 1);
// 			int rec = negamax(state, player == X ? O : X, depth + 1, -b, -a);
// 			undo(state, player, row, col);
// 			// best = player_id * max(player_id*best, player_id*rec);
// 			best = max(best, -rec);
// 			a = max(a, best);
// 			if (a >= b) {
// 				// last_move = pos;
// 				break;
// 			}
// 		}
// 	}
// 	// printf("depth: %d, player %d\n", depth, player_id);
// 	last_move = -1;
// 	return best;
// }

int min_search(vector<int>&, int, int, int);

int max_search(vector<int>& state, int depth=0, int a=-INF, int b=INF) {
	int best = -INF;
	for (int pos = 0; pos < 16; pos++) {
		int row = pos/4, col = pos%4;
		if (state[pos] == EMPTY) {
			bool winning_move = place(state, X, row, col);
			// print(state, depth);
			if (winning_move) {
				// cout << "winner " << player << endl;
				undo(state, X, row, col);
				// print_winner(X, depth);
				// last_move = pos;
				return 1;
			}
			int rec = min_search(state, depth+1, a, b);
			undo(state, X, row, col);
			best = max(best, rec);
			if (best >= b) {
				return best;
			}
			a = max(a, best);
		}
	}
	return best;
}

int min_search(vector<int>& state, int depth=0, int a=-INF, int b=INF) {
	int best = INF;
	for (int pos = 0; pos < 16; pos++) {
		int row = pos/4, col = pos%4;
		if (state[pos] == EMPTY) {
			bool winning_move = place(state, O, row, col);
			// print(state, depth);
			if (winning_move) {
				// cout << "winner " << player << endl;
				undo(state, O, row, col);
				// print_winner(O, depth);
				return -1;
			}
			int rec = max_search(state, depth+1, a, b);
			undo(state, O, row, col);
			best = min(best, rec);
			if (best <= a) {
				return best;
			}
			b = min(b, best);
		}
	}
	return best;
}


int main(int argc, char const *argv[]) {
	string s;
	for (cin >> s; s[0] != '$'; cin >> s) {
		rows = vector<vector<int>>(2, vector<int>(4, 0));
		cols = vector<vector<int>>(2, vector<int>(4, 0));
		diag1 = vector<int>(2, 0);
		diag2 = vector<int>(2, 0);
		int depth = 0;
		// last_move = -1;

		vector<int> board(16, EMPTY);

		for (size_t i = 0; i < 4; i++) {
			string row;
			cin >> row;
			for (size_t j = 0; j < 4; j++) {
				char c = row[j];
				if (c == '.') {
					board[4*i + j] = EMPTY;
				}
				else if (c == 'x') {
					board[4*i + j] = X;
					place(board, X, i, j);
					depth++;

				}
				else if (c == 'o') {
					board[4*i + j] = O;
					place(board, O, i, j);
					depth++;
				}
			}
		}
		// minimax(board, X, depth);
		// int ans = negamax(board, X, depth);
		int ans = -INF;
		for (int pos = 0; pos < 16; pos++) {
			if (board[pos] != EMPTY) continue;
			int row = pos/4;
			int col = pos%4;
			bool winning_move = place(board, X, row, col);
			if (winning_move) {
				ans = INF;
				printf("(%d,%d)\n", pos/4, pos%4);
				break;
			}
			int rec = min_search(board);
			if (rec > 0) {
				ans = INF;
				printf("(%d,%d)\n", pos/4, pos%4);
				break;
			}
			undo(board, X, row, col);

		}
		if (ans <= 0) {
			puts("#####");
		}
	}
	return 0;
}
