// NO OLVIDAR EL SORT ANTES DE NEXT PERMUTATION!!
#include <iostream>
#include <algorithm>
#include <vector>

#define UNDEF 99999

using namespace std;

int asd(vector<int> v1, vector<int> v2) {
	int pos;
	for (size_t i = 0; i < 3; i++) {
		if (v2[i] == UNDEF) {
			pos = i;
		}
	}
	int wins = 0;
	if (v2[(pos + 1) % 3] > v1[(pos + 1) % 3]) {
		wins++;
	}
	if (v2[(pos + 2) % 3] > v1[(pos + 2) % 3]) {
		wins++;
	}
	// cualquier carta sirve, tirar la menor
	if (wins == 2) {
		v2[pos] = 1;
		// revisamos si esta tomada
		for (size_t i = 0; i < 4; i++) {
			if (v1[(pos + 1) % 3] == v2[pos] or v1[(pos + 2) % 3] == v2[pos] or v2[(pos + 1) % 3] == v2[pos] or v2[(pos + 2) % 3] == v2[pos]) {
				v2[pos]++;
			}
			else {
				break;
			}
		}
		return v2[pos];
	}
	// ninguna le sirve para ganar
	else if (wins == 0) {
		return -1;
	}
	// en este caso, debemos escoger cuidadosamente la menor que nos haga ganar
	v2[pos] = v1[pos] + 1;
	// si ya esta tomada, usamos la siguiente mayor. revisamos 5 veces porque podrian ser
	for (size_t i = 0; i < 4; i++) {
		if (v1[(pos + 1) % 3] == v2[pos] or v1[(pos + 2) % 3] == v2[pos] or v2[(pos + 1) % 3] == v2[pos] or v2[(pos + 2) % 3] == v2[pos]) {
			v2[pos]++;
		}
		else {
			break;
		}
	}
	// si nos pasamos del maximo permitido, no hay manera de ganar
	if (v2[pos] > 52) {
		return -1;
	}
	else {
		return v2[pos];
	}
}

int main(int argc, char const *argv[]) {
	int a, b, c, x, y;
	for (cin>>a>>b>>c>>x>>y; a!=0 or b!=0 or c!=0 or x!=0 or y!=0; cin>>a>>b>>c>>x>>y) {
		vector<int> princess = {a, b, c};
		vector<int> prince = {x, y, UNDEF};
		vector<int> answers;
		sort(prince.begin(), prince.end());
		bool win = true;
		do {
			int ans = asd(princess, prince);
			if (ans == -1) {
				// no hay manera de ganar una permutacion particular
				// por lo tanto no hay manera de ganar
				win = false;
				break;
			}
			else {
				answers.push_back(ans);
			}
		} while(next_permutation(prince.begin(), prince.end()));
		if (win) {
			int max = answers[0];
			for (size_t i = 0; i < answers.size(); i++) {
				max = std::max(max, answers[i]);
			}
			cout << max << endl;
		}
		else {
			cout << "-1" << endl;
		}
	}

	return 0;
}
