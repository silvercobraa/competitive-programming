#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	vector<int> value(256, 0);
	value['B'] = 1;
	value['U'] = 10;
	value['S'] = 100;
	value['P'] = 1000;
	value['F'] = 10000;
	value['T'] = 100000;
	value['M'] = 1000000;
	value['D'] = 10000000; // dummy at the end

	int m;
	cin >> m;

	for (size_t t = 0; t < m; t++) {

		string s;
		cin >> s;
		s += 'D';

		bool error = false;
		char prev = '\0';
		int count = 0;
		int ans = 0;

		bool big_endian = false;
		bool little_endian = false;
		for (auto c: s) {
			// cout << c << " " << value[c] << endl;
			if (c == prev) {
				count++;
				if (count > 9) {
					error = true;
					break;
				}
			}
			else {
				if (prev != '\0' and c != 'D') {
					big_endian |= value[prev] > value[c];
					little_endian |= value[prev] < value[c];
					if (big_endian and little_endian) {
						error = true;
						break;
					}
				}
				ans += value[prev] * count;
				count = 1;
			}
			prev = c;
		}
		if (error) {
			cout << "error" << endl;
		}
		else {
			cout << ans << endl;
		}
		// cout << endl;
	}
	return 0;
}
