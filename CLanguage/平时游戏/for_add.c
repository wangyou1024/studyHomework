#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct words
{
	char Eng[20];
	char Cha[20];
	struct words *nextaddr;
}word_inf;
void giveoff(word_inf *head)
{
	word_inf *p,*p1;
	p=head;
	p1=head;
	while(p!=NULL)
	{
		p=p->nextaddr;
		free(p1);
		p1=p;
	}
}
int main()
{
	word_inf *head,*p;
	char ch;
	FILE *fp;
	int i;
	head=calloc(1,sizeof(word_inf));
	head->nextaddr=NULL;
	if((fp=fopen("E:\\recitation.txt","r+"))==NULL)
	{
		printf("2\n");
		exit(0);
	}
	while(1)
	{
		p=calloc(1,sizeof(word_inf));
		i=0;
		ch=fgetc(fp);
		while(ch!=' ')
		{
			p->Eng[i]=ch;
			i++;
			ch=fgetc(fp);
		}
		p->Eng[i]='\0';
		while(ch==' ')
			ch=fgetc(fp);
		i=0;
		while(ch!='\n' && ch!=EOF)
		{
			p->Cha[i]=ch;
			i++;
			ch=fgetc(fp);
		}
		p->Cha[i]='\0';
		p->nextaddr=head->nextaddr;
		head->nextaddr=p;
		if(ch==EOF)
			break;
	}
	p=head->nextaddr;
	while(p!=NULL)
	{
		printf("1.%s %s\n",p->Eng,p->Cha);
		p=p->nextaddr;
	}
	giveoff(head);
	fclose(fp);
	return 0;
}