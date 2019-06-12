#include <iostream>

using namespace std;

void print(string& s) {
	while (s.back() == ' ') {
		s.pop_back();
	}
	int start = s.find_first_not_of(" ");
	for (int i = start; i < s.size(); i++) {
		cout << s[i];
	}
}

int main(int argc, char const *argv[]) {
	string line;
	while (getline(cin, line)) {
	// while (cin >> line) {
		string isbn = "";
		int i;
		for (i = 0; i < line.size(); i++) {
			if (isdigit(line[i])) {
				isbn.push_back(line[i]);
				if (isbn.size() == 9) {
					i++;
					break;
				}
			}
		}
		for ( ; i < line.size(); i++) {
			if (isdigit(line[i]) or line[i] == 'X') {
				isbn.push_back(line[i]);
			}
		}
		if (isbn.size() != 10) {
			print(line);
			cout << " is incorrect." << endl;
			continue;
		}
		int sum = 0;
		int s2 = 0;
		for (i = 0; i < 9; i++) {
			sum += isbn[i] - '0';
			s2 += sum;
		}
		if (isbn[9] == 'X') {
			sum += 10;
		}
		else {
			sum += isbn[9] - '0';
		}
		s2 += sum;
		if (s2 % 11 == 0) {
			print(line);
			cout << " is correct." << endl;
		}
		else {
			print(line);
			cout << " is incorrect." << endl;
		}
	}
	return 0;
}
