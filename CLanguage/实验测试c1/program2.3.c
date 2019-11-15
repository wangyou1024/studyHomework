//find rank
#include <stdio.h>
int main()
{
	int a,b,c;
	printf("please input three figures:");
	scanf("%d%d%d",&a,&b,&c);
	//there are six rank
	if (a<b)
		if (c<a)
		{	printf("%d<%d<%d\n",c,a,b);
		}
		else if(b<c)
		{		printf("%d<%d<%d\n",a,b,c);
		}
			else
			{	printf("%d<%d<%d\n",a,c,b);
			}
	else if (c<b)
	{		printf("%d<%d<%d\n",c,b,a);
	}
		else if(c<a)
		{		printf("%d<%d<%d\n",b,c,a);
		}
			else
			{	printf("%d<%d<%d\n",b,a,c);
			}
	return 0;
}
