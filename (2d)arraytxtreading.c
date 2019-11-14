#include <stdio.h>
#include <stdlib.h>
#define SIZE 2
void read(FILE*inp, int arr[][SIZE])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			fscanf(inp, "%d", &arr[i][j]);
		}
	}
}
int main(void)
{
	FILE*inp;
	int arr[4][2];
	inp = fopen("deneme.txt", "r");
	if (inp==NULL)
	{
		printf("The file cannot open");
	}
	else
	{
		read(inp, arr);
		int i;
		int j;
	
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				printf("%d ", arr[i][j]);
			}
			printf("\n");

		}
	}
	
system("PAUSE");

	fcloseall();
	return 0;
}
