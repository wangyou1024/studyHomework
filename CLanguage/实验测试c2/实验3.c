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
	student *head,*p,*p1,*p2;
	int i,j,k,a;
	char t[15];
	if((fp=fopen("e:\\ÊµÑé»ù´¡2.txt","w+"))==NULL)
	{
		printf("the file can't open!\n");
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
		p1=head->next;
		p2=head->next->next;
		for(j=0;j<9-i;j++)
		{
			if(p1->sum>p2->sum)
			{
				strcpy(t,p1->num);
				strcpy(p1->num,p2->num);
				strcpy(p2->num,t);
				strcpy(t,p1->name);
				strcpy(p1->name,p2->name);
				strcpy(p2->name,t);
				for(k=0;k<3;k++)
				{
					a=p1->grade[k];
					p1->grade[k]=p2->grade[k];
					p2->grade[k]=a;
				}
				a=p1->sum;
				p1->sum=p2->sum;
				p2->sum=a;
			}
			p1=p1->next;
			p2=p2->next;
		}
	}
	p=head->next;
	while(p!=NULL)
	{
		printf("%-13s",p->num);
		fprintf(fp,"%-13s",p->num);
		printf("%-13s",p->name);
		fprintf(fp,"%-13s",p->name);
		for(k=0;k<3;k++)
		{
			printf("%-4d",p->grade[k]);
			fprintf(fp,"%-4d",p->grade[k]);
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