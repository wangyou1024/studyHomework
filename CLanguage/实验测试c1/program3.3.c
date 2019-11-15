#include<stdio.h>
int main()
{
	int i=2;
	int h;
	printf("%d ",i);
	i++;
	for(;i<100;i=i+2)
	{
		for(h=3;h<=i/2;h=h+2)
		{
			if(i%h==0)
				break;
		}
		if(h>i/2)
			printf("%d ",i);
	}
	return 0;
}
