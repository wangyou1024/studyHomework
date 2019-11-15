#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct information
{
	char num[12];
	char name[11];
	int score;
}student;
int main()
{
	student b[10],t;
	FILE *fp;
	int i,j,index;
	printf("please input the information:\n");
	for(i=0;i<10;i++)
	{
		fflush(stdin);
		gets(b[i].num);
		//scanf("%s",b[i].num);
		fflush(stdin);
		gets(b[i].name);
		//scanf("%s",b[i].name);
		scanf("%d",&b[i].score);
	}
	for(i=0;i<9;i++)
	{	
		index=i;
		for(j=i+1;j<10;j++)
		{
			if(b[j].score>b[index].score)
				index=j;
		}
		if(index!=i)
		{
			t=b[i];
			b[i]=b[index];
			b[index]=t;
		}
	}
	for(i=0;i<10;i++)
		printf("%-12s%-11s%-3d\n",b[i].num,b[i].name,b[i].score);
	if((fp=fopen("e:\\实验报告1.txt","w+"))==NULL)
	{
		printf("the file can't open!");
		exit(0);
	}
	for(i=0;i<10;i++)
	{
		fprintf(fp,"%-13s",b[i].num);
		fprintf(fp,"%-13s",b[i].name);
		fprintf(fp,"%-3d",b[i].score);
		fputs("\n",fp);
	}
	fclose(fp);
	return 0;
}