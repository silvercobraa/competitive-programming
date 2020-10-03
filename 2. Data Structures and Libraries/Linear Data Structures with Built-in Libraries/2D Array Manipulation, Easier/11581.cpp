// César Bolívar Severino
// resuelto propio
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

// obtengo el n-ésimo bit de B (0 el menos significativo)
int bit(int B, int n)
{
	return (B >> n) & 1;
}

// YOLO
int f(int g) {
	// for (int i = 0; i < 9; i++)
	// {
	// 	cout << "bit(g, i): " << bit(g, i) << endl;
	// }
	int b8 = (bit(g, 7) ^ bit(g, 5)) << 8;
	int b7 = (bit(g, 8) ^ bit(g, 6) ^ bit(g, 4)) << 7;
	int b6 = (bit(g, 7) ^ bit(g, 3)) << 6;
	int b5 = (bit(g, 8) ^ bit(g, 4) ^ bit(g, 2)) << 5;
	int b4 = (bit(g, 7) ^ bit(g, 5) ^ bit(g, 3) ^ bit(g, 1)) << 4;
	int b3 = (bit(g, 6) ^ bit(g, 4) ^ bit(g, 0)) << 3;
	int b2 = (bit(g, 5) ^ bit(g, 1)) << 2;
	int b1 = (bit(g, 4) ^ bit(g, 2) ^ bit(g, 0)) << 1;
	int b0 = bit(g, 3) ^ bit(g, 1);
	// cout << "b8: " << b8 << endl;
	// cout << "b7: " << b7 << endl;
	// cout << "b6: " << b6 << endl;
	// cout << "b5: " << b5 << endl;
	// cout << "b4: " << b4 << endl;
	// cout << "b3: " << b3 << endl;
	// cout << "b2: " << b2 << endl;
	// cout << "b1: " << b1 << endl;
	// cout << "b0: " << b0 << endl;
	return b8 | b7 | b6 | b5 | b4 | b3 | b2 | b1 | b0;
}

int main(int argc, char const* argv[])
{
	int n;
	cin >> n;
	char c;
	for (int i = 0; i < n; i++)
	{
		int g = 0;
		for (int j = 0; j < 9; j++)
		{
			// cin >> v[j];
			cin >> c;
			g = (g << 1) | (c - '0');
		}
		int k = -1;
		while (g != 0) {
			g = f(g);
			// cout << "g: " << g << endl;
			k++;
		}
		// printf("%x\n", g);
		cout << k << endl;
	}
	return 0;
}
