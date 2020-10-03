// César Bolívar Severino
// resuelto propio
#include <stdio.h>

int main(int argc, char const *argv[])
{
	while (1) {
		int queries;
		scanf("%d", &queries);
		if (queries == 0)
		{
			break;
		}
		int N;
		scanf("%d", &N);
		int M;
		scanf("%d", &M);
		int i;
		for (i = 0; i < queries; i++)
		{
			int X;
			scanf("%d", &X);
			int Y;
			scanf("%d", &Y);
			if (X == N || Y == M)
			{
				puts("divisa");
			}
			else if (X > N) {
				if (Y > M) {
					puts("NE");
				}
				else {
					puts("SE");
				}
			}
			else {
				if (Y > M) {
					puts("NO");
				}
				else {
					puts("SO");
				}
			}
		}
	}
	return 0;
}
