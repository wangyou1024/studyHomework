#include<stdio.h>
int main()
{
	float x;
	double y;
	scanf("%f",&x);
	if(x>=10000)
		y=0.05*x;
	if(x>=5000 && x<10000)
		y=0.03*x;
	if(x>=1000 && x<5000)
		y=0.02*x;
	if(x<1000)
		y=0;
	printf("%f",y);
	return 0;
}