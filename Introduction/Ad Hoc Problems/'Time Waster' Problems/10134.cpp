#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	string line;
	getline(cin, line); // consumir salto linea numero de casos
	getline(cin, line); // consumir primera linea vacia
	for (int t = 0; t < T; t++) {
		if (t != 0) {
			cout << endl;
		}
		int bait = 0;
		bool half_bait = false;
		int time = 0;
		int last_fish = -70;
		int fishing_time = 0;
		int fish_caught = 0;
		for (getline(cin, line); line != ""; getline(cin, line)) {
			// cout << "instruccion: " << line << endl;
			// cout << line << endl;
			if (line == "lunch") {
				// cout << "noop" << endl;
				time += 10;
			}
			else if (line == "bait") {
				if (bait < 3) {
					if (half_bait) {
						bait++;
						half_bait = false;
						// cout << bait << " carnada(s)" << endl;
					}
					else {
						half_bait = true;
						// cout << bait << " y media carnada" << endl;
					}
				}
				else {
					// cout << "ya hay 3 carnadas" << endl;
				}
				time += 10;
			}
			else if (line == "fish") {
				if (bait > 0) {
					fishing_time += 10;
					if (fish_caught == 0) {
						// cout << "primer pescado" << endl;
						fish_caught++;
						time += 10;
						last_fish = time;
						bait--;
						fishing_time = 0;
					}
					else if (fishing_time >= 30) {
						time += 10;
						if (time - last_fish >= 70) {
							fish_caught++;
							last_fish = time;
							bait--;
							fishing_time = 0;
							// cout << "otro pescado en tiempo " << last_fish << endl;
						}
						else {
							// cout << "ultimo pescado hace " << time-last_fish << " minutos" << endl;
						}
					}
					else {
						// cout << fishing_time << " minutos de pesca" << endl;
						time += 10;
					}

				}
				else {
					// cout << "no hay carnada" << endl;
					time += 10;
				}
			}
			// cout << "tiempo: " << time << endl;
		}
		cout << fish_caught << endl;
	}
	return 0;
}
