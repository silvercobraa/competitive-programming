#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;

int main(int argc, char const *argv[]) {
	string str1, str2;
	while (getline(cin, str1)) {
		getline(cin, str2);
		set<int> set1, set2;
		stringstream ss1(str1);
		stringstream ss2(str2);
		int x;
		while (ss1 >> x) {
			set1.insert(x);
		}
		while (ss2 >> x) {
			set2.insert(x);
		}
		set<int> inter;
		set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(inter, inter.begin()));
		if (inter.empty()) {
			puts("A and B are disjoint");
		}
		else if (inter == set1) {
			if (inter == set2) {
				puts("A equals B");
			}
			else {
				puts("A is a proper subset of B");
			}
		}
		else {
			if (inter == set2) {
				puts("B is a proper subset of A");
			}
			else {
				puts("I'm confused!");
			}
		}
	}
	return 0;
}
