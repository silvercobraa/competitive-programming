#include <iostream>
#include <vector>
#include <string>

using namespace std;

int line_count(vector<string>& board, char c) {
	int count = 0;
	if (board[0][0] == c and board[0][1] == c and board[0][2] == c) {
		count++;
	}
	if (board[1][0] == c and board[1][1] == c and board[1][2] == c) {
		count++;
	}
	if (board[2][0] == c and board[2][1] == c and board[2][2] == c) {
		count++;
	}
	if (board[0][0] == c and board[1][0] == c and board[2][0] == c) {
		count++;
	}
	if (board[0][1] == c and board[1][1] == c and board[2][1] == c) {
		count++;
	}
	if (board[0][2] == c and board[1][2] == c and board[2][2] == c) {
		count++;
	}
	if (board[0][0] == c and board[1][1] == c and board[2][2] == c) {
		count++;
	}
	if (board[0][2] == c and board[1][1] == c and board[2][0] == c) {
		count++;
	}
	return count;
}

int corner_count(vector<string>& board, char c) {
	int count = 0;
	if (board[0][0] == c) {
		count++;
	}
	if (board[0][2] == c) {
		count++;
	}
	if (board[2][0] == c) {
		count++;
	}
	if (board[2][2] == c) {
		count++;
	}
	return count;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	for (size_t i = 0; i < n; i++) {
		vector<string> board(3);
		cin >> board[0];
		cin >> board[1];
		cin >> board[2];
		int xcount = 0;
		int ocount = 0;
		for (size_t i = 0; i < 3; i++) {
			for (size_t j = 0; j < 3; j++) {
				if (board[i][j] == 'X') {
					xcount++;
				}
				else if (board[i][j] == 'O') {
					ocount++;
				}
			}
		}
		int xlines = line_count(board, 'X');
		int olines = line_count(board, 'O');
		// X siempre parte:
		// x gana:
		//   - hay 1 'X' mas que 'O'
		//   - hay 1 linea de 'X' y cero de 'O', o ninguna de ambas
		if (xcount == ocount + 1 and ((xlines == 1 and olines == 0) or (xlines == 0 and olines == 0))) {
			cout << "yes" << endl;
		}
		// casos en que se completan 2 filas de 'X' de una, por ejemplo, al poner la esquina superior izquierda al final en:
		// XXX
		// XOO
		// XOO
		else if (xcount == ocount + 1 and xlines >= olines + 2 and corner_count(board, 'X') != 1) {
			cout << "yes" << endl;
		}
		// o gana:
		//   - hay misma cantidad de 'X' que 'O'
		//   - hay 1 linea de 'O' y cero de 'X', o ninguna de ambas
		else if (xcount == ocount and ((olines == 1 and xlines == 0) or (olines == 0 and xlines == 0))) {
			cout << "yes" << endl;
		}
		// casos en que se completan 2 filas de 'O' de una, por ejemplo, al poner la esquina superior izquierda al final en:
		// XXX
		// XOO
		// XOO
		else if (ocount == xcount and olines >= xlines + 2 and corner_count(board, 'O') != 1) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}
	return 0;
}
