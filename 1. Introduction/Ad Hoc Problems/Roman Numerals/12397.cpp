#include <iostream>
#include <vector>

using namespace std;

int I=1, V=2, X=2, L=2, C=2, D=3, M=4;

vector<vector<int>> values = {
	{0, I, 2*I, 3*I, I+V, V, V+I, V+I+I, V+I+I+I, I+X}, // unidad
	{0, X, 2*X, 3*X, X+L, L, L+X, L+X+X, L+X+X+X, X+C}, // decena
	{0, C, 2*C, 3*C, C+D, D, D+C, D+C+C, D+C+C+C, C+M}, // centena
	{0, M, 2*M, 3*M}, // unidad de mil
};

int main(int argc, char const *argv[]) {
	int n;
	while (cin >> n) {
		int ans = 0;
		for (int digit = 0; n > 0; digit++, n/=10) {
			ans += values[digit][n % 10];
		}
		cout << ans << endl;
	}
	return 0;
}
