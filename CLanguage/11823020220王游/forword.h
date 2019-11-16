//����ṹ�壬��ŵ�����Ϣ
typedef struct words
{
	char Eng[20];
	char Cha[20];
	int score;
}word_inf;
//�ǽṹ�������������
typedef struct link
{
	word_inf word;
	struct link *nextaddr;
}word_link;
//�ú��������ͷŶ�̬�ڴ�
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
//�������ļ���ʼ��������һ���ļ������ļ�����һ���ṹ��Ϊ��λд�룬���ں�̵��޸ķ���;
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
		printf("û�е����ļ����޷���ʼ��������c�ļ���ͬһĿ¼�½��������Ϊword.txt���ļ���д������Ӣ�ģ�\nӢ����ǰ����Ӣ���ÿո�����ÿ��һ��������Ϣ�����߽�ԭ�ļ��µ�word,txt�ļ����Ƶ���ǰ�ļ�Ŀ¼��\n");
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
		printf("���ɵ��ʱ�ʧ�ܣ�");
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
	printf("��ʼ�����\n");
}
//�ú�������չʾ���дʻ�
void view_words()
{
	FILE *fp;
	word_inf word;
	if((fp=fopen("words.txt","r+"))==NULL)
	{
		printf("���ʱ��ʧ��");
		exit(0);
	}
	fread(&word,sizeof(word_inf),1,fp);
	printf("----------------------------------------------------\n");
	printf("|   ����              |     ����            | ���� |\n");
	printf("----------------------------------------------------\n");
	while(feof(fp)==0)
	{
		printf("|%-20s |%-20s |   %d  |\n",word.Eng,word.Cha,word.score);
		printf("----------------------------------------------------\n");
		fread(&word,sizeof(word_inf),1,fp);
	}
	fclose(fp);
}
//�ú�����������������
void get_word(word_link *head)
{
	int i,n,rand_num,min=0;//min�������ڲ��Ҵʻ���е÷���͵ĳɼ����ҵ���ɸ��������߸��ײ������
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
	system("cls");//�����Ļ���л�ϵͳ
	printf("*********************����ϵͳ*************************\n\n");
	printf("��������䵥�ʸ���:");
	scanf("%d",&n);
	getchar();
	while(n>20 || n<=0)
	{
		printf("��������ȷ�ļ��䵥����Ŀ��1-20����һ�β���̫�ࣺ");
		scanf("%d",&n);
	}
	printf("�������뵥��...");
	if((fp=fopen("words.txt","r+"))==NULL)
	{
		printf("�򿪴ʻ��ʧ�ܣ�����ʻ��words.bin�Ƿ���ڣ��粻��������������");
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
			if(word.score==min)//��ͷֵĴʻ�
			{
				p1=calloc(1,sizeof(word_link));
				p1->word=word;
				p1->nextaddr=head1->nextaddr;
				head1->nextaddr=p1;
			}
			else if(word.score==min+1)//����ͷֶ�һ��
			{
				p2=calloc(1,sizeof(word_link));
				p2->word=word;
				p2->nextaddr=head2->nextaddr;
				head2->nextaddr=p2;
			}
			else if(word.score==min+2)//����ͷֶ�����
			{
				p3=calloc(1,sizeof(word_link));
				p3->word=word;
				p3->nextaddr=head3->nextaddr;
				head3->nextaddr=p3;
			}
			else if(word.score==min+3)//����ͷֶ�����
			{
				p4=calloc(1,sizeof(word_link));
				p4->word=word;
				p4->nextaddr=head4->nextaddr;
				head4->nextaddr=p4;
			}
			else if(word.score==min+4)//����ͷֶ��ķ�
			{
				p5=calloc(1,sizeof(word_link));
				p5->word=word;
				p5->nextaddr=head5->nextaddr;
				head5->nextaddr=p5;
			}
			else if(word.score==min+5)//����ͷֶ����
			{
				p6=calloc(1,sizeof(word_link));
				p6->word=word;
				p6->nextaddr=head6->nextaddr;
				head6->nextaddr=p6;
			}
			else//ʣ���ȫ���������һ������
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
	for(i=0;i<n;i++)//���������ռ�n���ʻ�
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
					rand_num=41;//���߸��������п��������ʱ���ı�����������ֵ���ٴν���ѡ��ѭ��������һ��������Ѱ�ң�ֱ���ռ����ʻ�Ϊֹ
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
					rand_num=61;//ͬ��
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
					rand_num=71;//ͬ��
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
					rand_num=81;//ͬ��
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
					rand_num=91;//ͬ��
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
					rand_num=96;//ͬ��
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
					rand_num=1;//ͬ��
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
//�ú������ڼ��䵥�ʣ�ÿ����Ļ��ֻ��ʾһ�����ʣ����������Ҫ�����Լ��ļ������������ʵ�ʱ�������һ�����ʼ����ؿ���һ������
void rem_word(word_link *head)
{
	int i=1;
	int j;
	char ch;
	word_link *p;
	system("cls");
	printf("*********************����ϵͳ*************************\n\n");
	printf("��ʼ���䵥�ʣ�����w�鿴��һ�����ʣ�����s�鿴��һ�����ʣ�\n");
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
		//����ָ�����ƶ�һ�Σ��Ӷ��鿴��һ��
		if(ch=='w' || ch=='W')
		{
			system("cls");
			printf("*********************����ϵͳ*************************\n\n");
			printf("��ʼ���䵥�ʣ�����w�鿴��һ�����ʣ�����s�鿴��һ�����ʣ�\n");
			i=i-1;
			if(i==0)
			{
				printf("���ǵ�һ������\n");
				i=1;
			}

		}
		//����ָ����ƶ�һλ���Ӷ��鿴��һ��
		if(ch=='s' || ch=='S')
		{
			system("cls");
			printf("*********************����ϵͳ*************************\n\n");
			printf("��ʼ���䵥�ʣ�����w�鿴��һ�����ʣ�����s�鿴��һ�����ʣ�\n");
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
//�ú������ڼ���Ƿ��������ȷ�ļ���
void check_word(word_link *head)
{
	word_link *p;
	word_inf word,word1;
	char English[20];
	FILE *fp;
	if((fp=fopen("words.txt","r+"))==NULL)
	{
		printf("�򿪴ʻ��ʧ�ܣ�����ʻ��words.bin�Ƿ���ڣ��粻��������������");
		exit(0);
	}
	system("cls");
	printf("*********************����ϵͳ*************************\n\n");
	printf("��ʼ���䵥��,��ʾ���ģ�������Ӣ��\n");
	p=head->nextaddr;
	while(p!=NULL)
	{
		word=p->word;
		printf("%-20s",word.Cha);
		scanf("%s",English);
		if(strcmp(word.Eng,English)==0)//�ϸ����
		{
			printf("������ȷ��������һ\n");
			word.score=word.score+1;
			//���ļ����ҵ�Ҫ�޸ķ����ĵ���
			while((fread(&word1,sizeof(word_inf),1,fp))==1)
			{
				if(strcmp(word.Eng,word1.Eng)==0)
				{	//���ļ�ָ���ƶ���Ŀ�굥��ǰ��������ԭ��������
					fseek(fp,-sizeof(word_inf),SEEK_CUR); 
					fwrite(&word,sizeof(word_inf),1,fp);
					rewind(fp);
					break;
				}
			}
		}
		else
			printf("��������޼ӷ֣���ȷ��Ϊ��%-20s\n",word.Eng);
		p=p->nextaddr;
	}
	fclose(fp);
	printf("������ɣ�����������˳�����ϵͳ");
	getch();
	system("cls");
	printf("*****************������ϵͳ********************\n");
	printf("					��������\n");
	printf("   1.�鿴�ʻ��             2.��������ϵͳ\n");
	printf("   3.�˳�ϵͳ\n");
}
