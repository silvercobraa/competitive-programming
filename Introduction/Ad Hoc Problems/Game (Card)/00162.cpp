#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, int> penalty {
	{'A', 4}, {'2', 0}, {'3', 0}, {'4', 0},
	{'5', 0}, {'6', 0}, {'7', 0}, {'8', 0},
	{'9', 0}, {'T', 0}, {'J', 1}, {'Q', 2}, {'K', 3},
};

char ranko(string& card) {
	return card[1];
}

char suit(string& card) {
	return card[0];
}

int simulate(vector<string> hand[2], vector<string>& pile) {
	int player = 1;
	int pen = 0;
	while (true) {
		if (pen == 0) {
			if (hand[player].size() == 0) {
				// cerr << "player " << player << " no tiene mas cartas" << endl;
				return 1 - player;
			}
			pile.push_back(hand[player].back());
			// cerr << "player " << player << " bota " << pile.back() << endl;
			hand[player].pop_back();
			// cerr << "le quedan " << hand[player].size() << " cartas" << endl;
			pen = penalty[ranko(pile.back())];
			player = 1 - player;
		}
		else {
			int count = pen;
			bool dio_vuelta = false;
			// cerr << "penalizacion de " << pen << " cartas" << endl;
			for (int i = 0; i < count; i++) {
				if (hand[player].size() == 0) {
					// cerr << "player " << player << "no tiene mas cartas" << endl;
					return 1 - player;
				}
				pile.push_back(hand[player].back());
				// cerr << "player " << player << " bota " << pile.back() << endl;
				hand[player].pop_back();
				// cerr << "le quedan " << hand[player].size() << " cartas" << endl;
				pen = penalty[ranko(pile.back())];
				if (pen != 0) {
					// cerr << "penalizacion revertida" << endl;
					dio_vuelta = true;
					break;
				}
			}
			// si pague la penalizacion, agrego las cartas al ganador
			// si lo di vuelta, calculo el siguiente player
			if (!dio_vuelta) {
				// cerr << "player " << player << " no pudo revertir penalizacion" << endl;
				vector<string> aux;
				while (!pile.empty()) {
					aux.push_back(pile.back());
					pile.pop_back();
				}
				for (auto card: hand[1 - player]) {
					aux.push_back(card);
				}
				hand[1 - player] = aux;
			}
			player = 1 - player;
		}
	}
}

int main(int argc, char const* argv[])
{
	string card;
	for (cin >> card; card != "#"; cin >> card) {
		vector<string> deck;
		deck.push_back(card);
		for (size_t i = 1; i < 52; i++) {
			cin >> card;
			deck.push_back(card);
		}
		// 0 el dealer, 1 el non dealer
		vector<string> hand[2];
		int player = 1;
		for (auto card: deck) {
			hand[player].push_back(card);
			player = 1 - player;
		}
		vector<string> pile;
		int winner = simulate(hand, pile);
		printf("%d%3d\n", winner + 1, hand[winner].size());
		// cout << winner + 1 << " ";
		// cout << hand[winner].size() << endl;
		// cerr << "player 0:";
		// for (auto card: hand[0]) {
		// 	cerr << " " << card;
		// }
		// cerr << endl;
		// cerr << "player 1:";
		// for (auto card: hand[1]) {
		// 	cerr << " " << card;
		// }
		// cerr << endl;
		// cerr << "#" << endl;
	}
	return 0;
}
