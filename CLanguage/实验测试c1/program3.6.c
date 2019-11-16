#include<stdio.h>
int main()
{
	int i,h,j,sum;
	for(i=100;i<279;i++)
	{
		h=i;
		sum=0;
		while(h!=0)
		{
			j=h%10;
			sum=sum+j*10+3;
			h=h/10;
		}
		if(sum==i)
			printf("%d ",sum);
	}
	return 0;
}