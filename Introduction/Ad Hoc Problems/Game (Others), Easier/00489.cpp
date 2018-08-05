#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
	int n;
	for (cin >> n; n != -1; cin >> n) {
		string solution;
		string guess;
		cin >> solution >> guess;
		string progress = solution;
		set<char> wrong;
		int count = 0;
		for (auto c: guess) {
			bool found = false;
			for (int i = 0; i < solution.size(); i++) {
				if (c == solution[i]) {
					found = true;
					if (progress[i] != '\0') {
						count++;
					}
					progress[i] = '\0';
				}
			}
			// asi como checkeaba el lose temprano, debia checkear el win temprano también
			if (count == solution.size()) {
				break;
			}
			if (not found) {
				wrong.insert(c);
			}
			if (wrong.size() == 7) {
				break;
			}
		}
		cout << "Round " << n << endl;
		if (wrong.size() == 7) {
			cout << "You lose." << endl;
		}
		else if (count == solution.size()) {
			cout << "You win." << endl;
		}
		else {
			cout << "You chickened out." << endl;
		}

	}
	return 0;
}
