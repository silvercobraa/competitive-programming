#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	int allowed = 0;
	for (size_t i = 0; i < n; i++) {
		double length, width, depth, weight;
		cin >> length >> width >> depth >> weight;
		bool cond1 = length <= 56.0 and width <= 45.0 and depth <= 25.0;
		bool cond2 = length + width + depth <= 125.0;
		bool cond3 = weight <= 7.0;
		bool ans = (cond1 or cond2) and cond3;
		cout << int(ans) << endl;
		allowed += ans;
	}
	cout << allowed << endl;
	return 0;
}
