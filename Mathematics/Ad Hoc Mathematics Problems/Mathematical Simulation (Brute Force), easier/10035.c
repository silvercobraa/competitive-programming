#include <stdio.h>

void Carry(int num1, int num2)
{
	int carry = 0;
	int carry_operations = 0;
	int digito1, digito2, suma;
	while (num1!=0 || num2!=0)
	{
		digito1 = num1%10;
		digito2 = num2%10;
		suma = digito1+digito2+carry;
		if (suma > 9)
		{
			carry = 1;
			carry_operations++;
		}
		else
		{
			carry = 0;
		}
		num1 /= 10;
		num2 /= 10;
	}
	switch(carry_operations)
	{
		case 0: printf("No carry operation.\n"); break;
		case 1: printf("1 carry operation.\n"); break;
		default: printf("%d carry operations.\n", carry_operations); break;
	}
	return;
}


int main()
{
	int num1, num2;
	while (1)
	{
		scanf("%d %d", &num1, &num2);
		if (num1==0 && num2==0)
			break;
		Carry(num1, num2);
	}	return 0;
}
