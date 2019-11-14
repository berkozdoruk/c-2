#include <stdio.h>
#include  "stack_int.h"
void displaystack(stack_t s)//This function also contain countstack
{
	int elements,count=0;
	printf("STACK CONTENT\n");
	while (!is_empty_s(&s))
	{
		elements = pop(&s);
		count++;
		printf("%d\n", elements);
	}
	printf("Number of elements in the stack %d\n", count);
}
int RemoveMax(stack_t *s)
{
	int max=0;
	for (int i = 0; i < s->top; i++)
	{
		if (max<s->data[i])
		{
			max = s->data[i];
			
		}
	}
	printf("The max element of stack %d\n", max);

	
	return(max);
		
}
void sendNthtoEnd(stack_t *s)
{
	int num;
	printf("Enter N:");
	scanf("%d", &num);
	for (int i = 0; i < s->top; i++)
	{
		s->data[num] = (s->top);
	}
	
}

int main()
{
	int number;
	int choice;
	stack_t s;
	initialize_s(&s);
	do
	{
		printf("Enter a number:");
		scanf("%d", &number);
		push(&s, number);
	} while (number!=-9);
	printf("1.Count Stack\n");
	printf("2.Remove Maximum Element\n");
	printf("3.Send Nth to End\n");
	printf("4.Exit\n");
	
	do
	{
		printf("Enter your choice:");
		scanf("%d", &choice);
	} while (choice<1 || choice>4);


	switch (choice)
	{
	case 1:displaystack(s);
		break;
	case 2:RemoveMax(&s);
		break;
	case 3:sendNthtoEnd(&s);
		displaystack(s);
		break;
	}
}
