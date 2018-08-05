#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char const* argv[])
{
	string s;
	vector<char> suits = {'S', 'H', 'D', 'C'};
	while (getline(cin, s)) {
		stringstream ss(s);
		string card;
		map<char, int> rank_count;
		map<char, int> suit_count;
		int points = 0;
		int points567 = 0;
		vector<string> aces, kings, queens, jacks;
		map<char, bool> stopped;
		while (ss >> card) {
			rank_count[card[0]]++;
			suit_count[card[1]]++;
			if (card[0] == 'A') {
				aces.push_back(card);
				stopped[card[1]] = true;
				// Each ace counts 4 points
				points += 4;
			}
			else if (card[0] == 'K') {
				kings.push_back(card);
				// Each king counts 3 points
				points += 3;
			}
			else if (card[0] == 'Q') {
				queens.push_back(card);
				// Each queen counts 2 points
				points += 2;
			}
			else if (card[0] == 'J') {
				jacks.push_back(card);
				// Each jack counts one point.
				points += 1;
			}
		}
		// Subtract a point for any king of a suit in which the hand holds no other cards.
		for (auto k: kings) {
			if (suit_count[k[1]] == 1) {
				points -= 1;
			}
			else if (suit_count[k[1]] >= 2) {
				stopped[k[1]] = true;
			}
		}
		// Subtract a point for any queen in a suit in which the hand holds only zero or one other cards.
		for (auto q: queens) {
			if (suit_count[q[1]] == 1 or suit_count[q[1]] == 2) {
				points -= 1;
			}
			else if (suit_count[q[1]] >= 3) {
				stopped[q[1]] = true;
			}
		}
		// Subtract a point for any jack in a suit in which the hand holds only zero, one, or two other cards.
		for (auto j: jacks) {
			if (suit_count[j[1]] == 1 or suit_count[j[1]] == 2 or suit_count[j[1]] == 3) {
				points -= 1;
			}
		}
		for (auto suit: suits) {
			if (suit_count[suit] == 2) {
				points567 += 1;
			}
			else if (suit_count[suit] == 1) {
				points567 += 2;
			}
			else if (suit_count[suit] == 0) {
				points567 += 2;
			}
		}
		// cout << points << " " << points567 << endl;
		if (points >= 16 and stopped.size() == 4) {
			cout << "BID NO-TRUMP" << endl;
		}
		else if (points + points567 >= 14) {
			char bid = suits[0];
			int size = -1;
			for (auto suit: suits) {
				if (suit_count[suit] > size) {
					size = suit_count[suit];
					bid = suit;
				}
			}
			if (size > 0) {
				cout << "BID " << bid << endl;
			}
			else {
				cout << "PASS" << endl;
			}
		}
		else {
			cout << "PASS" << endl;
		}
	}
	return 0;
}
