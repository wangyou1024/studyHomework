/*1.首先建立词汇表，控制在第一次启动程序时执行
2.打开文件读取内容并输出到屏幕
3.记忆单词 3.1记录单词分数，根据分数的高低将单词信息分别放入七个链表中
		   3.2建立主链表，用于存放要记忆的单词
		   3.2产生随机数，1-40时，从分数最低的链表选一个单词放入主链表中，41-60时，在第二个链表中选择一个，以此类推，从而做到生单词出现概率高
4.修改文件内容*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include"forword.h"
int main()
{
	FILE *fp;
	word_link *head;
	int i;
	char ch;
	head=calloc(1,sizeof(word_link));
	head->nextaddr=NULL;
	if((fp=fopen("words.txt","r"))==NULL)
	{
		printf("正在初始化单词表\n");
		make_words();
	}
	else
	{
		printf("词汇表已存在,是否重新载入word.txt中的词汇，一旦载入，分数将重置，但在word.txt中新加入的单词会载入：(Y/N)");
		scanf("%c",&ch);
		if(ch=='Y'||ch=='y')
			make_words();
	}
	printf("*****************背单词系统********************\n");
	printf("					——王游\n");
	printf("   1.查看词汇表             2.启动记忆系统\n");
	printf("   3.退出系统\n");
	printf("请输入相应标号：");
	scanf("%d",&i);
	getchar();
	while(i!=3)
	{
		if(i==1)
		{
			view_words();//查看词汇表用到的函数
		}
		if(i==2)
		{
			//记忆单词用到的函数
			get_word(head);
			rem_word(head);
			check_word(head);
		}
		printf("请输入相应标号：");
		scanf("%d",&i);
		getchar();
	}
	giveoff(head);
	printf("退出系统！");
	getchar();
	return 0;
}