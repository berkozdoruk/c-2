#include <stdio.h>
#include <string.h>
#include "linked_list.h"
node_t *createlist(FILE*inp)
{
	node_t *headp, *p;

	company_t company;
	headp = NULL;

	fscanf(inp, "%s %d ", company.name, &company.lim);
	headp = addBeginning(headp, company);

	p = headp;

	while (fscanf(inp, "%s %d ", company.name, &company.lim)!=EOF)
	{
		addAfter(p, company);
		p = p->next;
	}

	return headp;
}
node_t *search(node_t *headp,char src[])
{
	node_t *p;
	p = headp;
	while (p!=NULL)
	{
		if (strcmp(p->data.name,src)==0)
		
			return p;
			p = p->next;
		
	}
	return NULL;
}
/*node_t *reverse(node_t *headp, node_t *newp)//LABGUIDE SOLUTION METHOD
{
	if (headp != NULL)
	{
		newp = addBeginning(newp, headp->data);
		newp = reverse(headp->next, newp);
	}
	return (newp);
}*/


void reversePrint(node_t* head)//MY METHOD
{
	if (head == NULL)
	{
		return;
	}
	else
	{
		reversePrint(head->next);
		printf("%s %d->", head->data.name,head->data.lim);
	}
}
int main()
{
	FILE*inp;
	inp = fopen("training.txt", "r");

	node_t *list;
	node_t *p;
	list = createlist(inp);
	
	display_list(list);

	char src[15];

	printf("Enter a company to search:");
	scanf("%s", src);
	p = search(list, src);
	if (p==NULL)
	{
		printf("The company is not in the list");
	}
	else
	{
		printf("%s %d FOUND\n", p->data.name, p->data.lim);
		
	}
	system("PAUSE");

}
