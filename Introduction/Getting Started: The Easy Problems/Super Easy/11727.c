// César Bolívar Severino
// resuelto propio
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int i;
	int s[3];
	for (i = 0; i < n; i++)
	{
		int j;
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &s[j]);
			// printf("s[%d]: %d\n", j, s[j]);
		}
		if ((s[1] <= s[0] && s[0] <= s[2]) || (s[2] <= s[0] && s[0] <= s[1]))
		{
			printf("Case %d: %d\n", i + 1, s[0]);
		}
		else if ((s[0] <= s[1] && s[1] <= s[2]) || (s[2] <= s[1] && s[1] <= s[0]))
		{
			printf("Case %d: %d\n", i + 1, s[1]);
		}
		else {
			printf("Case %d: %d\n", i + 1, s[2]);
		}
	}
	return 0;
}
