#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack_string.h"
#include "queue_str.h"
void displaymax(queue_t q)
{
	bank_t temp, max;
	temp = remove(&q);
	max = temp;
	while (!isEmptyQ(&q))
	{
		if (temp.year<max.year)
		
			max = temp;
		temp = remove(&q);



	}
	printf("The oldest bank is %s and %d years\n", max.bankname,(2018 - max.year));



}

void displayS(stack_t s)
{
	char temp[60];
	printf("STACK CONTENT\n---------\n");
	while (!isEmptyS(&s))
	{
		strcpy(temp, pop(&s));
		printf("%s\n", temp);
	}
}
void displayQ(queue_t q)
{
	bank_t temp;
	printf("QUEUE CONTENT\n---------\n");
	temp = remove(&q);
	while (!isEmptyQ(&q))
	{
		
		printf("%s %d\n", temp.bankname, temp.year);
		temp = remove(&q);
	}
}
int main()
{
	FILE*inp;
	inp = fopen("bank.txt", "r");
	stack_t s;
	queue_t q;
	bank_t bank;
	char ope[50];
	initializeQ(&q);
	initializeS(&s);
	if (inp==NULL)
	{
		printf("Error");
	}
	else
	{
		while (fscanf(inp,"%[^0-9] %d %s",bank.bankname,&bank.year,ope)!=EOF)
		{
			insert(&q, bank);
			push(&s, ope);
		}


	}

	displayS(s);
	displayQ(q);
	displaymax(q);
	system("PAUSE");
}
