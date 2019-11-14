#include <stdio.h>
#include <stdlib.h>
#define SIZE 30
int Read_list(int arr[])
{
	int i = 0;
	printf("Enter list elements(999 to stop):");
	scanf("%d", &arr[i]);
	while (arr[i] != 999)
	{

		i++;
		printf("Enter list elements(999 to stop):");
		scanf("%d", &arr[i]);
	}
	return (i);
}
void Find_Sum_Pro(int arr[], int size, int *sum,int *product)
{
	*sum = 0;
	*product = 1;

	for (int i = 0; i < size; i++)
	{
		*sum += arr[i];
		*product *= arr[i];
	}


}
int Compare_Sum_Pro(int list[], int listsize, int *sum, int *product)
{
	Find_Sum_Pro(list, listsize, sum, product);
	if (*sum == *product)
		return 0;
	else if (*sum > *product)
		return 1;
	else return 2;
}
int main(void)
{
	int sum;
	int listsize;
	int product;
	int arr[SIZE];
	listsize=Read_list(arr);
	Find_Sum_Pro(arr, listsize, &sum,&product);
	printf("The sum of the elements (%d) is %d\n", product, sum);
	switch (Compare_Sum_Pro(arr, listsize, &sum, &product))
	{
	case 0: printf("\nThe sum of the elements (%d) is EQUAL to the product of the elements (%d)!\n", sum, product);
		break;

	case 1: printf("\nThe sum of the elements (%d) is GREATER than the product of the elements (%d)!\n", sum, product);
		break;

	case 2: printf("\nThe sum of the elements (%d) is LESS than the product of the elements (%d)!\n", sum, product);
		break;

	}
	system("PAUSE");
	return 0;
}
