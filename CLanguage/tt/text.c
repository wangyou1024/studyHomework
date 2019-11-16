/*
程序功能：统计学生信息
        1.统计各生源地男女学生人数（男女分开统计）；
	    2.统计各专业学生人数，并按降序输出；
	    3.对数据按姓名升序排列，并输出到文件student_sort.txt。
编写日期：2019年6月15日
编写目的：用于重庆师范大学2018级数学教育专业《计算机文化基础II》期末课程考核范例
运行要求：程序运行前，必须准备好学生信息数据库。
          该数据库文件名students.txt，结构如下所示：
	 		生源地	姓名	性别  民族	专业
			重庆市	刘妮娜	男	  汉族	小学教育（语文）
			重庆市	陈姗	女	  汉族	小学教育（语文）
			重庆市	罗艺	女	  汉族	小学教育（语文）
			重庆市	严公芬	女	  汉族	小学教育（语文）
            ......

注意事项：数据库字段只能为5个，其中“生源地”字段长度小于12，姓名字段小于9，
          性别只能用汉字“男”、“女”表示，“民族”字段小于9，专业字段小于25，
		  总学生人数不得多于1600人。数据库文件只能放在D盘根目录下。
*/

#include<stdio.h>     //使用printf()函数
#include<stdlib.h>    //使用exit()函数
#include<string.h>    //使用fgets()、fputs()函数

//定义存储数据的结构体变量
struct stumsg
{
	char syd[20];    //存储生源地
	char name[9];    //存储姓名
	char sex[3];     //存储性别
	char mz[9];      //存储民族
	char zy[25];     //存储专业
};

//主函数
int main()
{
	//变量准备
	FILE *fp, *fp1;
	char str[50];                 //用于存储临时字符串信息
	int i = 0, j = 0, n = 0, fn;
	struct stumsg student[1600];  //最多能处理1600名学生，如果有更多数据则增大该数
	char zymc[70][25];           //生源地临时存储
	int zycou[70][2] = {0};        //各生源地学生人数 
	int mansum = 0, womansum = 0;
	int index = 0; //存放下标； 

	//打开数据文件
	fp = fopen("student1.txt","r");
	if(fp == NULL)
	{
		printf("文件打开失败!");
		exit(0);
	}
	//读取相关数据
	fgets(str,50,fp);       //从数据库文件汇总读取学生信息
	while(!feof(fp))      //将读取到的信息存放在数组student中相应位置
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

   /*=====处理数据=====*/
   
   //完成任务1
	 fn=1;
     strcpy(zymc[0],student[0].syd);
     
	 for(i=0;i<n;i++)
	 {
	    for(j=0;j<fn;j++)
		if(strcmp(student[i].syd,zymc[j])==0)
		{
			if(strcmp(student[i].sex,"男")==0) zycou[j][0]++;
			else zycou[j][1]++;
			break;
		}
	
		if(j>=fn)
		{
			fn++;
			strcpy(zymc[fn-1],student[i].syd);
			if(strcmp(student[i].sex,"男")==0) zycou[fn-1][0]=1;
			else zycou[fn-1][1]=1;
		}
	 }
	 
	//输出数据
	printf("== 生源地 ==== 男生人数 == 女生人数 == 总人数==\n");
	
	for(i=0;i<fn;i++) 
	{
		printf("%-17s%4d\t     %4d\t%4d\n",zymc[i],zycou[i][0],zycou[i][1],zycou[i][0]+zycou[i][1]);
		mansum+=zycou[i][0];
		womansum+=zycou[i][1];
	}
	
	printf("\n总计%d个专业,其中：\n\t男生总人数:%d\n\t女生总人数:%d\n\t人数合计:%d\n\n",fn,mansum,womansum,mansum+womansum);
	
	//完成任务2
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
	 
	 //输出数据
	 printf("====== 专业 ======= 总人数======\n");
	 
	 for(i=0;i<=fn+1;i++) for(j=0;j<=fn;j++) if(i==zycou[j][1]) printf("%-20s %4d\n",zymc[j],zycou[j][0]);

	//完成任务3
	 //排序(选择排序法)
	 for(i=0;i<n;i++)
	 {
		 mansum=i; for(j=i+1;j<n;j++) if(strcmp(student[j].name,student[mansum].name)<0) mansum=j; 
		 strcpy(str,student[mansum].syd); strcpy(student[mansum].syd,student[i].syd); strcpy(student[i].syd,str);
		 strcpy(str,student[mansum].name); strcpy(student[mansum].name,student[i].name); strcpy(student[i].name,str);
		 strcpy(str,student[mansum].sex); strcpy(student[mansum].sex,student[i].sex); strcpy(student[i].sex,str);
		 strcpy(str,student[mansum].mz); strcpy(student[mansum].mz,student[i].mz); strcpy(student[i].mz,str);
		 strcpy(str,student[mansum].zy); strcpy(student[mansum].zy,student[i].zy); strcpy(student[i].zy,str);
	 }
	 
	 //创建并写文件
	 fp1=fopen("student_sort.txt","a");
	 
	 for(i=0;i<n;i++)
	 {
		//准备待写数据
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
		
		//写数据进student_sort.txt文件
		fputs(str,fp1);
	 }

	//关闭文件并结束程序
	 fclose(fp1);
	 fclose(fp);
}
int is_zh_ch(char p){
	if(~(p>>8)==0){
		return 0;//不是汉字
	}
	else
		return -1;
}
