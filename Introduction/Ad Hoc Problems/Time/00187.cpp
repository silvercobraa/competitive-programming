#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

map<int, string> name;

bool is_account(string& s) {
	return not isdigit(s[3]);
}

int main(int argc, char const *argv[]) {
	string s;
	vector<pair<int, int>> v;
	int id = 0;
	while (getline(cin, s)) {
		if (is_account(s)) {
			int acc = 10*(10*(s[0]-'0')+(s[1]-'0'))+(s[2]-'0');
			name[acc] = s.substr(3, s.size()-3);
			// cout << acc << " " << name[acc] << endl;
			// cout << s.substr(3, s.size()-3) << endl;
		}
		else {
			stringstream ss(s);
			int tmp, credit;
			ss >> tmp >> credit;
			// cout << tmp << " " << credit << endl;
			int t = tmp/1000, acc = tmp%1000;
			if (t == id) {
				v.push_back({acc, credit});
			}
			else {
				int sum = 0;
				for (auto p: v) {
					sum += p.second;
				}
				if (sum != 0) {
					printf("*** Transaction %03d is out of balance ***\n", id);
					for (auto p: v) {
						printf("%03d ", p.first);
						// cout << setw(30) << name[p.first];
						cout << name[p.first];
						for (int i = name[p.first].size(); i < 30; i++) {
							cout << " ";
						}
						printf(" %10.2lf\n", double(p.second)/100);
					}
					printf("999 Out of Balance                 %10.2lf\n\n", -double(sum)/100);
				}
				else {
					// cout << id << ": balanced" << endl;
				}
				id = t;
				v.clear();
				v.push_back({acc, credit});
			}
		}
	}
	return 0;
}
