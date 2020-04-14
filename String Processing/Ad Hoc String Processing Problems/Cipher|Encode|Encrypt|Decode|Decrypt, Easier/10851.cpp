#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int N;
	cin >> N;
	for (size_t i = 0; i < N; i++) {
		vector<string> M(10);
		for (size_t j = 0; j < 10; j++) {
			cin >> M[j];
			// cout << M[j] << endl;
		}
		for (int j = 1; j < M[0].size() - 1; j++) {
			int ascii = 0;
			for (int k = 9; k >= 1; k--) {
				ascii *= 2;
				ascii += M[k][j] == '/' ? 0 : 1;
			}
			cout << char(ascii);
		}
		cout << endl;
	}
	return 0;
}
