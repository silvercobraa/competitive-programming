#include <iostream>

using namespace std;

string word;
int position = 0;

bool accept(char c) {
	if (word[position] == c) {
		position++;
		return true;
	}
	return false;
}

int integer() {
	int value = 0;
	for ( ; position < word.size() and '0' <= word[position] and word[position] <= '9'; position++) {
		value *= 10;
		value += word[position] - '0';
	}
	// cout << "integer " << value << endl;
	return value;
}

// esta funcion y la integer serian mucho mas simples si estivuera leyendo de streams en vez de usando un cursor
double probability() {
	double p = 0.0;
	// CASO MARICON
	if (accept('1')) {
		p = 1.0;
	}
	else {
		accept('0');
	}
	accept('.');
	for (int div = 10; position < word.size() and '0' <= word[position] and word[position] <= '9'; position++, div *= 10) {
		// cout << (word[position] - '0') << endl;
		p += (word[position] - '0') / double(div);
	}
	return p;
}

double smeech() {
	if (accept('(')) {
		// cout << "smeech" << endl;
		double p = probability();
		accept(' ');
		double e1 = smeech();
		accept(' ');
		double e2 = smeech();
		accept(')');
		// cout << e1 << " " << e2 << endl;
		return p*(e1 + e2) + (1 - p)*(e1 - e2);
	}
	else if (accept('-')) {
		return -integer();
	}
	else {
		return integer();
	}
}


int main(int argc, char const *argv[]) {
	for (getline(cin, word); word != "()"; getline(cin, word)) {
		position = 0;
		double ans = smeech();
		printf("%.2lf\n", ans);
	}
	return 0;
}
