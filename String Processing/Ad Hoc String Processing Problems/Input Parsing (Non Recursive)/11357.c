// César Bolívar Severino
// resuelto propio ?
// El código es propio, pero la idea fue sacada del libro "Competitive Programing 3"
// "...only one clause needs to be satisfied to get TRUE; a clause can be satisfied if for all variables in the clause, its inverse is not in the clause too"
#include <stdio.h>
#include <string.h>

int validate(char DNF[]) {
	int variable[26] = {0};
	int negation[26] = {0};
	for (int i = 0; i < strlen(DNF); i++) {
		if ('a' <= DNF[i] && DNF[i] <= 'z') {
			variable[DNF[i] - 'a'] = 1;
		}
		else if (DNF[i] == '~') {
			negation[DNF[++i] - 'a'] = 1;
		}
		else if (DNF[i] == ')') {
			int all_ok = 1;
			for (int j = 0; j < 26; j++) {
				if (variable[j] && negation[j]) { // si esta una variable y su negacion dentro de la misma conjuncion, debemos revisar las demas conjunciones (por sui hubiese una verdadera)
					all_ok = 0;
					break;
				}
			}
			if (all_ok) { // al menos una conjuncion puede ser verdadera, podemos retornar inmediatamente
				return 1;
			}
			// cada vez que terminamos de revisar una conjuncion, limiamos estos arreglos
			memset(variable, 0, 26*sizeof(int));
			memset(negation, 0, 26*sizeof(int));
		}
	}
	return 0;
}

int main(int argc, char const *argv[]) {
	char formula[256];
	char* veredict[] = {"NO", "YES"};
	int n;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", formula);
		int v = validate(formula);
		// printf("v: %d\n", v);
		puts(veredict[v]);
	}
	return 0;
}
