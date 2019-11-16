#include<stdio.h>
int main()
{
	int i,h;
	for(i=2;i<=100;i++)
	{
		for(h=2;h<i;h++)
		{
			if(i%h==0)
				break;
		}
		if(h==i)
			printf("%d ",i);
	}
	return 0;
}