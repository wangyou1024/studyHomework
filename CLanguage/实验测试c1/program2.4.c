#include<stdio.h>
int main()
{
	int a[2];
	int i,h,t;
	for(i=0;i<3;i++)
	scanf("%d",&a[i]);
	for(h=0;h<2;h++)
	{
		for(i=0;i<2-h;i++)
		{
			if(a[i]>a[i+1])
			{
				t=a[i+1];
				a[i+1]=a[i];
				a[i]=t;
			}
		}
	}
	for(i=0;i<3;i++)
		printf("%d ",a[i]);
	return 0;
}