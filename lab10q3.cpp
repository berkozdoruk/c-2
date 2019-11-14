#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
int binary_search(char tour[][MAX], int top, int bottom, char srch[])
{
	int middle;

	while (top <= bottom)
	{
		middle = (top + bottom) / 2;

		if (strcmp(tour[middle], srch) == 0)
			return (middle);
		else
			if (strcmp(tour[middle], srch) > 0)
				return binary_search(tour, top, middle - 1, srch); //	bottom = middle - 1;
			else
				return binary_search(tour, top, middle + 1, srch);//top = middle + 1;
	}
	return (-1);
}
void display(char tour[][MAX], int size)
{
	printf("KARADENIZ TOUR PROGRAMME\n*******************************\n");
	for (int i = 0; i < size; i++)
	{
		printf("%s\n", tour[i]);
	}



}
	
int main()
{
	FILE*inp;
	inp = fopen("karadeniz.txt", "r");
	int i = 0;
	char req[20];
	int index;
	char tour[MAX][MAX];
	if (inp==NULL)
	{
		printf("ERROR");
	}
	else
	{
		while (fscanf(inp," %[^\n] ",tour[i])!=EOF)
		{
			i++;
		}
	}
	display(tour, i);

	printf("Enter the place that you want to visit:");
	scanf("%[^\n]", req);
	
	index = binary_search(tour, 0, i, req);
	if (index==-1)
	{
		printf("%s is not included in out tour programme\n", req);
	}
	else
	{
		printf("%s is  included in out tour programme\n", req);
	}

	system("PAUSE");
}
