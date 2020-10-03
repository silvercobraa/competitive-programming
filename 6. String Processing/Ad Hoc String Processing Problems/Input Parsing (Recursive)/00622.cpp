#include <iostream>
#include <string>

using namespace std;

constexpr int ERROR = -99999999;

int position = 0;
string word;

enum Symbol {LEFT_PAR='(', RIGHT_PAR=')', PLUS='+', ASTERISK='*'};

int expression();

void next_symbol() {
	position++;
}


bool accept(Symbol symbol) {
	if (word[position] == symbol) {
		position++;
		return true;
	}
	return false;
}

bool expect(Symbol symbol) {
	if (accept(symbol)) {
		return true;
	}
	// cout << "Error: se esperaba " << symbol << endl;
	return false;
}

int integer() {
	int value = 0;
	int count = 0;
	for (; position < word.size() and '0' <= word[position] and word[position] <= '9'; position++) {
		count++;
		value *= 10;
		value += word[position] - '0';
	}
	// cout << "integer " << value << endl;
	// cout << "count " << count << endl;
	return count != 0 ? value : ERROR;
	// if ('0' <= word[position] and word[position] <= '9') {
	// 	cout << "integer " << word[position] << endl;
	// 	position++;
	// 	integer();
	// }
}

int factor() {
	int fac = ERROR;
	if (accept(LEFT_PAR)) {
		// cout << "factor (" << endl;
		fac = expression();
		if (fac == ERROR) return ERROR;
		if (not expect(RIGHT_PAR)) return ERROR;
		// cout << "factor )" << endl;
	}
	else {
		fac = integer();
		if (fac == ERROR) return ERROR;
	}
	return fac;
}

int component() {
	int comp = factor();
	if (comp == ERROR) return ERROR;
	if (accept(ASTERISK)) {
		// cout << "component *" << endl;
		int tmp = component();
		if (tmp == ERROR) return ERROR;
		comp *= tmp;
	}
	return comp;
}

int expression() {
	int expr = component();
	if (expr == ERROR) return ERROR;
	if (accept(PLUS)) {
		// cout << "expression +" << endl;
		int tmp = expression();
		if (tmp == ERROR) return ERROR;
		expr += tmp;
	}
	return expr;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> word;
		position = 0;
		int ans = expression();
		if (position != word.size() or ans == ERROR) {
			cout << "ERROR" << endl;
		}
		else {
			cout << ans << endl;
		}
	}
	return 0;
}
