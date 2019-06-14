#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& v) {
	for (auto x: v) {
		cout << x << " ";
	}
	cout << endl;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	string s;
	getline(cin, s);
	getline(cin, s);
	for (int t = 0; t < n; t++) {
		if (t != 0) {
			cout << endl;
		}
		vector<int> ram(1000, 0);
		vector<int> reg(10, 0);
		int pc = 0;
		for (getline(cin, s); s != ""; getline(cin, s)) {
			ram[pc] = stoi(s);
			pc++;
		}
		pc = 0;
		bool halted = false;
		int total = 0;
		for ( ; not halted; total++) {
			// print(ram);
			// print(reg);
			int ins = ram[pc];
			// cout << "ins: " << ins << endl;
			int code = ins/100;
			int op1 = (ins/10)%10;
			int op2 = ins%10;
			// cout << ins << " " << code << " " << op1 << " " << op2 << endl;
			if (ins == 100) {
				halted = true;
			}
			else if (code == 2) {
				reg[op1] = op2;
			}
			else if (code == 3) {
				reg[op1] = (reg[op1] + op2) % 1000;
			}
			else if (code == 4) {
				reg[op1] = (reg[op1] * op2) % 1000;
			}
			else if (code == 5) {
				reg[op1] = reg[op2];
			}
			else if (code == 6) {
				reg[op1] = (reg[op1] + reg[op2]) % 1000;
			}
			else if (code == 7) {
				reg[op1] = (reg[op1] * reg[op2]) % 1000;
			}
			else if (code == 8) {
				reg[op1] = ram[reg[op2]];
			}
			else if (code == 9) {
				ram[reg[op2]] = reg[op1];
			}
			else if (code == 0) {
				if (reg[op2] != 0) {
					pc = reg[op1]-1;
				}
			}
			pc++;
			// cout << "\npc: " << pc << endl;
		}
		cout << total << endl;

	}
	return 0;
}
