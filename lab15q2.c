#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	int code;
	char name[50];
}course_t;

typedef struct
{
	int id;
	int q1, q2, q3;
	double avg;
	int num;
	char op;
}stu_t;
int main()
{
	FILE*inp1;
	FILE*inp2;
	inp1 = fopen("student.txt", "r");
	inp2 = fopen("coursesbin", "rb");
	stu_t stu;
	course_t course;
	if (inp1==NULL || inp2==NULL)
	{
		printf("ERROR");
	}
	else
	{
		while (fscanf(inp1,"%d %c %d %d %d %d",&stu.id,&stu.op,&stu.num,&stu.q1, &stu.q2, &stu.q3)!=EOF)
		{
			switch (stu.op)
			{
			case 'T':
				fseek(inp2, sizeof(course_t)*(stu.num - 1), SEEK_SET);
				fread(&course, sizeof(course_t), 1, inp2);
				break;
			case 'C':
				fseek(inp2, sizeof(course_t)*(stu.num - 1), SEEK_CUR);
				fread(&course, sizeof(course_t), 1, inp2);
				break;
			case 'B':
				fseek(inp2, sizeof(course_t)*(stu.num *(- 1)), SEEK_END);
				fread(&course, sizeof(course_t), 1, inp2);
				break;
			}
			stu.avg = (stu.q1 + stu.q2 + stu.q3) / 3;
			printf("%d %d %s %0.2f\n", course.code, stu.id, course.name, stu.avg);




		}
	}

	system("PAUSE");



}
