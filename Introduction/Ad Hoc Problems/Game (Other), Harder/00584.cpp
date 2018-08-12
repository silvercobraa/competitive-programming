#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[]) {
	string s;
	for (getline(cin, s); s != "Game Over"; getline(cin, s)) {
		stringstream ss(s);
		char c;
		vector<char> frame;
		while (ss >> c) {
			frame.push_back(c);
			// cout << c << " ";
		}
		// cout << endl;
		vector<int> score(frame.size(), 0);
		for (int i = 0; i < frame.size(); i++) {
			if (frame[i] == 'X') {
				score[i] = 10;
			}
			else if (frame[i] == '/') {
				score[i] = 10;
			}
			else {
				score[i] = frame[i] - '0';
			}
		}
		// for (auto x: score) {
		// 	cout << x << " ";
		// }
		// cout << endl;
		bool first = true;
		int sum = 0;
		int count = 0;
		for (int i = 0; i < frame.size() and count < 10; i++) {
			// cout << count << endl;
			if (first) {
				if (frame[i] == 'X') {
					sum += score[i];
					if (count < 10) {
						if (frame[i + 2] == '/') {
							sum += score[i + 2];
							// cout << "strike: " << score[i] << " + " << score[i + 2] << endl;
						}
						else {
							sum += score[i + 1] + score[i + 2];
							// cout << "strike: " << score[i] << " + " << score[i + 1] << " + " << score[i + 2] << endl;
						}
					}
					count++;
				}
				else {
					first = false;
				}
			}
			else {
				sum += score[i];
				if (frame[i] == '/') {
					if (count < 10) {
						sum += score[i + 1];
						// cout << "spare: " << score[i] << " + " << score[i + 1] << endl;
					}
				}
				else {
					if (count < 10) {
						// cout << "normal: " << score[i] << " + " << score[i - 1] << endl;
						sum += score[i - 1];
					}
					else {
						sum += score[i];
					}
				}
				first = true;
				count++;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
