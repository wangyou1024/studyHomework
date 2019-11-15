#include<stdio.h>
int main()
{
	int i;
	int h=1;
	int Sn=0;
	for(i=1;i<=6;i++)
	{
		h*=i;
		printf("%d\n",h);
		Sn+=h;
	}
	printf("Sn=%d\n",Sn);
	return 0;
}