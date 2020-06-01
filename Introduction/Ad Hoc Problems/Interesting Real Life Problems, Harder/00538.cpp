#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {
	int n, t, case_ = 1;
	for (cin >> n >> t; n != 0 or t != 0; cin >> n >> t) {
		cout << "Case #" << case_ << endl;
		vector<string> name(n);
		vector<int> debt(n, 0);
		map<string, int> idx;
		for (int i = 0; i < n; i++) {
			cin >> name[i];
			idx[name[i]] = i;
		}
		for (int i = 0; i < t; i++) {
			string s1, s2;
			int money;
			cin >> s1 >> s2 >> money;
			int idx1 = idx[s1];
			int idx2 = idx[s2];
			debt[idx1] -= money;
			debt[idx2] += money;

		}
		// El con mayor deuda siempre le va a pagar toda su deuda al que le falte mas plata,
		// de esa forma siempre se esta balanceando 1 persona por iteración.
		// El ciclo termina cuando ya no quedan mas deudas por saldar.
		while (true) {
			int maxi = 0;
			int mini = 0;
			int payer = -1, payee = -1;
			for (size_t i = 0; i < n; i++) {
				if (debt[i] > maxi) {
					maxi = debt[i];
					payer = i;
				}
				if (debt[i] < mini) {
					mini = debt[i];
					payee = i;
				}
			}
			if (maxi == 0) {
				break;
			}
			int amount = debt[payer];
			if (debt[payer] < 0) {
				// puts("ERRROOOORRRR!!!!");
			}
			debt[payee] += amount;
			debt[payer] = 0;
			cout << name[payer] << " " << name[payee] << " " << amount << endl;
		}
		case_++;
		cout << endl;
	}
	return 0;
}
