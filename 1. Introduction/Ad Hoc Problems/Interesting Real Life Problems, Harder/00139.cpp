#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {
	string s;
	map<string, string> areas;
	map<string, int> cents;
	for (cin >> s; s != "000000"; cin >> s) {
		string areacents;
		// cin >> areacents;
		getline(cin, areacents, ' ');
		getline(cin, areacents);
		stringstream ss(areacents);
		string area;
		int price;
		getline(ss, area, '$');
		ss >> price;
		areas[s] = area;
		cents[s] = price;
	}
	for (cin >> s; s != "#"; cin >> s) {
		int mins;
		cin >> mins;
		cout << s;
		for (int i = s.size(); i < 16; i++) {
			cout << " ";
		}
		if (s[0] != '0') {
			cout << "Local";
			cout << setw(30) << s;
			cout << setw(5) << mins;
			printf("%6.2lf%7.2lf\n", 0.00, 0.00);
			continue;
		}
		// bool match = false;
		int len = 99999999;
		// int len = 0;
		string smatch = "";
		for (auto p: areas) {
			auto pos = s.find(p.first);
			// if (s.find(p.first) != string::npos) {
			if (s.find(p.first) == 0) {
				// if (s.size() - p.first.size() > len) {
				// if (p.first.size() > len and int(s.size())-int(p.first.size()) < 7) {
				// if (p.first.size() > len) {
				// if (p.first.size() > len) {
				int sublen = int(s.size())-int(p.first.size());
				// AYY LMAO
				if (p.first.size() < s.size() and p.first.size() < len and not (s[0] == '0' and s[1] != '0' and (sublen < 4 or sublen > 7))
				and not (s[1] == '0' and (sublen < 4 or sublen > 10))) {
				// if (p.first.size() < len) {
					// len = s.size() - p.first.size();
					len = p.first.size();
					// cout << "len:" << len << " ";
					smatch = p.first;
				}
				// match = true;
				// cout << p.second;
				// int size = p.first.size();
				// cout << setw(35-p.second.size()) << s.substr(size, s.size()-size);
				// cout << setw(5) << mins;
				// printf("%6.2lf", cents[p.first]/100.0);
				// printf("%7.2lf", mins*cents[p.first]/100.0);
				// break;
			}
		}
		// if (not match) {
		// if (len > 0) {
		if (len != 99999999) {
			cout << areas[smatch];
			int size = smatch.size();
			cout << setw(35-areas[smatch].size()) << s.substr(size, s.size()-size);
			cout << setw(5) << mins;
			printf("%6.2lf", cents[smatch]/100.0);
			printf("%7.2lf", mins*cents[smatch]/100.0);
		}
		else {
			cout << "Unknown";
			for (int i = 7; i < 25+10; i++) {
				cout << " ";
			}
			cout << setw(5) << mins;
			printf("%13.2lf", -1.00);
		}
		cout << endl;
	}
	return 0;
}
