#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

void get_king_moves(set<int>& kmoves, int k, int q1) {
	int row = k / 8;
	int col = k % 8;
	if (row != 0 and 8*(row - 1) + col != q1) {
		kmoves.insert(8*(row - 1) + col);
	}
	if (col != 0 and 8*(row) + col - 1 != q1) {
		kmoves.insert(8*(row) + col - 1);
	}
	if (row != 7 and 8*(row + 1) + col != q1) {
		kmoves.insert(8*(row + 1) + col);
	}
	if (col != 7 and 8*(row) + col + 1 != q1) {
		kmoves.insert(8*(row) + col + 1);
	}
	// cout << "K:";
	// for (auto x: kmoves) {
	// 	cout << " " << x;
	// }
	// cout << endl;
}

void get_queen_moves(set<int>& qmoves, int q1, int k) {
	int row = q1 / 8;
	int col = q1 % 8;
	for (int i = row + 1; i < 8; i++) {
		if (8*i + col == k) {
			break;
		}
		qmoves.insert(8*i + col);
	}
	for (int i = row - 1; i >= 0; i--) {
		if (8*i + col == k) {
			break;
		}
		qmoves.insert(8*i + col);
	}
	for (int j = col + 1; j < 8; j++) {
		if (8*row + j == k) {
			break;
		}
		qmoves.insert(8*row + j);
	}
	for (int j = col - 1; j >= 0; j--) {
		if (8*row + j == k) {
			break;
		}
		qmoves.insert(8*row + j);
	}
	// cout << "Q:";
	// for (auto x: qmoves) {
	// 	cout << " " << x;
	// }
	// cout << endl;
}

int main(int argc, char const *argv[]) {
	int k, q1, q2;
	while (cin >> k >> q1 >> q2) {
		if (k == q1) {
			cout << "Illegal state" << endl;
			continue;
		}
		set<int> kmoves;
		set<int> qmoves;
		get_king_moves(kmoves, k, q1);
		get_queen_moves(qmoves, q1, k);

		if (qmoves.find(q2) == qmoves.end()) {
			cout << "Illegal move" << endl;
			continue;
		}
		if (kmoves.find(q2) != kmoves.end()) {
			cout << "Move not allowed" << endl;
			continue;
		}
		else {
			kmoves.clear();
			qmoves.clear();
			get_king_moves(kmoves, k, q2);
			get_queen_moves(qmoves, q2, k);
			set<int> diff;
			set_difference(kmoves.begin(), kmoves.end(),
				qmoves.begin(), qmoves.end(),
				inserter(diff, diff.begin())
			);
			if (diff.size() == 0) {
				cout << "Stop" << endl;
			}
			else {
				cout << "Continue" << endl;
			}
		}
	}
	return 0;
}
