#include<stdio.h>
int main()
{
	int i,a,b,c,sum;
	for(i=100;i<=999;i++)
	{
		a=i%10;
		b=(i%100)/10;
		c=i/100;
		sum=10*a+10*b+10*c+9;
		if(sum==i)
		{
			printf("%d ",i);
		}
	}
	return 0;
}