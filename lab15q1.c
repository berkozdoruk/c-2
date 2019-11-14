#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_str.h"
int find(char *mail)
{
	int i = 0;
	while (mail[i]!='@')
	{
		i++;
	}

	return i;
}
void display_stack(stack_t stack)
{
	printf("STACK CONTENT\n");
	info_t remove;
	while (!isEmptyS(&stack))
	{
		remove = pop(&stack);
		printf("%s %s %s %s\n",remove.name,remove.surname,remove.phone,remove.email );
			   
	}
	   	  
}

int main()
{
	FILE*inp;
	inp = fopen("people.txt", "r");
	info_t array;
	int i = 0;
	int index;
	char temp[20] = "";
	stack_t stack;
	initializeS(&stack);
	if (inp == NULL)
	{
		printf("ERROR");
			
	}
	else
	{

		

		for ( i = 0; i < 7; i++)
		{
			fscanf(inp, "%s %s %s %s", array.name, array.surname, array.phone, array.email);
			index = find(array.email);//we 
			strncpy(temp, array.email+index+1 , 5);
			temp[6] = '\0';//the content is 'gmail'
			if (strcmp(temp,"gmail")==0)
			{
				push(&stack, array);
			}
			
			
			
			
		}
	}


	display_stack(stack);


	system("PAUSE");
}
