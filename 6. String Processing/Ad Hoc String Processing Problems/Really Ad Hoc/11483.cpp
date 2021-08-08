#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int n, t = 1;
	for (cin >> n; n != 0; cin >> n, t++) {
		string s;
		getline(cin, s);
		cout << "Case " << t << ":\n";
		cout << "#include<string.h>\n#include<stdio.h>\nint main()\n{\n";
		for (size_t i = 0; i < n; i++) {
			getline(cin, s);
			cout << "printf(\"";
			for (auto c: s) {
				if (c == '\\') {
					cout << "\\\\";
				}
				else if (c == '\"') {
					cout << "\\\"";
				}
				else {
					cout << c;
				}
			}
			cout << "\\n\");\n";
		}
		cout << "printf(\"\\n\");\n";
		cout << "return 0;\n}\n";
	}
	return 0;
}
