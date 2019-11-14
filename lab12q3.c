#include <stdio.h>
#include <stdlib.h>
#include "stack_struct1.h"


int main()
{

	FILE*binaryp;
	binaryp = fopen("person_info", "rb");
	person array;
	stack_t stack;
	initializeS(&stack);
	fread(&array, sizeof(person), 1, binaryp);// to init structure array
	
	while (!feof(binaryp))//read the binary files and push the stack
	{
		push(&stack, array);
		fread(&array, sizeof(person), 1, binaryp);
		
	
		
	}
	while (!isEmptyS(&stack))// pop the stack elements and transfer to  the structure array and print screen the result.
	{
		
		array = pop(&stack);
		printf("%s %s %d\n", array.name, array.surname, array.age);
	}



	
	system("PAUSE");

}
