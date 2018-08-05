// NO USAR <numeric> !!! La caga de juez de la uva da Compilation Error
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
// #include <numeric>

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		if (t != 0) {
			cout << endl;
		}
		int n;
		cin >> n;
		vector<vector<int>> shuffles(n, vector<int>(52));
		for (size_t i = 0; i < n; i++) {
			for (size_t j = 0; j < 52; j++) {
				cin >> shuffles[i][j];
				// cout << shuffles[i][j] << " ";
				shuffles[i][j]--;
			}
			// cout << endl;
		}
		// cout << s << endl;
		vector<int> hand(52);
		vector<int> aux(52);
		for (size_t i = 0; i < 52; i++) {
			hand[i] = i;
		}

		string s;
		getline(cin, s);
		for (getline(cin, s); s != ""; getline(cin, s)) {
			int k = stoi(s);
			k--;
			// cout << k << endl;
			for (size_t j = 0; j < 52; j++) {
				aux[j] = hand[shuffles[k][j]];
				// aux[shuffles[k][j]] = hand[j];
			}
			hand = aux;
			/* code */
		}
		for (size_t i = 0; i < 52; i++) {
			// cout << hand[i] << endl;
			int card = hand[i];
			int rank = card % 13;
			int suit = card / 13;
			if (rank == 9) cout << "Jack";
			else if (rank == 10) cout << "Queen";
			else if (rank == 11) cout << "King";
			else if (rank == 12) cout << "Ace";
			else cout << rank + 2;
			cout << " of ";
			if (suit == 0) cout << "Clubs";
			else if (suit == 1) cout << "Diamonds";
			else if (suit == 2) cout << "Hearts";
			else if (suit == 3) cout << "Spades";
			cout << endl;
		}
	}
	return 0;
}
