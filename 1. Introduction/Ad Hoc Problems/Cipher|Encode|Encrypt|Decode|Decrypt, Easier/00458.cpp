#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    string s;
    for ( ; getline(cin, s); ) {
        for (char c: s) {
            putchar(c - 7);
        }
        putchar('\n');
    }
}