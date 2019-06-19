// César Bolívar Severino
// resuelto propio
#include <iostream>
#include <set>
#include <string>
#include <map>
#include <sstream>

using namespace std;

int intvalue(char c) {
	return c == ' ' ? 0 : c - 'A' + 1;
}

char charvalue(int i) {
	return i == 0 ? ' ' : (char)i + 'A' - 1;
}
string rotate(string s, int k) {
	string result = s;
	for (int j = 0; j < s.size(); j++) {
		result[j] = charvalue((intvalue(s[j]) + k) % 27);
	}
	return result;
}

int main(int argc, char const* argv[])
{
	string word;
	string ciphertext;
	set<string> dictionary;
	int max_matches = 0;
	int max_matches_at = 0;
	cin >> word;
	while (word != "#") {
		dictionary.insert(word);
		cin >> word;
	}
	getline(cin, ciphertext); // consumir el salto de linea
	getline(cin, ciphertext);
	// for (string w : dictionary) {
		// cout << w << endl;
	// }
	// cout << ciphertext << endl;
	for (int i = 0; i < 27; i++) {
		// for (int j = 0; j < ciphertext.size(); j++) {
		// 	ciphertext[j] = charvalue((intvalue(ciphertext[j]) + 1) % 27);
		// }
		// cout << ciphertext << endl;
		int matches = 0;
		string rotated = rotate(ciphertext, i);
		istringstream iss(rotated);
		string aux;
		while (iss >> aux) {
			if (dictionary.find(aux) != dictionary.end()) {
				matches++;
			}
			// cout << i << ": " << aux << endl;
		}
		// cout << "matches: " << matches << endl;
		if (matches > max_matches) {
			max_matches = matches;
			max_matches_at = i;
		}
	}
	string result = rotate(ciphertext, max_matches_at);
	istringstream iss(result); // amo esta wea
	string aux;
	iss >> aux;
	int column = aux.size();
	cout << aux;
	while(iss >> aux) {
		if (column + aux.size() + 1 > 60)  { // mas uno para contar el espacio
			cout << endl;
			column = aux.size();
			cout << aux;
		}
		else {
			column += aux.size() + 1;
			cout << " " << aux;
		}
	}
	cout << endl;
	// cout << result << endl;
	return 0;
}
