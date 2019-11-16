#include<stdio.h>

#include<string.h>

char *cut(char s[100],int m,int n);

void main()

{

	char s[100];
	char a[100];
	char *p=a;
	int n,m;

	printf("Please input a string:");

	gets(s);

	printf("Please input the number of positions from which to intercept the string:");

	scanf("%d",&m);

	printf("please input the number of chars which we need to intercept:");

	scanf("%d",&n);

	p=cut(s,m,n);
	printf("%s\n",p);

}

char *cut(char s[100],int m,int n)

{	
	char a[100];
	char *p=a;

	int q,i;
	q=0;
	for(i=m-1;i<m+n-1 || s[i]=='\0';i++)
	{
		*(p+q)=s[i];
		q++;
	}
	*(p+q)='\0';
	return p;
}

  



	
