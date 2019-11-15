#include<stdio.h>
int main()
{
	int i,h;
	double a[34];
	a[0]=1;
	for(i=2;i<=35;i++)
	{
		a[i-1]=a[i-2]*i;
	}
	for(h=0;h<35;h++)
		printf("%.0lf\n",a[h]);
	return 0;
}