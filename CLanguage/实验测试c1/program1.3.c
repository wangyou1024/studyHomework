#include<stdio.h>
int main()
{
	float Score;
	scanf("%f",&Score);
	if(Score>=90)
		printf("A");
	else if(Score>=80)
		printf("B");
	else if(Score>=70)
		printf("C");
	else if(Score>=60)
		printf("D");
	else
		printf("E");
	return 0;
}