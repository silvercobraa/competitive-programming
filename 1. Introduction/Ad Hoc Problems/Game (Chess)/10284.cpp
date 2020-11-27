// esto se pudo haber hecho mucho mas decente
#include <iostream>
#include <vector>
#include <string>
#include <set>

#define EMPTY '.'

using namespace std;

vector<vector<char>> board;
set<pair<int,int>> occupied;

bool valid(int row, int col) {
	return 0 <= row and row < 8 and 0 <= col and col < 8;
}

void pawn(int row, int col, int dir) {
	if (valid(row + dir, col + 1) and board[row + dir][col + 1] == EMPTY) {
		occupied.insert({row + dir, col + 1});
	}
	if (valid(row + dir, col - 1) and board[row + dir][col - 1] == EMPTY) {
		occupied.insert({row + dir, col - 1});
	}
}

void knight(int row, int col) {
	for (int i = -2; i <= 2; i++) {
		for (int j = -2; j <= 2; j++) {
			if (i*j != 2 and i*j != -2) {
				continue;
			}
			if (valid(row + i, col + j) and board[row + i][col + j] == EMPTY) {
				occupied.insert({row + i, col + j});
			}
		}
	}
}

void king(int row, int col) {
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (i == 0 and j == 0) {
				continue;
			}
			if (valid(row + i, col + j) and board[row + i][col + j] == EMPTY) {
				occupied.insert({row + i, col + j});
			}
		}
	}
}

void generic(int row, int col, int rdir, int cdir) {
	for (int i = row + rdir, j = col + cdir; valid(i, j); i += rdir, j += cdir) {
		if (board[i][j] == EMPTY) {
			occupied.insert({i, j});
		}
		else {
			break;
		}
	}
}

void rook(int row, int col) {
	generic(row, col, 0, 1);
	generic(row, col, 0, -1);
	generic(row, col, 1, 0);
	generic(row, col, -1, 0);
}

void bishop(int row, int col) {
	generic(row, col, 1, 1);
	generic(row, col, 1, -1);
	generic(row, col, -1, 1);
	generic(row, col, -1, -1);

}

void queen(int row, int col) {
	rook(row, col);
	bishop(row, col);
}

int main(int argc, char const *argv[]) {
	string s;
	while (cin >> s) {
		// cout << s << endl;
		board = vector<vector<char>>(8, vector<char>(8, EMPTY));
		int row = 0;
		int col = 0;
		for (auto c: s) {
			if (c == '/') {
				row++;
				col = 0;
			}
			else if ('1' <= c and c <= '8') {
				col += int(c - '1' + 1);
			}
			else {
				board[row][col] = c;
				occupied.insert({row, col});
				col++;
			}
		}
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				char piece = board[i][j];
				if (piece == 'p') {
					pawn(i, j, 1);
				}
				else if (piece == 'P') {
					pawn(i, j, -1);
				}
				else if (piece == 'n' or piece  == 'N') {
					knight(i, j);
				}
				else if (piece == 'k' or piece  == 'K') {
					king(i, j);
				}
				else if (piece == 'r' or piece  == 'R') {
					rook(i, j);
				}
				else if (piece == 'b' or piece  == 'B') {
					bishop(i, j);
				}
				else if (piece == 'q' or piece  == 'Q') {
					queen(i, j);
				}
			}
		}
		// for (auto p: occupied) {
		// 	cout << p.first << " " << p.second << endl;
		// }
		// cout << endl;
		cout << 64 - int(occupied.size()) << endl;
		board.clear();
		occupied.clear();
	}
	return 0;
}
