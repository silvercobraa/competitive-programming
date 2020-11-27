#include <stdio.h>

#define NEGRO 0
#define BLANCO 1

int pos_string=0;

void LlenarCuadrante(int* esquina, int largo, int color)
{
	int i, j;
	for (i=0; i<largo; i++)
	{
		for (j=0; j<largo; j++)
		{
			*(esquina+32*i+j)=color;
		}
	}
	return;
}

void LeerCaracter(int* esquina, char* string, int largo)
{
	if (string[pos_string]=='e')
	{
		LlenarCuadrante(esquina, largo, BLANCO);
		pos_string++;
	}
	else if (string[pos_string]=='f')
	{
		LlenarCuadrante(esquina, largo, NEGRO);
		pos_string++;
	}
	else if (string[pos_string]=='p')
	{
		pos_string++;
		LeerCaracter(esquina+largo/2, string, largo/2);
		LeerCaracter(esquina, string, largo/2);
		LeerCaracter(esquina+(32*largo/2), string, largo/2);
		LeerCaracter(esquina+largo/2+(32*largo/2), string, largo/2);
	}
	return;
}


int ContarPixelesNegros(int* Array1, int* Array2)
{
	int total=0;
	int i;
	for (i=0; i<1024; i++)
	{
		if ((*(Array1+i))*(*(Array2+i))==NEGRO)
		{
			total++;
		}
	}
	return total;
}

int main()
{
	int i, n;
	int largo_inicial=32;
	int Imagen1[32][32];
	int Imagen2[32][32];
	char string1[1366];
	char string2[1366];

	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		scanf("%s", string1);
		scanf("%s", string2);

		LeerCaracter(&Imagen1[0][0], string1, largo_inicial);
		pos_string=0;
		LeerCaracter(&Imagen2[0][0], string2, largo_inicial);
		pos_string=0;
		printf("There are %d black pixels.\n", ContarPixelesNegros(&Imagen1[0][0], &Imagen2[0][0]));
	}
	return 0;
}
