#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

map<char, int> value = {
	{'2', 0},
	{'3', 1},
	{'4', 2},
	{'5', 3},
	{'6', 4},
	{'7', 5},
	{'8', 6},
	{'9', 7},
	{'T', 8},
	{'J', 9},
	{'Q', 10},
	{'K', 11},
	{'A', 12},
};

char suit(string& s) {
	return s[1];
}

int rank_(const string& s) {
	return value[s[0]];
}

bool compare(const string& s1, const string& s2) {
	return rank_(s1) < rank_(s2);
}

// todas estas funciones asumen la mano ordenada por rango
int straight_flush(vector<string>& hand) {
	char sui = suit(hand[0]);
	int val = rank_(hand[0]);
	for (size_t i = 1; i < 5; i++) {
		if (suit(hand[i]) != sui or val + 1 != rank_(hand[i])) {
			return -1;
		}
		val++;
	}
	return rank_(hand[4]);
}

int four_of_a_kind(vector<string>& hand) {
	if (rank_(hand[0]) == rank_(hand[3])) {
		return rank_(hand[3]);
	} else if (rank_(hand[1]) == rank_(hand[4])) {
		return rank_(hand[4]);
	}
	else {
		return -1;
	}
}

int full_house(vector<string>& hand) {
	bool cond1 = rank_(hand[0]) == rank_(hand[1]);
	bool cond2 = rank_(hand[3]) == rank_(hand[4]);
	if (!cond1 or !cond2) {
		return -1;
	}
	bool cond3 = rank_(hand[1]) == rank_(hand[2]);
	bool cond4 = rank_(hand[2]) == rank_(hand[3]);
	if (cond3 or cond4) {
		return rank_(hand[2]);
	}
	else {
		return -1;
	}
}

int flush(vector<string>& hand) {
	char sui = suit(hand[0]);
	for (int i = 1; i < 5; i++) {
		if (suit(hand[i]) != sui) {
			return -1;
		}
	}
	return 1;
}

int straight(vector<string>& hand) {
	int val = rank_(hand[0]);
	for (int i = 1; i < 5; i++) {
		if (val + 1 != rank_(hand[i])) {
			return -1;
		}
		val++;
	}
	return rank_(hand[4]);
}

int three_of_a_kind(vector<string>& hand) {
	bool cond1 = rank_(hand[0]) == rank_(hand[2]);
	bool cond2 = rank_(hand[1]) == rank_(hand[3]);
	bool cond3 = rank_(hand[2]) == rank_(hand[4]);
	if (cond1 or cond2 or cond3) {
		return rank_(hand[2]);
	}
	else {
		return -1;
	}
}

vector<int> two_pairs(vector<string>& hand) {
	bool cond1 = rank_(hand[0]) == rank_(hand[1]);
	bool cond2 = rank_(hand[1]) == rank_(hand[2]);
	bool cond3 = rank_(hand[2]) == rank_(hand[3]);
	bool cond4 = rank_(hand[3]) == rank_(hand[4]);
	if (cond1 and cond3) {
		return {rank_(hand[2]), rank_(hand[0]), rank_(hand[4])};
	}
	else if (cond1 and cond4) {
		return {rank_(hand[3]), rank_(hand[0]), rank_(hand[2])};
	}
	else if (cond2 and cond4) {
		return {rank_(hand[3]), rank_(hand[1]), rank_(hand[0])};
	}
	return {};
}

bool tie(int black, int white) {
	if (black > white) {
		puts("Black wins.");
		return false;
	}
	else if (black < white) {
		puts("White wins.");
		return false;
	}
	return true;
}

bool tie(vector<int>& v1, vector<int>& v2) {
	if (v1.size() > v2.size()) {
		puts("Black wins.");
		return false;
	}
	else if (v1.size() < v2.size()) {
		puts("White wins.");
		return false;
	}
	for (size_t i = 0; i < v1.size(); i++) {
		if (v1[i] > v2[i]) {
			puts("Black wins.");
			return false;
		}
		else if (v1[i] < v2[i]) {
			puts("White wins.");
			return false;
		}
	}
	return true;

}

vector<int> pair_(vector<string>& hand) {
	vector<int> ranks = {
		rank_(hand[0]), rank_(hand[1]), rank_(hand[2]), rank_(hand[3]), rank_(hand[4])
	};
	if (ranks[4] == ranks[3]) {
		ranks = {ranks[4], ranks[2], ranks[1], ranks[0]};
	}
	else if (ranks[3] == ranks[2]) {
		ranks = {ranks[2], ranks[4], ranks[1], ranks[0]};
	}
	else if (ranks[2] == ranks[1]) {
		ranks = {ranks[1], ranks[4], ranks[3], ranks[0]};
	}
	else if (ranks[1] == ranks[0]) {
		ranks = {ranks[0], ranks[4], ranks[3], ranks[2]};
	}
	else {
		ranks = {};
	}
	return ranks;
}

bool high_card(vector<string>& hand1, vector<string>& hand2) {
	for (int i = int(hand1.size()) - 1; i >= 0; i--) {
		if (rank_(hand1[i]) > rank_(hand2[i])) {
			puts("Black wins.");
			return false;
		}
		else if (rank_(hand1[i]) < rank_(hand2[i])) {
			puts("White wins.");
			return false;
		}
	}
	puts("Tie.");
	return true;
}

void play(vector<string>& hand1, vector<string>& hand2) {
	int black = straight_flush(hand1);
	int white = straight_flush(hand2);
	if (!tie(black, white)) {
		return;
	}
	black = four_of_a_kind(hand1);
	white = four_of_a_kind(hand2);
	if (!tie(black, white)) {
		return;
	}
	black = full_house(hand1);
	white = full_house(hand2);
	if (!tie(black, white)) {
		return;
	}
	black = flush(hand1);
	white = flush(hand2);
	if (!tie(black, white)) {
		return;
	}
	// ambos tienen flush
	if (black != -1) {
		high_card(hand1, hand2);
		return;
	}
	// ninguno tiene flush
	black = straight(hand1);
	white = straight(hand2);
	if (!tie(black, white)) {
		return;
	}
	black = three_of_a_kind(hand1);
	white = three_of_a_kind(hand2);
	if (!tie(black, white)) {
		return;
	}
	vector<int> vblack = two_pairs(hand1);
	vector<int> vwhite = two_pairs(hand2);
	if (!tie(vblack, vwhite)) {
		return;
	}
	vblack = pair_(hand1);
	vwhite = pair_(hand2);
	if (!tie(vblack, vwhite)) {
		return;
	}
	high_card(hand1, hand2);
}

int main(int argc, char const *argv[]) {
	string line;

	while (getline(cin, line)) {
		stringstream ss(line);
		vector<string> hand1(5);
		vector<string> hand2(5);
		for (int i = 0; i < 5; i++) {
			ss >> hand1[i];
		}
		for (int i = 0; i < 5; i++) {
			ss >> hand2[i];
		}
		sort(hand1.begin(), hand1.end(), compare);
		sort(hand2.begin(), hand2.end(), compare);
		play(hand1, hand2);
	}
	return 0;
}
