// César Bolívar Severino
// resuelto propio
#include <stdio.h>

int main(int argc, char const* argv[])
{
	char buffer[13];
	fgets(buffer, 13, stdin);
	while (fread(buffer, 1, 12, stdin) != 0)
	{
		if (buffer[0] == '-') {
			break;
		}
		char letter = '\0';
		int i;
		for (i = 1; i < 10; i++) {
			if (i == 6) {
				continue;
			}
			int bit = buffer[i] == 'o' ? 1 : 0;
			letter = (letter << 1);
			letter |= bit;
		}
		printf("%c", letter);
	}
	return 0;
}
