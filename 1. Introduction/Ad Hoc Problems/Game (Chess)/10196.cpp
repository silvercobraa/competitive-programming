// esto se pudo haber hecho mucho mas decente
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool empty(vector<string>& board) {
	for (auto row: board) {
		if (row != "........") {
			return false;
		}
	}
	return true;
}

void find(vector<string>& board, char piece, int& row, int& col) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j] == piece) {
				row = i;
				col = j;
				return;
			}
		}
	}
}

bool valid(int row, int col) {
	return 0 <= row and row < 8 and 0 <= col and col < 8;
}

int main(int argc, char const *argv[]) {
	for (int cas = 0; ; cas++) {
		vector<string> board(8);
		for (int i = 0; i < 8; i++) {
			cin >> board[i];
		}
		if (empty(board)) {
			break;
		}
		int brow = -1;
		int bcol = -1;
		int wrow = -1;
		int wcol = -1;
		find(board, 'K', wrow, wcol);
		find(board, 'k', brow, bcol);
		bool bcheck = false;
		bool wcheck = false;
		if (valid(brow, bcol)) {
			// pawn
			if (valid(brow + 1, bcol + 1) and board[brow + 1][bcol + 1] == 'P') {
				bcheck = true;
			}
			if (valid(brow + 1, bcol - 1) and board[brow + 1][bcol - 1] == 'P') {
				bcheck = true;
			}
			//knight
			if (valid(brow + 2, bcol + 1) and board[brow + 2][bcol + 1] == 'N') {
				bcheck = true;
			}
			if (valid(brow + 1, bcol + 2) and board[brow + 1][bcol + 2] == 'N') {
				bcheck = true;
			}
			if (valid(brow + 2, bcol - 1) and board[brow + 2][bcol - 1] == 'N') {
				bcheck = true;
			}
			if (valid(brow + 1, bcol - 2) and board[brow + 1][bcol - 2] == 'N') {
				bcheck = true;
			}
			if (valid(brow - 2, bcol + 1) and board[brow - 2][bcol + 1] == 'N') {
				bcheck = true;
			}
			if (valid(brow - 1, bcol + 2) and board[brow - 1][bcol + 2] == 'N') {
				bcheck = true;
			}
			if (valid(brow - 2, bcol - 1) and board[brow - 2][bcol - 1] == 'N') {
				bcheck = true;
			}
			if (valid(brow - 1, bcol - 2) and board[brow - 1][bcol - 2] == 'N') {
				bcheck = true;
			}
			for (int i = brow + 1; i < 8; i++) {
				char p = board[i][bcol];
				if (p == 'R' or p == 'Q') {
					bcheck = true;
				}
				else if (p != '.') {
					break;
				}
			}
			for (int i = brow - 1; i >= 0; i--) {
				char p = board[i][bcol];
				if (p == 'R' or p == 'Q') {
					bcheck = true;
				}
				else if (p != '.') {
					break;
				}
			}
			for (int j = bcol + 1; j < 8; j++) {
				char p = board[brow][j];
				if (p == 'R' or p == 'Q') {
					bcheck = true;
				}
				else if (p != '.') {
					break;
				}
			}
			for (int j = bcol - 1; j >= 0; j--) {
				char p = board[brow][j];
				if (p == 'R' or p == 'Q') {
					bcheck = true;
				}
				else if (p != '.') {
					break;
				}
			}
			for (int i = brow + 1, j = bcol + 1; valid(i, j); i++, j++) {
				char p = board[i][j];
				if (p == 'B' or p == 'Q') {
					bcheck = true;
				}
				else if (p != '.') {
					break;
				}
			}
			for (int i = brow + 1, j = bcol - 1; valid(i, j); i++, j--) {
				char p = board[i][j];
				if (p == 'B' or p == 'Q') {
					bcheck = true;
				}
				else if (p != '.') {
					break;
				}
			}
			for (int i = brow - 1, j = bcol + 1; valid(i, j); i--, j++) {
				char p = board[i][j];
				if (p == 'B' or p == 'Q') {
					bcheck = true;
				}
				else if (p != '.') {
					break;
				}
			}
			for (int i = brow - 1, j = bcol - 1; valid(i, j); i--, j--) {
				char p = board[i][j];
				if (p == 'B' or p == 'Q') {
					bcheck = true;
				}
				else if (p != '.') {
					break;
				}
			}
		}
		if (valid(wrow, wcol)) {
			// pawn
			if (valid(wrow - 1, wcol + 1) and board[wrow - 1][wcol + 1] == 'p') {
				wcheck = true;
			}
			if (valid(wrow - 1, wcol - 1) and board[wrow - 1][wcol - 1] == 'p') {
				wcheck = true;
			}
			//knight
			if (valid(wrow + 2, wcol + 1) and board[wrow + 2][wcol + 1] == 'n') {
				wcheck = true;
			}
			if (valid(wrow + 1, wcol + 2) and board[wrow + 1][wcol + 2] == 'n') {
				wcheck = true;
			}
			if (valid(wrow + 2, wcol - 1) and board[wrow + 2][wcol - 1] == 'n') {
				wcheck = true;
			}
			if (valid(wrow + 1, wcol - 2) and board[wrow + 1][wcol - 2] == 'n') {
				wcheck = true;
			}
			if (valid(wrow - 2, wcol + 1) and board[wrow - 2][wcol + 1] == 'n') {
				wcheck = true;
			}
			if (valid(wrow - 1, wcol + 2) and board[wrow - 1][wcol + 2] == 'n') {
				wcheck = true;
			}
			if (valid(wrow - 2, wcol - 1) and board[wrow - 2][wcol - 1] == 'n') {
				wcheck = true;
			}
			if (valid(wrow - 1, wcol - 2) and board[wrow - 1][wcol - 2] == 'n') {
				wcheck = true;
			}
			for (int i = wrow + 1; i < 8; i++) {
				char p = board[i][wcol];
				if (p == 'r' or p == 'q') {
					wcheck = true;
				}
				else if (p != '.') {
					break;
				}
			}
			for (int i = wrow - 1; i >= 0; i--) {
				char p = board[i][wcol];
				if (p == 'r' or p == 'q') {
					wcheck = true;
				}
				else if (p != '.') {
					break;
				}
			}
			for (int j = wcol + 1; j < 8; j++) {
				char p = board[wrow][j];
				if (p == 'r' or p == 'q') {
					wcheck = true;
				}
				else if (p != '.') {
					break;
				}
			}
			for (int j = wcol - 1; j >= 0; j--) {
				char p = board[wrow][j];
				if (p == 'r' or p == 'q') {
					wcheck = true;
				}
				else if (p != '.') {
					break;
				}
			}
			for (int i = wrow + 1, j = wcol + 1; valid(i, j); i++, j++) {
				char p = board[i][j];
				if (p == 'b' or p == 'q') {
					wcheck = true;
				}
				else if (p != '.') {
					break;
				}
			}
			for (int i = wrow + 1, j = wcol - 1; valid(i, j); i++, j--) {
				char p = board[i][j];
				if (p == 'b' or p == 'q') {
					wcheck = true;
				}
				else if (p != '.') {
					break;
				}
			}
			for (int i = wrow - 1, j = wcol + 1; valid(i, j); i--, j++) {
				char p = board[i][j];
				if (p == 'b' or p == 'q') {
					wcheck = true;
				}
				else if (p != '.') {
					break;
				}
			}
			for (int i = wrow - 1, j = wcol - 1; valid(i, j); i--, j--) {
				char p = board[i][j];
				if (p == 'b' or p == 'q') {
					wcheck = true;
				}
				else if (p != '.') {
					break;
				}
			}
		}
		if (bcheck) {
			cout << "Game #" << cas + 1 << ": black king is in check." << endl;
		}
		else if (wcheck) {
			cout << "Game #" << cas + 1 << ": white king is in check." << endl;
		}
		else {
			cout << "Game #" << cas + 1 << ": no king is in check." << endl;
		}
	}
	return 0;
}
