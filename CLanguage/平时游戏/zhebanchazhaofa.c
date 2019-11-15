#include<stdio.h>
int main()
{
	int min=0;
	int max=10;
	int mid=0;
	int n,i;
	int a[10];
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	scanf("%d",&n);
	while(1)
	{
		mid=(min+max)/2;
		if(n==a[mid])
		{
			printf("%d\n",mid);
			break;
		}
		else if(n>a[mid])
				min=mid;
			else
				max=mid;
		if(min+1==max)
		{
			printf("Not exist\n");
			break;
		}
	}

	return 0;
}