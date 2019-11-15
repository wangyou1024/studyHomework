#include<stdio.h>
int main()
{
	int i;
	double a=1;
	for(i=1;i<=35;i++)
	{
		a=a*i;
		printf("%d!=%.0lf\n",i,a);
	}
	return 0;
}