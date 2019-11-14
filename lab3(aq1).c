#include <stdio.h>
#include <stdlib.h>
void swap(double *num1, double *num2)
{
	double temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
void bubble_sort(double grades[], int n)
{
	int pass, k;
	for ( pass = 1; pass <=n-1 ; pass++)
	{
		for ( k = 0; k <n-pass ; k++)
		{
			if (grades[k]>grades[k+1])
			{
				swap(&grades[k], &grades[k + 1]);
			}
		}
	}
}

int main()
{
	double grades[5];
	int id;
	printf("Enter the id of the student 1:");
	scanf("%d", &id);

	printf("Enter three grades:");

	for (int i = 0; i < 3; i++)
	{
		scanf("%lf", &grades[i]);

	}
	bubble_sort(grades, 3);
	printf("student %d's:", id);

	for (int i = 0; i < 3; i++)
	{
		printf(" %.1f ", grades[i]);
	}


	
	system("PAUSE");
}
