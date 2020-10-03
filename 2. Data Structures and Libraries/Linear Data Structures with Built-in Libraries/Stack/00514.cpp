// César Bolívar Severino
// resuelto propio
#include <iostream>
#include <stack>
#include <vector>
#include <stdlib.h>

using namespace std;

int main(int argc, char const* argv[])
{
	vector<int>* A = NULL;
	vector<int>* B = NULL;
	stack<int>* s = NULL;
	unsigned int largo_vector;
	int aux;

	while (true) {
		// cout << "Ingrese el largo del vector: ";
		cin >> largo_vector;
		if (largo_vector == 0) {
			exit(0);
		}
		while (true) {
			A = new vector<int>();
			B = new vector<int>();
			s = new stack<int>();

			for (unsigned int i = 0; i < largo_vector; i++) {
				B->push_back(i+1);
			}
			// for (unsigned int i = 0; i < A->size(); i++)
			// { cout << (*A)[i] << " ";}
			// cout << endl;

			// cout << "Ingrese la permutación: ";
			cin >> aux;
			if (aux == 0) {
				cout << endl;
				break;
			}
			else{
				A->push_back(aux);
			}
			for (unsigned int i = 1; i < largo_vector; i++) {
				cin >> aux;
				A->push_back(aux);
			}
			// for (unsigned int i = 0; i < B->size(); i++)
			// { cout << (*B)[i] << " ";}
			// cout << endl;

			s->push(0);

			unsigned int j = 0;
			unsigned int i = 0;
			for ( ; i < largo_vector; ) {
				if (s->top() == (*A)[i]) {
					// cout << "pop " << s->top() << endl;
					s->pop();
					i++;
					continue;
				}
				else if ((*A)[i] == (*B)[j]) {
					// cout << "coincide el " << (*A)[i] << endl;
					j++;
					i++;
					continue;
				}
				else if (j < largo_vector) {
					// cout << "push " << (*B)[j] << endl;
					s->push((*B)[j]);
					j++;
				}
				else{
					break;
				}
			}
			if (s->top() == 0) {
				cout << "Yes" << endl;
			}
			else{
				cout << "No" << endl;
			}
		}
	}
	return 0;

}
