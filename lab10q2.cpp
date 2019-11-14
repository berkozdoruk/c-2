#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int num;
	double fact;
}numbers_t;

int is_prime(int num, int i)//i is a divisor
{
	if (i == 1)
	{
		return 1;
	}
	else if (num%i==0)
	{
		return 0;
	}
	else
	{
		is_prime(num, i + 1);
	}
}
double fact(int num)
{
	if (num == 1)
	{
		return 1;
	}
	else
	{
		return(num * fact(num - 1));
	}
}

int main()
{
	int m, n;
	int i ;
	int k=0;
	int prime;
	numbers_t *odd;
	printf("Enter the value of m:");
	scanf("%d", &m);

	printf("Enter the value of n:");
	scanf("%d", &n);
	odd = (numbers_t *)malloc((m / 2 + 1) * sizeof(numbers_t));

	for ( i = 1; i < m; i++)
	{
		if (i%2==1)
		{
			odd[k].num == i;
			odd[k].fact = fact(i);
			k++;
		}
	}
	printf("ODD NUMBERS\n");
	for ( i = 0; i < k; i++)
	{
		printf(" %d %0.2f\n", odd[i].num, odd[i].fact);
	}
	system("PAUSE");
	return 0;
}
