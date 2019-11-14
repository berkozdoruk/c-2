#include <stdio.h>
#include "stack_int.h"
int main()
{
	int number,elements;
	stack_t s;
	printf("Enter a decimal number:");
	scanf("%d", &number);
	initialize_s(&s);
	while (number > 0)
	{
		push(&s, number % 2);
		number = number / 2;
	}
	while (!is_empty_s(&s))
	{
		elements = pop(&s);
		printf("%d", elements);
	}

	printf("\nThe Decimal is : %d\n", number);
}
