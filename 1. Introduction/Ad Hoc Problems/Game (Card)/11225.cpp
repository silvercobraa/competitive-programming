#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (size_t t = 0; t < T; t++) {
		if (t != 0) {
			puts("");
		}
		int M;
		cin >> M;
		int needed = 0;
		int got = 0;
		int oudlers = 0;
		string s;
		getline(cin, s);
		for (size_t i = 0; i < M; i++) {
			getline(cin, s);
			if (s == "fool" or s == "one of trumps" or s == "twenty-one of trumps") {
				oudlers++;
				got += 9;
			}
			else {
				stringstream ss (s);
				string rank_;
				ss >> rank_;
				if (rank_ == "king") {
					got += 9;
				}
				else if (rank_ == "queen") {
					got += 7;
				}
				else if (rank_ == "knight") {
					got += 5;
				}
				else if (rank_ == "jack") {
					got += 3;
				}
				else {
					got += 1;
				}
			}
		}
		if (oudlers == 3) {
			needed = 36;
		}
		else if (oudlers == 2) {
			needed = 41;
		}
		else if (oudlers == 1) {
			needed = 51;
		}
		else {
			needed = 56;
		}
		got /= 2;
		// cout << needed << " " << got << endl;
		cout << "Hand #" << t + 1 << endl;
		if (got >= needed) {
			cout << "Game won by " << got - needed << " point(s)." << endl;
		}
		else {
			cout << "Game lost by " << needed - got << " point(s)." << endl;
		}
	}

	return 0;
}
