//定义结构体，存放单词信息
typedef struct words
{
	char Eng[20];
	char Cha[20];
	int score;
}word_inf;
//记结构体用于链表操作
typedef struct link
{
	word_inf word;
	struct link *nextaddr;
}word_link;
//该函数用于释放动态内存
void giveoff(word_link *head)
{
	word_link *p,*p1;
	p=head;
	p1=head;
	while(p!=NULL)
	{
		p=p->nextaddr;
		free(p1);
		p1=p;
	}
}
//将单词文件初始化生成另一个文件，新文件用以一个结构体为单位写入，便于后继的修改分数;
void make_words()
{
	word_link *head,*p;
	word_inf word;
	char ch;
	FILE *fp;
	int i;
	head=calloc(1,sizeof(word_link));
	head->nextaddr=NULL;
	if((fp=fopen("word.txt","r+"))==NULL)
	{
		printf("没有单词文件，无法初始化，请在c文件的同一目录下建立五个名为word.txt的文件，写入中文英文，\n英文在前，中英文用空格间隔，每行一个单词信息，或者将原文件下的word,txt文件复制到当前文件目录下\n");
		exit(0);
	}
	while(1)
	{
		p=calloc(1,sizeof(word_link));
		i=0;
		ch=fgetc(fp);
		while(ch!=' ')
		{
			p->word.Eng[i]=ch;
			i++;
			ch=fgetc(fp);
		}
		p->word.Eng[i]='\0';
		while(ch==' ')
			ch=fgetc(fp);
		i=0;
		while(ch!='\n' && ch!=EOF)
		{
			p->word.Cha[i]=ch;
			i++;
			ch=fgetc(fp);
		}
		p->word.Cha[i]='\0';
		p->word.score=0;
		p->nextaddr=head->nextaddr;
		head->nextaddr=p;
		if(ch==EOF)
		{
			break;
		}
		
	}
	p=head->nextaddr;
	fclose(fp);
	if((fp=fopen("words.txt","w+"))==NULL)
	{
		printf("生成单词表失败！");
		exit(0);
	}
	while(p!=NULL)
	{
		word=p->word;
		fwrite(&word,sizeof(word_inf),1,fp);
		p=p->nextaddr;
	}
	fclose(fp);
	giveoff(head);
	printf("初始化完成\n");
}
//该函数用于展示所有词汇
void view_words()
{
	FILE *fp;
	word_inf word;
	if((fp=fopen("words.txt","r+"))==NULL)
	{
		printf("单词表打开失败");
		exit(0);
	}
	fread(&word,sizeof(word_inf),1,fp);
	printf("----------------------------------------------------\n");
	printf("|   单词              |     中文            | 分数 |\n");
	printf("----------------------------------------------------\n");
	while(feof(fp)==0)
	{
		printf("|%-20s |%-20s |   %d  |\n",word.Eng,word.Cha,word.score);
		printf("----------------------------------------------------\n");
		fread(&word,sizeof(word_inf),1,fp);
	}
	fclose(fp);
}
//该函数用于生成主链表
void get_word(word_link *head)
{
	int i,n,rand_num,min=0;//min变量用于查找词汇表中得分最低的成绩，找到后可根据它来七个阶层的链表
	word_inf word;
	word_link *p,*head1,*head2,*head3,*head4,*head5,*head6,*head7,*p1,*p2,*p3,*p4,*p5,*p6,*p7;
	FILE *fp;
	srand(time(NULL));
	head1=calloc(1,sizeof(word_link));
	head2=calloc(1,sizeof(word_link));
	head3=calloc(1,sizeof(word_link));
	head4=calloc(1,sizeof(word_link));
	head5=calloc(1,sizeof(word_link));
	head6=calloc(1,sizeof(word_link));
	head7=calloc(1,sizeof(word_link));
	head1->nextaddr=NULL;
	head2->nextaddr=NULL;
	head3->nextaddr=NULL;
	head4->nextaddr=NULL;
	head5->nextaddr=NULL;
	head6->nextaddr=NULL;
	head7->nextaddr=NULL;
	system("cls");//清空屏幕，切换系统
	printf("*********************记忆系统*************************\n\n");
	printf("请输入记忆单词个数:");
	scanf("%d",&n);
	getchar();
	while(n>20 || n<=0)
	{
		printf("请输入正确的记忆单词数目（1-20），一次不可太多：");
		scanf("%d",&n);
	}
	printf("正在载入单词...");
	if((fp=fopen("words.txt","r+"))==NULL)
	{
		printf("打开词汇表失败，请检查词汇表words.bin是否存在，如不存在请重启程序！");
		exit(0);
	}
	fread(&word,sizeof(word_inf),1,fp);
	min=word.score;
	while(feof(fp)==0)
	{
		fread(&word,sizeof(word_inf),1,fp);
		if(min>word.score)
			min=word.score;
	}
	rewind(fp);
	while(feof(fp)==0)
	{
		if((fread(&word,sizeof(word_inf),1,fp))==1)
		{	
			if(word.score==min)//最低分的词汇
			{
				p1=calloc(1,sizeof(word_link));
				p1->word=word;
				p1->nextaddr=head1->nextaddr;
				head1->nextaddr=p1;
			}
			else if(word.score==min+1)//比最低分多一分
			{
				p2=calloc(1,sizeof(word_link));
				p2->word=word;
				p2->nextaddr=head2->nextaddr;
				head2->nextaddr=p2;
			}
			else if(word.score==min+2)//比最低分多两分
			{
				p3=calloc(1,sizeof(word_link));
				p3->word=word;
				p3->nextaddr=head3->nextaddr;
				head3->nextaddr=p3;
			}
			else if(word.score==min+3)//比最低分多三分
			{
				p4=calloc(1,sizeof(word_link));
				p4->word=word;
				p4->nextaddr=head4->nextaddr;
				head4->nextaddr=p4;
			}
			else if(word.score==min+4)//比最低分多四分
			{
				p5=calloc(1,sizeof(word_link));
				p5->word=word;
				p5->nextaddr=head5->nextaddr;
				head5->nextaddr=p5;
			}
			else if(word.score==min+5)//比最低分多五分
			{
				p6=calloc(1,sizeof(word_link));
				p6->word=word;
				p6->nextaddr=head6->nextaddr;
				head6->nextaddr=p6;
			}
			else//剩余的全部放入最后一个链表
			{
				p7=calloc(1,sizeof(word_link));
				p7->word=word;
				p7->nextaddr=head7->nextaddr;
				head7->nextaddr=p7;
			}
		}
	}
	p1=head1->nextaddr;
	p2=head2->nextaddr;
	p3=head3->nextaddr;
	p4=head4->nextaddr;
	p5=head5->nextaddr;
	p6=head6->nextaddr;
	p7=head7->nextaddr;
	for(i=0;i<n;i++)//主链表中收集n个词汇
	{
		rand_num=1+rand()%100;
		while(1)
		{
			if(rand_num<=40)
			{
				if(p1!=NULL)
				{
					p=calloc(1,sizeof(word_link));
					p->word=p1->word;
					p->nextaddr=head->nextaddr;
					head->nextaddr=p;
					p1=p1->nextaddr;
					break;
				}
				else
				{
					rand_num=41;//当七个链表中有空链表出现时，改变产生的随机数值，再次进入选择循环，在另一个链表中寻找，直到收集到词汇为止
				}
			}
			else if(rand_num<=60)
			{
				if(p2!=NULL)
				{
					p=calloc(1,sizeof(word_link));
					p->word=p2->word;
					p->nextaddr=head->nextaddr;
					head->nextaddr=p;
					p2=p2->nextaddr;
					break;
				}
				else
				{
					rand_num=61;//同理
				}
			}
			else if(rand_num<=70)
			{
				if(p3!=NULL)
				{
					p=calloc(1,sizeof(word_link));
					p->word=p3->word;
					p->nextaddr=head->nextaddr;
					head->nextaddr=p;
					p3=p3->nextaddr;
					break;
				}
				else
				{
					rand_num=71;//同理
				}
			}
			else if(rand_num<=80)
			{
				if(p4!=NULL)
				{
					p=calloc(1,sizeof(word_link));
					p->word=p4->word;
					p->nextaddr=head->nextaddr;
					head->nextaddr=p;
					p4=p4->nextaddr;
					break;
				}
				else
				{
					rand_num=81;//同理
				}
			}
			else if(rand_num<=90)
			{
				if(p5!=NULL)
				{
					p=calloc(1,sizeof(word_link));
					p->word=p5->word;
					p->nextaddr=head->nextaddr;
					head->nextaddr=p;
					p5=p5->nextaddr;
					break;
				}
				else
				{
					rand_num=91;//同理
				}
			}
			else if(rand_num<=95)
			{
				if(p6!=NULL)
				{
					p=calloc(1,sizeof(word_link));
					p->word=p6->word;
					p->nextaddr=head->nextaddr;
					head->nextaddr=p;
					p6=p6->nextaddr;
					break;
				}
				else
				{
					rand_num=96;//同理
				}
			}
			else
			{
				if(p7!=NULL)
				{
					p=calloc(1,sizeof(word_link));
					p->word=p7->word;
					p->nextaddr=head->nextaddr;
					head->nextaddr=p;
					p7=p7->nextaddr;
					break;
				}
				else
				{
					rand_num=1;//同理
				}
			}
		}
	}
	giveoff(head1);
	giveoff(head2);
	giveoff(head3);
	giveoff(head4);
	giveoff(head5);
	giveoff(head6);
	giveoff(head7);
	fclose(fp);
}
//该函数用于记忆单词，每次屏幕上只显示一个单词，记忆过程需要根据自己的记忆能力，在适当时候进入下一个单词记忆或回看上一个单词
void rem_word(word_link *head)
{
	int i=1;
	int j;
	char ch;
	word_link *p;
	system("cls");
	printf("*********************记忆系统*************************\n\n");
	printf("开始记忆单词，输入w查看上一个单词，输入s查看下一个单词！\n");
	p=head->nextaddr;
	printf("%-20s%-20s",p->word.Eng,p->word.Cha);
	if(p->nextaddr==NULL)
	{
		p=p->nextaddr;
		getchar();
	}
	while(p!=NULL)
	{
		scanf("%c",&ch);
		getchar();
		//控制指针少移动一次，从而查看上一个
		if(ch=='w' || ch=='W')
		{
			system("cls");
			printf("*********************记忆系统*************************\n\n");
			printf("开始记忆单词，输入w查看上一个单词，输入s查看下一个单词！\n");
			i=i-1;
			if(i==0)
			{
				printf("这是第一个单词\n");
				i=1;
			}

		}
		//控制指针多移动一位，从而查看下一个
		if(ch=='s' || ch=='S')
		{
			system("cls");
			printf("*********************记忆系统*************************\n\n");
			printf("开始记忆单词，输入w查看上一个单词，输入s查看下一个单词！\n");
			i=i+1;
		}
		p=head->nextaddr;
		for(j=1;j<i && p!=NULL;j++)
		{
			p=p->nextaddr;
		}
		if(p!=NULL)
			printf("%-20s%-20s",p->word.Eng,p->word.Cha);
	}
}
//该函数用于检查是否进行了正确的记忆
void check_word(word_link *head)
{
	word_link *p;
	word_inf word,word1;
	char English[20];
	FILE *fp;
	if((fp=fopen("words.txt","r+"))==NULL)
	{
		printf("打开词汇表失败，请检查词汇表words.bin是否存在，如不存在请重启程序！");
		exit(0);
	}
	system("cls");
	printf("*********************记忆系统*************************\n\n");
	printf("开始记忆单词,显示中文，请输入英文\n");
	p=head->nextaddr;
	while(p!=NULL)
	{
		word=p->word;
		printf("%-20s",word.Cha);
		scanf("%s",English);
		if(strcmp(word.Eng,English)==0)//合格情况
		{
			printf("输入正确，分数加一\n");
			word.score=word.score+1;
			//在文件中找到要修改分数的单词
			while((fread(&word1,sizeof(word_inf),1,fp))==1)
			{
				if(strcmp(word.Eng,word1.Eng)==0)
				{	//将文件指针移动到目标单词前，并覆盖原来的内容
					fseek(fp,-sizeof(word_inf),SEEK_CUR); 
					fwrite(&word,sizeof(word_inf),1,fp);
					rewind(fp);
					break;
				}
			}
		}
		else
			printf("输入错误，无加分！正确答案为：%-20s\n",word.Eng);
		p=p->nextaddr;
	}
	fclose(fp);
	printf("记忆完成，按下任意键退出记忆系统");
	getch();
	system("cls");
	printf("*****************背单词系统********************\n");
	printf("					——王游\n");
	printf("   1.查看词汇表             2.启动记忆系统\n");
	printf("   3.退出系统\n");
}
