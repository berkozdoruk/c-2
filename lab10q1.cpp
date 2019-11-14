#include <stdio.h>
#include <stdlib.h>
int Ackermann(int num1, int num2)
{
	if (num1==0)
	{
		return num2 + 1;
	}
	if (num1>0 && num2==0)
	{
		return Ackermann(num1 - 1, 1);

	}
	if (num1>0 && num2>0)
	{
		return Ackermann(num1 - 1, Ackermann(num1, num2 - 1));

	}


	


}
int main()
{
	int m, n, result;
	printf("Enter the value of m:");
	scanf("%d", &m);

	printf("Enter the value of n:");
	scanf("%d", &n);
	result = Ackermann(m, n);

	printf("The result is %d\n", result);
	system("PAUSE");
	return 0;
}
