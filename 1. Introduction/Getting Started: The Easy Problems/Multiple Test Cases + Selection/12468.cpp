#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int a, b;
	for (cin >> a >> b; a != -1 or b != -1; cin >> a >> b) {
		cout << min((b + 100 - a) % 100, (a + 100 - b) % 100) << endl;
	}
	return 0;
}
