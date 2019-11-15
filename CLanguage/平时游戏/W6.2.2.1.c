#include<stdio.h>
void main()
{
	char ch[7]={"657ab21"};
	int a[10]={1,2,3,4,5,6,7,8,9,10},*p=a;
	int i;
	for(i=0;ch[i]>='0'&&ch[i]<='9';i++)
	{
		printf("%c ",ch[i]);
		printf("i=%d\n",i);
	}
	printf("%d",*p+4);
}