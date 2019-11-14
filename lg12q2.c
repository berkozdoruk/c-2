#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack_char.h"
#include <ctype.h>
int palindrome(char sent[], stack_t st)
{
	int len, i;
	int value;
	len = strlen(sent);
	for ( i = 0; i < len; i++)
	{
		push(&st, sent[i]);

	}
	i = 0;
	value = pop(&st);
	while (toupper(sent[i])==toupper(value) && i < len )
	{
		i++;
		if(!isEmptyS(&st))
			value = pop(&st);
	}
	if (i==len)
	{
		return 1;
	}
	else
	{
		return 0;
	}




}
void display(char arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%s\n", arr[i]);
	}
}
int main()
{
	FILE*inp;
	inp = fopen("palindrome.txt", "r");
	char sent[50];
	stack_t st;
	initializeS(&st);

	while (fscanf(inp," %[^\n]",sent)!=EOF)
	{
		if (palindrome(sent,st))
		{
			printf("%s\n", sent);
		}
		
	}


	system("PAUSE");
}
