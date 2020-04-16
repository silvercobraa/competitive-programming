#include <iostream>
#include <vector>

using namespace std;

int iterations = 0;
int count = 0;
vector<vector<int>> pegs;

void print() {
	for (int i = 0; i < 3; i++) {
		cout << char('A' + i) << "=>";
		if (not pegs[i].empty()) {
			cout << "  ";
		}
		for (auto x: pegs[i]) {
			cout << " " << x;
		}
		cout << endl;
	}
	cout << endl;
}

void hanoi(int n, int source, int dest) {
	if (n == 0) {
		return;
	}
	int other = 3 - (source + dest);
 	hanoi(n-1, source, other);
	pegs[dest].push_back(pegs[source].back());
	pegs[source].pop_back();
	count++;
	if (count > iterations) {
		return;
	}
	print();
 	hanoi(n-1, other, dest);
}

int main(int argc, char const *argv[]) {
	int n, m;
	int problem = 1;
	for (cin >> n >> m; n != 0 or m != 0; cin >> n >> m) {
		cout << "Problem #" << problem << endl << endl;
		iterations = m;
		count = 0;
		pegs = vector<vector<int>>(3);
		for (int i = n; i > 0; i--) {
			pegs[0].push_back(i);
		}
		print();
		hanoi(n, 0, 2);
		problem++;
	}
	return 0;
}
