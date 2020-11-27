// César Bolívar Severino
// resuelto propio
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	while (scanf("%d", &n) != EOF) {
		int A[n];
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &A[i]);
		}
		string jollyness = "Jolly";
		if (n == 1) {
			cout << "Jolly" << endl;
			continue;
		}
		vector<bool> v(n - 1);
		v[0] = true;
		fill(v.begin(), v.end(), false);
		for (int j = 0; j < n - 1; j++)
		{
			int abs_ = abs(A[j] - A[j+1]);
			if (abs_ >= n || abs_ <= 0) {
				jollyness = "Not jolly";
				break;
			}
			else {
				v[abs_ - 1] = true;
			}
		}
		for (auto it = v.begin(); it != v.end(); it++)
		{
			if (!*it) {
				jollyness = "Not jolly";
				break;
			}
		}
		cout << jollyness << endl;
	}
	return 0;
}
