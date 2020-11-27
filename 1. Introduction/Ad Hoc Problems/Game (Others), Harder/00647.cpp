#include <iostream>
#include <vector>

using namespace std;

std::vector<int> rolls;
std::vector<int> ladder(100);
std::vector<bool> miss(100);
std::vector<bool> reroll(100);
std::vector<int> pos;
std::vector<bool> skip;

// retorna el indice de la siguiente tirada de dados
int play(int player, int i) {
	// printf("turno jugador %d\n", player);
	// printf("jugador %d está en la casilla %d\n", player, pos[player]);
	int roll = rolls[i];
	if (skip[player]) {
		skip[player] = false;
		// printf("jugador %d debe saltar su turno\n", player);
		return i; // salto de turno, por lo tanto retorno el mismo indice
	}
	// printf("jugador %d lanza el dado, saca %d (tiro #%d)\n", player, roll, i);
	if (pos[player] + roll == 100) {
		// printf("jugador %d llega a la meta!\n", player);
		cout << player + 1 << endl;
		return rolls.size(); // el juego termina, por lo tanto retorno el ultimo indice para no seguir iterando
	}
	else if (pos[player] + roll < 100) {
		pos[player] += roll;
		// printf("jugador %d avanza a la casilla %d\n", player, pos[player]);
		if (ladder[pos[player]] != pos[player]) {
			// printf("jugador %d es desplazado a la casilla %d\n", player, ladder[pos[player]]);
		}
		pos[player] = ladder[pos[player]];
		if (miss[pos[player]]) {
			// printf("jugador %d debe saltar su próximo turno\n", player);
			skip[player] = true;
		}
		else if (reroll[pos[player]]) {
			// printf("jugador %d juega de nuevo\n", player);
			return play(player, i + 1);
		}
	}
	else {
		// printf("jugador %d no puede avanzar esa cantidad\n", player);

	}
	return i + 1;
}

int main(int argc, char const *argv[]) {
	int roll;
	for (cin >> roll; roll != 0; cin >> roll) {
		rolls.push_back(roll);
	}
	int players;
	for (cin >> players; players != 0; cin >> players) {
		// printf("players: %d\n", players);
		pos = vector<int>(players, 0);
		skip = vector<bool>(players, false);
		for (size_t i = 0; i < 100; i++) {
			ladder[i] = i;
			miss[i] = false;
			reroll[i] = false;
		}
		int start, end;
		for (cin >> start >> end; start != 0 or end != 0; cin >> start >> end) {
			ladder[start] = end;
			// printf("ladder %d %d\n", start, end);
		}
		int square;
		for (cin >> square; square != 0; cin >> square) {
			if (square < 0) {
				miss[-square] = true;
				// printf("miss %d\n", -square);
			}
			else if (square > 0) {
				reroll[square] = true;
				// printf("reroll %d\n", square);
			}
		}
		for (int player = 0, roll = 0; roll < rolls.size(); ) {
			roll = play(player, roll);
			player = (player + 1) % players;
		}
	}
	return 0;
}
