#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct information
{
	char num[12];
	char name[11];
	int score;
}student;
void exchange(student *x,student *y)
{
	student t;
	t=*x;
	*x=*y;
	*y=t;
}
int main()
{
	student a[10];
	student *b=a;
	FILE *fp;
	int i,j,maxindex,minindex;
	printf("please input the information:\n");
	for(i=0;i<10;i++){
		fflush(stdin);
		gets((b+i)->num);
		fflush(stdin);
		gets((b+i)->name);
		scanf("%d",&(b+i)->score);
		printf("the next\n");
	}
	for(i=0;i<5;i++){	
		maxindex=i;
		minindex=9-i;
		for(j=i+1;j<10;j++){
			if((b+j)->score>(b+maxindex)->score)
				maxindex=j;
			if((b+9-j)->score<(b+minindex)->score)
				minindex=9-j;
		}
		if(maxindex==9-i && minindex==i){
			exchange((b+maxindex),(b+minindex));
		}
		else if(maxindex==9-i){
			exchange(b+i,b+maxindex);
			exchange(b+9-i,b+minindex);
		}
		else if(minindex==i){
			exchange(b+9-i,b+minindex);
			exchange(b+i,b+maxindex);
		}
		else{
			exchange(b+i,b+maxindex);
			exchange(b+9-i,b+minindex);
		}
	}
	for(i=0;i<10;i++)
		printf("%-12s%-11s%-3d\n",(b+i)->num,(b+i)->name,(b+i)->score);
	if((fp=fopen("e:\\实验报告1.txt","w+"))==NULL){
		printf("the file can't open!");
		exit(0);
	}
	for(i=0;i<10;i++){
		fprintf(fp,"%-13s",(b+i)->num);
		fprintf(fp,"%-13s",(b+i)->name);
		fprintf(fp,"%-3d",(b+i)->score);
		fputs("\n",fp);
	}
	fclose(fp);
	return 0;
}