#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<string> deck;
// {string, bool} = {card, is_face_down}
vector<deque<pair<string,bool>>> clock_;
string card;

// 0 es el K
int rank_(string& s) {
	if (s[0] == 'A') return 1;
	else if (s[0] == 'T') return 10;
	else if (s[0] == 'J') return 11;
	else if (s[0] == 'Q') return 12;
	else if (s[0] == 'K') return 0;
	else return s[0] - '0';
}

void simulate() {
	int exposed = 0;
	int pile = 0;
	while (clock_[pile].back().second) {
		card = clock_[pile].back().first;
		clock_[pile].pop_back();
		pile = rank_(card);
		clock_[pile].push_front({card, false});
		exposed++;
	}
	printf("%02d,", exposed);
	cout << card << endl;
}

int main(int argc, char const *argv[]) {
	string card;
	for (cin >> card; card != "#"; cin >> card) {
		deck.push_back(card);
		clock_.resize(13);
		// cout << card << " " << rank_(card) << endl;
		for (size_t i = 1; i < 52; i++) {
			cin >> card;
			deck.push_back(card);
			// cout << card << " " << rank_(card) << endl;
		}
		for (int i = 1; not deck.empty(); i = (i + 1) % 13) {
			clock_[i].push_back({deck.back(), true});
			deck.pop_back();
		}
		simulate();
		clock_.clear();
	}
	return 0;
}
