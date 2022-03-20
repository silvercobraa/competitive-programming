#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <map>

using namespace std;

string ranks {"A23456789TJQK"};
string suits {"SHDC"};

struct Card {
	string s;

	int rank() {
		switch (s[0]) {
			case 'A': return 0;
			case 'T': return 9;
			case 'J': return 10;
			case 'Q': return 11;
			case 'K': return 12;
			default: return s[0] - '1';
		}
	}
	// bool operator==(const Card& c) const {
	// 	return s[0] == c.s[0] and s[1] == c.s[1];
	// }
	bool operator<(const Card& c) const {
		if (s[0] == c.s[0]) {
			return s[1] < c.s[1];
		}
		else {
			return s[0] < c.s[0];
		}
	}
};

// return the rank where the run of count 'count' starts (-1 if no run of length 'count' found)
int check_run(const vector<int>& rank_count, int count) {
	for (int start = 0; start < ranks.size(); start++) {
		bool cond = true;
		for (int offset = 0; offset < count; offset++) {
			cond &= rank_count[(start + offset) % ranks.size()] > 0;
		}
		if (cond) return start;
	}
	return -1;
}

int get_payment(const vector<Card>& hand) {
	vector<int> rank_count(ranks.size(), 0);
	for (auto card: hand) {
		++rank_count[card.rank()];
	}
	// for (auto c: rank_count) {
	// 	cout << c << " ";
	// }
	// cout << endl;
	// check "Straight"
	if (check_run(rank_count, 5) != -1) {
		return 100;
	}
	// check "Invite-the-Neighbours"
	else if (check_run(rank_count, 4) != -1) {
		return 10;
	}
	int trio_start = check_run(rank_count, 3);
	if (trio_start != -1) {
		// for (auto c: rank_count) {
		// 	cout << c << " ";
		// }
		// cout << endl;
		for  (int offset = 0; offset < 3; offset++) {
			--rank_count[(trio_start + offset) % ranks.size()];
		}
		// for (auto c: rank_count) {
		// 	cout << c << " ";
		// }
		// cout << endl;
		// check "Bed-and-Breakfast"
		if (check_run(rank_count, 2) != -1) {
			// for (auto h: hand) {
			// 	cout << h.s << " ";
			// }
			// cout << endl;
			// for (auto rc: rank_count) {
			// 	cout << rc << " ";
			// }
			// cout << endl;
			return 5;
		}
		// Menage-a-Trois, no check needed
		else {
			return 3;
		}
	}
	int pair_start = check_run(rank_count, 2);
	if (pair_start != -1) {
		for  (int offset = 0; offset < 2; offset++) {
			--rank_count[(pair_start + offset) % ranks.size()];
		}
		// check "Double Dutch"
		if (check_run(rank_count, 2) != -1) {
			return 1;
		}
		// "Dutch", no check needed nor payment received
	}
	// Deault "Dummy", no payment received
	return 0;
}

void search(const set<Card>& all_cards, vector<Card>& hand) {
	double best_payment = get_payment(hand);
	// cout << "Stay payment: " << best_payment << endl;
	string answer = "Stay";
	set<Card> remaining_cards = all_cards;
	for (auto card: hand) {
		auto erased = remaining_cards.erase(card);
		// cout << erased << " " << remaining_cards.size() << endl;
	}
	for (int i = 0; i < hand.size(); i++) {
		Card old_card = hand[i];
		// cout << "Exchanging " << old_card.s << endl;
		// remaining_cards.insert(old_card);
		map<int, int> score_counts;
		for (auto card: remaining_cards) {
			hand[i] = card;
			// for (auto c: hand) {
			// 	cout << c.s << " ";
			// }
			// cout << endl;
			int payment = get_payment(hand);
			// cout << payment << endl;
			++score_counts[payment];
		}
		double weighted_sum = 0.0;
		for (auto p: score_counts) {
			weighted_sum += p.first * p.second;
			// printf("p(SCORE = %d) = %d/%d\n", p.first, p.second, 47);
		}
		double expected_payment = weighted_sum / 47 - 1;
		// cout << "weighted_sum: " << weighted_sum << endl;
		// cout << "expected_payment: " << expected_payment << endl;
		if (expected_payment > best_payment) {
			for (auto p: score_counts) {
				weighted_sum += p.first * p.second;
				// printf("p(SCORE = %d) = %d/%d\n", p.first, p.second, 47);
			}
			// cout << "weighted_sum: " << weighted_sum << endl;
			// cout << "expected_payment: " << expected_payment << endl;
			best_payment = expected_payment;
			answer = "Exchange " + old_card.s;
		}
		// remaining_cards.erase(old_card);
		hand[i] = old_card;
	}
	cout << answer << endl;
}


int main(int argc, char const *argv[]) {
	set<Card> all_cards;
	for (auto rank: ranks) {
		for (auto suit: suits) {
			all_cards.insert(Card{{rank, suit}});
		}
	}
	// for (auto card: all_cards) {<
	// 	cout << card.s << " " << card.rank() << endl;
	// }
	string line;
	for (getline(cin, line); line != "#"; getline(cin, line)) {
		stringstream ss(line);
		vector<Card> hand;
		string card;
		while (ss >> card) {
			hand.push_back(Card{{card}});
		}
		// for (auto c: hand) {
		// 	cout << c.s << " ";
		// }
		// cout << endl;
		search(all_cards, hand);
	}
	return 0;
}
