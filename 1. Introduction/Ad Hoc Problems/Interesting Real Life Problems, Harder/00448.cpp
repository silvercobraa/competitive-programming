#include <iostream>
#include <string>
#include <map>

using namespace std;

enum Instruction {
	ADD='0', SUB='1', MUL='2', DIV='3',
	MOV='4', BREQ='5', BRLE='6', BRLS='7',
	BRGE='8', BRGR='9', BRNE='A', BR='B',
	AND='C', OR='D', XOR='E', NOT='F',
};

map <char, string> name = {
	{ADD, "ADD"}, {SUB, "SUB"}, {MUL, "MUL"}, {DIV, "DIV"},
	{MOV, "MOV"}, {BREQ, "BREQ"}, {BRLE, "BRLE"}, {BRLS, "BRLS"},
	{BRGE, "BRGE"}, {BRGR, "BRGR"}, {BRNE, "BRNE"}, {BR, "BR"},
	{AND, "AND"}, {OR, "OR"}, {XOR, "XOR"}, {NOT, "NOT"},
};

enum Mode {
	REGISTER=0, ABSOLUTE=1, PC_RELATIVE=2, CONSTANT=3
};

void read_op() {
	char high, low;
	cin >> high;
	if ('A' <= high and high <= 'F') {
		high -= 'A' - '9' - 1;
	}
	int mode = (high - '0') >> 2;
	// cout << "  mode: " << mode << endl;
	int value = (high - '0') & 0x3;
	for (int i = 0; i < 3; i++) {
		value <<= 4;
		cin >> low;
		if ('A' <= low and low <= 'F') {
			low -= 'A' - '9' - 1;
		}
		value |= low - '0';
	}
	// cout << "mode: " << high - '0' << " " << mode << endl;
	// cout << "value: " << low << " " << value << endl;
	if (mode == REGISTER) {
		cout << "R" << value;
	}
	else if (mode == ABSOLUTE) {
		cout << "$" << value;
	}
	else if (mode == PC_RELATIVE) {
		cout << "PC+" << value;
	}
	else if (mode == CONSTANT) {
		cout << value;
	}
}

int main(int argc, char const *argv[]) {
	char ins;
	while (cin >> ins) {
		cout << name[ins] << " ";
		if (ins == ADD or ins == SUB or ins == MUL or ins == DIV or ins == MOV) {
			read_op();
			cout << ",";
			read_op();
		}
		else if (ins == AND or ins == OR or ins == XOR) {
			read_op();
			cout << ",";
			read_op();
			cout << ",";
			read_op();
		}
		else {
			read_op();
		}
		cout << endl;
	}
	return 0;
}
