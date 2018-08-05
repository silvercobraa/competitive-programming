#include <stdio.h>

int ValorDe(char* nombre)
{
	int suma_parcial = 0;
	int suma_final = 0;
	int i;
	for (i=0; nombre[i]!='\0'; i++)
	{
		if ('a'<=nombre[i] && nombre[i]<='z')
		{
			suma_parcial += nombre[i]-96;
		}
		else if ('A'<=nombre[i] && nombre[i]<='Z')
		{
			suma_parcial += nombre[i]-64;
		}
	}
	while (suma_final==0)
	{
		for (;suma_parcial!=0;)
		{
			suma_final += suma_parcial%10,
			suma_parcial /=10;
		}
		if (suma_final<10)
		{
			return suma_final;
		}
		else
		{
			suma_parcial = suma_final;
			suma_final = 0;
		}
	}
	return -1;
}

void PorcentajeDeAmor(int a, int b)
{
	if (a<=b)
	{
		printf("%.2f %%\n", 100*(float)a/b);
		return;
	}
	else
	{
		printf("%.2f %%\n", 100*(float)b/a);
		return;
	}
}

int main()
{
	char Nombre1[27];
	char Nombre2[27];
	int valor_1;
	int valor_2;

	while(1)
	{
		if (!fgets(Nombre1, 27, stdin))
			break;
		if (!fgets(Nombre2, 27, stdin))
			break;
		valor_1 = ValorDe(Nombre1);
		valor_2 = ValorDe(Nombre2);
		PorcentajeDeAmor(valor_1, valor_2);
	}
	return 0;
}
