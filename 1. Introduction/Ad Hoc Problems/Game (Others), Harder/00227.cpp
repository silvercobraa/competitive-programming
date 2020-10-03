#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool simulate(vector<string>& puzzle, string& moves, int i, int j) {
	for (auto move: moves) {
		if (move == 'A') {
			if (i == 0) {
				return false;
			}
			puzzle[i][j] = puzzle[i - 1][j];
			puzzle[i - 1][j] = ' ';
			i--;
		}
		else if (move == 'B') {
			if (i == 4) {
				return false;
			}
			puzzle[i][j] = puzzle[i + 1][j];
			puzzle[i + 1][j] = ' ';
			i++;
		}
		else if (move == 'L') {
			if (j == 0) {
				return false;
			}
			puzzle[i][j] = puzzle[i][j - 1];
			puzzle[i][j - 1] = ' ';
			j--;
		}
		else if (move == 'R') {
			if (j == 4) {
				return false;
			}
			puzzle[i][j] = puzzle[i][j + 1];
			puzzle[i][j + 1] = ' ';
			j++;
		}
	}
	return true;
}

int main(int argc, char const *argv[]) {
	string s;
	int t = 1;
	for (getline(cin, s); s != "Z"; getline(cin, s), t++) {
		if (t != 1) {
			cout << endl;
		}
		vector<string> puzzle(5);
		puzzle[0] = s;
		for (int i = 1; i < 5; i++) {
			getline(cin, puzzle[i]);
		}
		int x = -1;
		int y = -1;
		// parece que getline se pasa por la raja los espacios al final
		// asi que hay que verificar este caso
		for (int i = 0; i < puzzle.size(); i++) {
			if (puzzle[i].size() == 4) {
				puzzle[i].push_back(' ');
			}
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (puzzle[i][j] == ' ') {
					x = i;
					y = j;
				}
			}
		}
		string moves = "";
		string move;
		do {
			getline(cin, move);
			moves += move;
		} while(move[move.size() - 1] != '0');

		bool ans = simulate(puzzle, moves, x, y);
		cout << "Puzzle #" << t << ":" << endl;
		if (ans) {
			for (auto row: puzzle) {
				cout << row[0];
				for (int i = 1; i < 5; i++) {
					cout << " " << row[i];
				}
				cout << endl;
			}
		}
		else {
			cout << "This puzzle has no final configuration." << endl;
		}
	}
	return 0;
}
