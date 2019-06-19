// César Bolívar Severino
// resuelto propio
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, n;
	cin >> N;
	cin >> n;
	// cout << N << " " << n << endl;
	string s;
	while (N != 0 || n != 0) {
		getline(cin, s);
		// cout << s << endl;
		vector<string> big_square;
		vector<string> small_square;
		for (int i = 0; i < N; i++)
		{
			getline(cin, s);
			big_square.push_back(s);
			// cout << s << endl;
		}
		for (int i = 0; i < n; i++)
		{
			getline(cin, s);
			small_square.push_back(s);
			// cout << s << endl;
		}

		int rot[4] = {0, 0, 0, 0};
		for (int Nvi = 0; Nvi < N - n + 1; Nvi++)
		{
			for (int Nhi = 0; Nhi < N - n + 1; Nhi++)
			{
				int equal[4] = {1, 1, 1, 1};
				for (int nvi = 0; nvi < n; nvi++)
				{
					for (int nhi = 0; nhi < n; nhi++)
					{
						if (big_square[Nvi + nvi][Nhi + nhi] != small_square[nvi][nhi]) {
							equal[0] = 0;
							// cout << "Nhi: " <<  Nhi << ", nhi: " << nhi << endl;
							// cout << "big_sqare[Nvi + nvi][Nhi + nhi]: " <<  big_square[Nvi + nvi][Nhi + nhi] << ", small_sqare[nvi][nhi]: " << small_square[nvi][nhi] << endl;
						}
						if (big_square[Nvi + nvi][Nhi + nhi] != small_square[nhi][n - nvi - 1]) {
							equal[3] = 0;
						}
						if (big_square[Nvi + nvi][Nhi + nhi] != small_square[n - nvi - 1][n - nhi - 1]) {
							equal[2] = 0;
						}
						if (big_square[Nvi + nvi][Nhi + nhi] != small_square[n - nhi - 1][nvi]) {
							equal[1] = 0;
						}
					}
				}
				for (int i = 0; i < 4; i++)
				{
					rot[i] += equal[i];
					//cout << rot[i] << " ";
				}
				// cout << endl;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			cout << rot[i] << " ";
		}
		cout << rot[3] << endl;
		cin >> N;
		cin >> n;
		// cout << N << " " << n << endl;
	}
	return 0;
}
