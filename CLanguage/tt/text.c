/*
�����ܣ�ͳ��ѧ����Ϣ
        1.ͳ�Ƹ���Դ����Ůѧ����������Ů�ֿ�ͳ�ƣ���
	    2.ͳ�Ƹ�רҵѧ���������������������
	    3.�����ݰ������������У���������ļ�student_sort.txt��
��д���ڣ�2019��6��15��
��дĿ�ģ���������ʦ����ѧ2018����ѧ����רҵ��������Ļ�����II����ĩ�γ̿��˷���
����Ҫ�󣺳�������ǰ������׼����ѧ����Ϣ���ݿ⡣
          �����ݿ��ļ���students.txt���ṹ������ʾ��
	 		��Դ��	����	�Ա�  ����	רҵ
			������	������	��	  ����	Сѧ���������ģ�
			������	���	Ů	  ����	Сѧ���������ģ�
			������	����	Ů	  ����	Сѧ���������ģ�
			������	�Ϲ���	Ů	  ����	Сѧ���������ģ�
            ......

ע��������ݿ��ֶ�ֻ��Ϊ5�������С���Դ�ء��ֶγ���С��12�������ֶ�С��9��
          �Ա�ֻ���ú��֡��С�����Ů����ʾ�������塱�ֶ�С��9��רҵ�ֶ�С��25��
		  ��ѧ���������ö���1600�ˡ����ݿ��ļ�ֻ�ܷ���D�̸�Ŀ¼�¡�
*/

#include<stdio.h>     //ʹ��printf()����
#include<stdlib.h>    //ʹ��exit()����
#include<string.h>    //ʹ��fgets()��fputs()����

//����洢���ݵĽṹ�����
struct stumsg
{
	char syd[20];    //�洢��Դ��
	char name[9];    //�洢����
	char sex[3];     //�洢�Ա�
	char mz[9];      //�洢����
	char zy[25];     //�洢רҵ
};

//������
int main()
{
	//����׼��
	FILE *fp, *fp1;
	char str[50];                 //���ڴ洢��ʱ�ַ�����Ϣ
	int i = 0, j = 0, n = 0, fn;
	struct stumsg student[1600];  //����ܴ���1600��ѧ��������и����������������
	char zymc[70][25];           //��Դ����ʱ�洢
	int zycou[70][2] = {0};        //����Դ��ѧ������ 
	int mansum = 0, womansum = 0;
	int index = 0; //����±ꣻ 

	//�������ļ�
	fp = fopen("student1.txt","r");
	if(fp == NULL)
	{
		printf("�ļ���ʧ��!");
		exit(0);
	}
	//��ȡ�������
	fgets(str,50,fp);       //�����ݿ��ļ����ܶ�ȡѧ����Ϣ
	while(!feof(fp))      //����ȡ������Ϣ���������student����Ӧλ��
	{
	  fgets(str,70,fp); 
	  printf("%s",str);
	  for(i = 0, j = 0; str[i] != '\t'; i++, j++) {
	      student[n].syd[j]=str[i];
		   index = i; 
	  }student[n].syd[j]='\0';
	  
	  for(j = 0, i = index++; str[i]!='\t'; i++,j++){
	  	student[n].name[j]=str[i];
	  	 index = i; 
	  }student[n].name[j]='\0';
	  printf("%c",student[n].name[0]);
	  
	  for(j = 0, i = index++; str[i]!='\t';i++,j++){
	  	student[n].sex[j]=str[i];
	  	 index = i;
	  }   student[n].sex[j]='\0';
	  
	  for(j = 0, i = index++; str[i]!='\t';i++,j++){
	  	student[n].mz[j]=str[i]; 
	  	 index = i;
	  }  student[n].mz[j]='\0';
	  
	  for(j = 0, i = index++; str[i]!='\n';i++,j++){
	  	 student[n].zy[j]=str[i];
	  	  index = i;
	  }  student[n].zy[j]='\0';
	  
	  n++; 
	 	  	  
	}

   /*=====��������=====*/
   
   //�������1
	 fn=1;
     strcpy(zymc[0],student[0].syd);
     
	 for(i=0;i<n;i++)
	 {
	    for(j=0;j<fn;j++)
		if(strcmp(student[i].syd,zymc[j])==0)
		{
			if(strcmp(student[i].sex,"��")==0) zycou[j][0]++;
			else zycou[j][1]++;
			break;
		}
	
		if(j>=fn)
		{
			fn++;
			strcpy(zymc[fn-1],student[i].syd);
			if(strcmp(student[i].sex,"��")==0) zycou[fn-1][0]=1;
			else zycou[fn-1][1]=1;
		}
	 }
	 
	//�������
	printf("== ��Դ�� ==== �������� == Ů������ == ������==\n");
	
	for(i=0;i<fn;i++) 
	{
		printf("%-17s%4d\t     %4d\t%4d\n",zymc[i],zycou[i][0],zycou[i][1],zycou[i][0]+zycou[i][1]);
		mansum+=zycou[i][0];
		womansum+=zycou[i][1];
	}
	
	printf("\n�ܼ�%d��רҵ,���У�\n\t����������:%d\n\tŮ��������:%d\n\t�����ϼ�:%d\n\n",fn,mansum,womansum,mansum+womansum);
	
	//�������2
	 fn=0;
     strcpy(zymc[0],student[0].zy);
	 zycou[0][0]=0;
	 
	 for(i=0;i<n;i++)
	 {
	    for(j=0;j<=fn;j++) if(strcmp(student[i].zy,zymc[j])==0)	{zycou[j][0]++;	break;}
		if(j>fn){fn++;	strcpy(zymc[fn],student[i].zy); zycou[fn][0]=1;}
	 }
	 
	 mansum=0;
	 for(i=n;i>=0;i--) for(j=0;j<=fn;j++) if(i==zycou[j][0]){mansum++;zycou[j][1]=mansum;}
	 
	 //�������
	 printf("====== רҵ ======= ������======\n");
	 
	 for(i=0;i<=fn+1;i++) for(j=0;j<=fn;j++) if(i==zycou[j][1]) printf("%-20s %4d\n",zymc[j],zycou[j][0]);

	//�������3
	 //����(ѡ������)
	 for(i=0;i<n;i++)
	 {
		 mansum=i; for(j=i+1;j<n;j++) if(strcmp(student[j].name,student[mansum].name)<0) mansum=j; 
		 strcpy(str,student[mansum].syd); strcpy(student[mansum].syd,student[i].syd); strcpy(student[i].syd,str);
		 strcpy(str,student[mansum].name); strcpy(student[mansum].name,student[i].name); strcpy(student[i].name,str);
		 strcpy(str,student[mansum].sex); strcpy(student[mansum].sex,student[i].sex); strcpy(student[i].sex,str);
		 strcpy(str,student[mansum].mz); strcpy(student[mansum].mz,student[i].mz); strcpy(student[i].mz,str);
		 strcpy(str,student[mansum].zy); strcpy(student[mansum].zy,student[i].zy); strcpy(student[i].zy,str);
	 }
	 
	 //������д�ļ�
	 fp1=fopen("student_sort.txt","a");
	 
	 for(i=0;i<n;i++)
	 {
		//׼����д����
		mansum=0;
		
		for(j=0;j<20;j++)
			if(mansum==0)
				if(student[i].syd[j]!='\0')	str[j]=student[i].syd[j];
				else {mansum=1;str[j]=' ';}
			else
				str[j]=' ';
				
		str[j]='\0';
		strcat(str,"\t");
		strcat(str,student[i].name); strcat(str,"\t");
		strcat(str,student[i].sex);	strcat(str,"\t");
		strcat(str,student[i].mz); strcat(str,"\t");
		strcat(str,student[i].zy); strcat(str,"\n");
		
		//д���ݽ�student_sort.txt�ļ�
		fputs(str,fp1);
	 }

	//�ر��ļ�����������
	 fclose(fp1);
	 fclose(fp);
}
int is_zh_ch(char p){
	if(~(p>>8)==0){
		return 0;//���Ǻ���
	}
	else
		return -1;
}
