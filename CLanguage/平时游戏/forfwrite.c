/*��1�������ļ����������Ϣ��ѧ����Ϣ���£�
ѧ��	    ����	�Ա�	��������   C����  �ߵ���ѧ	Ӣ��
11303070408	�±�	M	  1999.9.20	   100	   90	     86
11303070422	Ф��ܰ	F	  1998.8.15	   95	   80	     100
11303070301	�ⳬ	M	  1997.3.10	   98	   70	     59
11303070413	���Ӻ�	F	  2000.8.15	   88	   58	     90
11303070305	��׳	M	  1996.8.15	   99	   95	     98*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct information
{
	char a[12];
	char b[20];
	char sex;
	char c[11];
	int grade[3];
}student;
int main()
{
	int i;
	student x[5]={"11303070408","�±�",'M',"1999.9.20",{100,90,86},
		"11303070422","Ф��ܰ",'F',"1998.8.15",{95,80,100},
		"11303070301","�ⳬ",'M',"1997.3.10",{98,70,59},
		"11303070413","���Ӻ�",'F',"2000.8.15",{88,58,90},
		"11303070305","��׳",'M',"1996.8.15",{99,95,98}};
	student y[5];
	FILE *fp;
	if((fp=fopen("e:\\write.bin","wb+"))==NULL)
	{
		printf("the file can't open\n");
		exit(0);
	}
	for(i=0;i<5;i++)
	{
		if(fwrite(x+i,sizeof(student),1,fp)!=1)
		{
			printf("cannot write!\n");
			exit(0);
		}
	}
	fseek(fp,0,SEEK_SET);
	for(i=0;i<5;i++)
	{
		if(fread(y+i,sizeof(student),1,fp)!=1)
		{
			printf("cannot read\n");
			exit(0);
		}
	}
	for(i=0;i<5;i++)
	{
		printf("%s %s %c %s %d %d %d\n",y[i].a,y[i].b,y[i].sex,y[i].c,y[i].grade[0],y[i].grade[1],y[i].grade[2]);
	}
	fclose(fp);
	return 0;
}
