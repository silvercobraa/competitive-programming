// César Bolívar Severino
// resuelto propio
#include <iostream>
#include <string>
#include <map>
#include <tuple>

using namespace std;

bool is_constant(map<string, tuple<string, string, string>>& expr, string var) {
	return expr.find(var) == expr.end();
}

void print_expression(map<string, tuple<string, string, string>>& expr, string s, string prev_op, bool is_left) {
	// si no es una variable no estará en el map, por lo tanto es un valor inmediato. Lo imprimimos
	if (is_constant(expr, s)) {
		cout << s;
		return;
	}
	string var1 = get<0>(expr[s]);
	string curr_op = get<1>(expr[s]);
	string var2 = get<2>(expr[s]);
	if (prev_op == "+") {
		if (curr_op == "+" && !is_left) {
			cout << "(";
		}
		print_expression(expr, var1, curr_op, true); // imprimimos el desglose de la primera variable
		cout << get<1>(expr[s]);
		print_expression(expr, var2, curr_op, false); // imprimimos el desglose de la segunda variable
		if (curr_op == "+" && !is_left) {
			cout << ")";
		}
	}
	else if (prev_op == "*") {
		if (curr_op == "+" || (curr_op == "*" && !is_left)) {
			cout << "(";
		}
		print_expression(expr, var1, curr_op, true); // imprimimos el desglose de la primera variable
		cout << get<1>(expr[s]);
		print_expression(expr, var2, curr_op, false); // imprimimos el desglose de la segunda variable
		if (curr_op == "+" || (curr_op == "*" && !is_left)) {
			cout << ")";
		}
	}
}

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int N;
		map<string, tuple<string, string, string>> expr;
		cin >> N;
		string last;
		for (int j = 0; j < N; j++) {
			string var, equals, var1, op, var2;
			cin >> var;
			cin >> equals;
			cin >> var1;
			cin >> op;
			cin >> var2;
			// cout << var << equals << var1 << op << var2 << endl;
			expr[var] = make_tuple(var1, op, var2);
			last = var;
		}
		// cout << "last: " << last << endl;
		cout << "Expression #" << i << ": ";
		print_expression(expr, last, "+", true);
		cout << endl;
	}
	return 0;
}
