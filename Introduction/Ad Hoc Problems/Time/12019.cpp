#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	// el 1 de enero de 2011 cae sabado, me evito un offset al ponerlo como el cero
	vector<string> name = {"Satur", "Sun", "Mon", "Tues", "Wednes", "Thurs", "Fri"};
	// offset en dias del mes i a partir del 1 de enero de 2011
	vector<int> offset = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
	for (int i = 1; i < 12; i++) {
		offset[i] += offset[i - 1];
	}
	for (size_t i = 0; i < n; i++) {
		int m, d;
		cin >> m >> d;
		m--; d--;
		cout << name[(offset[m] + d) % 7] << "day" << endl;
	}
	return 0;
}
