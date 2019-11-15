#include<stdio.h>
int main()
{
	float x;
	double y;
	scanf("%f",&x);
	if(x>=10000.0)
		y=0.05*x;
		else if(x>=5000.0)
			y=0.03*x;
			else if(x>=1000.0)
				y=0.02*x;
			else 
			{
				y=0;
			}
		
	printf("%lf\n",y);
	return 0;
}