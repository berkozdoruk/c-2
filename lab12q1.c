#include <stdio.h>
#include <stdlib.h>
#include "stack_int.h"
void display_stack(stack_t st)
{
	printf("Stack Content\n");
	while (!isEmptyS(&st))
	{
		printf("%d\n", pop(&st));
	}

	

}

int main()
{
	stack_t arr;
	int i = 0;
	int num;
	int first;
	int second;
	initializeS(&arr);
	for ( i = 0; i < 6; i++)
	{
		printf("Enter an integer:");
		scanf("%d", &num);
		push(&arr,num);
	}

	display_stack(arr);
	first = pop(&arr);
	second = pop(&arr);

	push(&arr, first);
	push(&arr, second);

	display_stack(arr);
	
	system("PAUSE");

}
