/*1.���Ƚ����ʻ�������ڵ�һ����������ʱִ��
2.���ļ���ȡ���ݲ��������Ļ
3.���䵥�� 3.1��¼���ʷ��������ݷ����ĸߵͽ�������Ϣ�ֱ�����߸�������
		   3.2�������������ڴ��Ҫ����ĵ���
		   3.2�����������1-40ʱ���ӷ�����͵�����ѡһ�����ʷ����������У�41-60ʱ���ڵڶ���������ѡ��һ�����Դ����ƣ��Ӷ����������ʳ��ָ��ʸ�
4.�޸��ļ�����*/
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
		printf("���ڳ�ʼ�����ʱ�\n");
		make_words();
	}
	else
	{
		printf("�ʻ���Ѵ���,�Ƿ���������word.txt�еĴʻ㣬һ�����룬���������ã�����word.txt���¼���ĵ��ʻ����룺(Y/N)");
		scanf("%c",&ch);
		if(ch=='Y'||ch=='y')
			make_words();
	}
	printf("*****************������ϵͳ********************\n");
	printf("					��������\n");
	printf("   1.�鿴�ʻ��             2.��������ϵͳ\n");
	printf("   3.�˳�ϵͳ\n");
	printf("��������Ӧ��ţ�");
	scanf("%d",&i);
	getchar();
	while(i!=3)
	{
		if(i==1)
		{
			view_words();//�鿴�ʻ���õ��ĺ���
		}
		if(i==2)
		{
			//���䵥���õ��ĺ���
			get_word(head);
			rem_word(head);
			check_word(head);
		}
		printf("��������Ӧ��ţ�");
		scanf("%d",&i);
		getchar();
	}
	giveoff(head);
	printf("�˳�ϵͳ��");
	getchar();
	return 0;
}