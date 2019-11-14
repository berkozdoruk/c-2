#include <stdio.h>
#include <stdlib.h>
typedef struct {
	double avg_score;
	double avg_rebound;


}avg_score;
typedef struct {
	char name[20];
	int age;
	double len;
	avg_score points;
}info_t;
int read(FILE*inp, info_t arr[])
{
	int i = 0;
	int temp;

	while (fscanf(inp, "%s %d %lf %lf %lf", arr[i].name, &arr[i].age, &arr[i].len, &arr[i].points.avg_score, &arr[i].points.avg_rebound) != EOF)
	{
		i++;


	}

	for (int j = 0; j < i; j++)
	{
		printf("%s %d %.2f %.2f %.2f\n", arr[j].name, arr[j].age, arr[j].len, arr[j].points.avg_score, arr[j].points.avg_rebound);
	}
	return i;

}
void display(info_t *arr)
{

}
int maxave(info_t *arr,int size)
{
	double max = arr[0].points.avg_rebound;
	int i = 0;
	for ( i = 0; i < size; i++)
	{
		if (arr[i].points.avg_rebound>max)
		{
			max = arr[i].points.avg_rebound;
		}
	}
	printf("Best Rebound Player:\n %.2f",max);
	return max;
	
}


int main()
{
	FILE*inp;
	info_t arr[25];
	int size;
	double max;


	inp = fopen("players.txt", "r");
	if (inp == NULL)
	{
		printf("ERROR");
	}
	else
	{
		size=read(inp, arr);
		maxave(arr, size);
		

	}

	system("PAUSE");

}
