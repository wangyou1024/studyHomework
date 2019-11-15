#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct information
{
	char num[12];
	char name[11];
	int grade[3];
	int sum;
	struct information *next;
}student;
int main()
{
	FILE *fp;
	student *head,*p,*p1,*p2,*p3;
	int j,i;
	if((fp=fopen("e:\\ÊµÑé»ù´¡2.txt","w+"))==NULL)
	{
		printf("the file can't open\n");
		exit(0);
	}
	head=calloc(1,sizeof(student));
	head->next=NULL;
	for(i=0;i<10;i++)
	{
		p=calloc(1,sizeof(student));
		p->sum=0;
		printf("input the information\n");
		fflush(stdin);
		gets(p->num);
		gets(p->name);
		for(j=0;j<3;j++)
		{
			scanf("%d",&p->grade[j]);
			p->sum=p->sum+p->grade[j];
		}
		p->next=head->next;
		head->next=p;
	}
	for(i=0;i<9;i++)
	{
		p1=head;
		p2=head->next;
		p3=head->next->next;
		for(j=0;j<9-i;j++)
		{
			if(p2->sum>p3->sum)
			{
				p1->next=p3;
				p2->next=p3->next;
				p3->next=p2;
			}
			p1=p1->next;
			p2=p2->next;
			p3=p3->next;
		}
	}
	p=head->next;
	while(p!=NULL)
	{
		printf("%-13s",p->num);
		fprintf(fp,"%-13s",p->num);
		printf("%-13s",p->name);
		fprintf(fp,"%-13s",p->name);
		for(j=0;j<3;j++)
		{
			printf("%-4d",p->grade[j]);
			fprintf(fp,"%-4d",p->grade[j]);
		}
		printf("%-4d\n",p->sum);
		fprintf(fp,"%-4d\n",p->sum);
		fputs("\n",fp);
		p=p->next;
	}
	fclose(fp);
	p1=head;
	p2=head;
	while(p1!=NULL)
	{
		p1=p1->next;
		free(p2);
		p2=p1;
	}
	return 0;
}