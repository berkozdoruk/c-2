#include <stdio.h>
#include <stdlib.h>
typedef struct {
	char name[20];
	int age;
	double GPA;
}stu_t;
int main()
{
	FILE*inp;
	inp = fopen("stu.bin", "rb");
	stu_t arr;
	int size = 15;
	int X;
	int cho;
	//size = fread(&arr, sizeof(stu_t), 15, inp);
	
	//for (int i = 0; i < size; i++)
	//{
		//printf("%s %d %0.2f\n", arr[i].name, arr[i].age, arr[i].GPA);
	//}
	printf("1.)Go to record X from top\n");
	printf("2.)Move X record ahead\n");
	printf("3.)Go X records back from\n");
	printf("4.)Exit\n");


	printf("Enter your choice:");
	scanf("%d", &cho);


	switch (cho)
	{
	case 1:
		printf("Enter X:");
		scanf("%d", &X);

		fseek(inp, sizeof(stu_t)*(X-1), SEEK_SET);
		fread(&arr, sizeof(stu_t), 1, inp);
		printf("%s %d %0.2f", arr.name, arr.age, arr.GPA);
		break;
	case 2:
		printf("Enter X:");
		scanf("%d", &X);

		fseek(inp, sizeof(stu_t)*(X - 1), SEEK_CUR);
		fread(&arr, sizeof(stu_t), 1, inp);
		printf("%s %d %0.2f", arr.name, arr.age, arr.GPA);
		break;
	case 3:
		printf("Enter X:");
		scanf("%d", &X);

		fseek(inp, sizeof(stu_t)*(-X), SEEK_END);
		fread(&arr, sizeof(stu_t), 1, inp);
		printf("%s %d %0.2f", arr.name, arr.age, arr.GPA);
		break;
	case 4:
		return 0;
		break;
	
	}





	system("PAUSE");
	return 0;

}
