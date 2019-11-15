typedef struct student_information
{
	char stu_num[12];//ѧ�ţ����к��а༶��Ϣ
	char stu_nam[8];//����
	char sex[4];//�Ա�
	char stu_bir[11];//����
	float bas;//������
	float bas_pro;//רҵ������
	float pro;//רҵ��
	float pro_cho;//רҵѡ����
	float real;//ʵ����
	char password[17];//����
}stu_inf;
typedef struct student_link//��������Ľṹ��
{
	stu_inf one_stu;
	struct student_link *nextaddr;
}stu_link;
void giveoff(stu_link *head)//�ͷŶ�̬�ڴ�
{
	stu_link *p,*p1;
	p=head;
	p1=head;
	while(p!=NULL)
	{
		p=p->nextaddr;
		free(p1);
		p1=p;
	}
}
void view_all_inf()//���ȫ����Ϣ
{
	stu_inf student;
	FILE *fp;
	int i=1;
	if((fp=fopen("E:\\student_information.bin","rb+"))==NULL)
	{
		printf("���ļ�����\n");
		exit(0);
	}
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("| ��� |    ѧ��    |   ����  |  �Ա�  |  ��������  |  ʵ��  |  רҵѡ�� |  רҵ  |  רҵ����  |  ����  |\n");
	printf("---------------------------------------------------------------------------------------------------------\n");
	while(fread(&student,sizeof(stu_inf),1,fp)==1)
	{
		printf("|  %-4d|%-12s|  %-7s|   %-5s|  %-10s|  %-6.2f|   %-7.2f | %-7.2f|   %-9.2f| %-7.2f|\n",i,student.stu_num,student.stu_nam,student.sex,student.stu_bir,student.real,student.pro_cho,student.pro,student.bas_pro,student.bas);
		printf("---------------------------------------------------------------------------------------------------------\n");
		i++;
	}
	fclose(fp);
}
void add_information()//���ѧ����Ϣ����
{
	FILE *fp;
	stu_inf student;
	if((fp=fopen("E:\\student_information.bin","ab"))==NULL)
	{
		printf("���ʱ���ļ�ʧ�ܣ�");
		exit(0);
	}
	printf("������ѧ�ţ�");
	gets(student.stu_num);
	printf("������������");
	gets(student.stu_nam);
	printf("�������Ա�");
	gets(student.sex);
	printf("������������ڣ�");
	gets(student.stu_bir);
	printf("���������ɼ�( ʵ��,רҵѡ��,רҵ,רҵ����,����),�ÿո�����");
	scanf("%f%f%f%f%f",&student.real,&student.pro_cho,&student.pro,&student.bas_pro,&student.bas);
	strcpy(student.password,"000000");
	fwrite(&student,sizeof(stu_inf),1,fp);
	printf("���\n");
	fclose(fp);
	Sleep(500);
}
void modification_stu_inf()//�޸�ѧ����Ϣ
{
	stu_inf student;
	FILE *fp;
	int i;
	char Y;
	char number[12];
	printf("������ѧ��ѧ�ţ�");
	gets(number);
	if((fp=fopen("E:\\student_information.bin","rb+"))==NULL)
	{
		printf("���ļ�����\n");
		exit(0);
	}
	while(1)//Ѱ��ѧ����Ϣ���ļ��е�λ��
	{
		if(fread(&student,sizeof(stu_inf),1,fp)!=1)
		{
			i=0;
			break;
		}
		if(strcmp(student.stu_num,number)==0)
		{
			i=1;
			break;
		}
	}
	if(i==0)
		printf("ϵͳ��û�и�ѧ����Ϣ��\n");
	else
	{
		printf("---------------------------------------------------------------------------------------------------------\n");
		printf("| ��� |    ѧ��    |   ����  |  �Ա�  |  ��������  |  ʵ��  |  רҵѡ�� |  רҵ  |  רҵ����  |  ����  |\n");
		printf("---------------------------------------------------------------------------------------------------------\n");
		printf("|  1   |%-12s|  %-7s|   %-5s|  %-10s|  %-6.2f|   %-7.2f | %-7.2f|   %-9.2f| %-7.2f|\n",student.stu_num,student.stu_nam,student.sex,student.stu_bir,student.real,student.pro_cho,student.pro,student.bas_pro,student.bas);
		printf("---------------------------------------------------------------------------------------------------------\n");
		printf("1.ѧ�� 2.���� 3.�Ա�  4.��������  5.������ѧ��  6.רҵ������ѧ��  7.רҵ��ѧ��  8.רҵѡ�޿�ѧ��  9.ʵ����ѧ��\n");
		printf("��������Ӧ����Ž����޸ģ�����0������޸ģ���");
		scanf("%d",&i);
		getchar();
		while(i)//�޸�ѧ����Ϣ��ѭ���޸Ĳ�ͬ��Ϣ
		{
			if(i==1)
			{
				printf("��������ѧ�ţ�");
				gets(student.stu_num);
			}
			else if(i==2)
			{
				printf("��������������");
				gets(student.stu_nam);
			}
			else if(i==3)
			{
				printf("�������Ա�");
				gets(student.sex);
			}
			else if(i==4)
			{
				printf("������������ڣ���ʽ1999-8-14��");
				gets(student.stu_bir);
			}
			else if(i==5)
			{
				printf("�����������ѧ�֣�");
				scanf("%f",&student.bas);
			}
			else if(i==6)
			{
				printf("������רҵ������ѧ�֣�");
				scanf("%f",&student.bas_pro);
			}
			else if(i==7)
			{
				printf("������רҵ��ѧ�� ��");
				scanf("%f",&student.pro);
			}
			else if(i==8)
			{
				printf("������רҵѡ�޿�ѧ�֣�");
				scanf("%f",&student.pro_cho);
			}
			else if(i==9)
			{
				printf("������ʵ����ѧ�֣�");
				scanf("%f",&student.real);
			}
			else
				i=0;
			printf("��������һ���޸����ݻ��˳���");
			scanf("%d",&i);
			getchar();
		}
		printf("---------------------------------------------------------------------------------------------------------\n");
		printf("| ��� |    ѧ��    |   ����  |  �Ա�  |  ��������  |  ʵ��  |  רҵѡ�� |  רҵ  |  רҵ����  |  ����  |\n");
		printf("---------------------------------------------------------------------------------------------------------\n");
		printf("|  1   |%-12s|  %-7s|   %-5s|  %-10s|  %-6.2f|   %-7.2f | %-7.2f|   %-9.2f| %-7.2f|\n",student.stu_num,student.stu_nam,student.sex,student.stu_bir,student.real,student.pro_cho,student.pro,student.bas_pro,student.bas);
		printf("---------------------------------------------------------------------------------------------------------\n");
		printf("�Ƿ�ȷ�ϣ�Y/N��");
		scanf("%c",&Y);
		if(Y=='y' || Y=='Y')
		{
			fseek(fp,-sizeof(stu_inf),SEEK_CUR);//�ļ�ָ��ǰ��һ���ṹ��ռ�
			fwrite(&student,sizeof(stu_inf),1,fp);//������Ϣ����ԭλ����Ϣ��
			printf("��ɣ�\n");
		}	
	}
	fclose(fp);
}
void del_inf()//ɾ��ѧ����Ϣ
{
	FILE *fp;
	stu_inf student;
	char num[12];
	int i=0;
	stu_link *head,*p;
	head=calloc(1,sizeof(stu_link));
	head->nextaddr=NULL;
	if((fp=fopen("E:\\student_information.bin","rb+"))==NULL)
	{
		printf("���ļ�����\n");
		exit(0);
	}
	printf("��������Ҫɾ����ѧ��ѧ�ţ�");
	gets(num);
	while(fread(&student,sizeof(stu_inf),1,fp)==1)//����ָ��ѧ�����ѧ����Ϣ����������
	{
		if(strcmp(student.stu_num,num)!=0)
		{
			p=calloc(1,sizeof(stu_link));
			p->one_stu=student;
			p->nextaddr=head->nextaddr;
			head->nextaddr=p;
		}
		else
		{
			i=1;
			printf("---------------------------------------------------------------------------------------------------------\n");
			printf("| ��� |    ѧ��    |   ����  |  �Ա�  |  ��������  |  ʵ��  |  רҵѡ�� |  רҵ  |  רҵ����  |  ����  |\n");
			printf("---------------------------------------------------------------------------------------------------------\n");
			printf("|  1   |%-12s|  %-7s|   %-5s|  %-10s|  %-6.2f|   %-7.2f | %-7.2f|   %-9.2f| %-7.2f|\n",student.stu_num,student.stu_nam,student.sex,student.stu_bir,student.real,student.pro_cho,student.pro,student.bas_pro,student.bas);
			printf("---------------------------------------------------------------------------------------------------------\n");
		}
	}
	fclose(fp);
	if(i==1)//���и�ѧ���Ϳ�����д�ļ����������е���Ϣд�����ļ������ļ���ԭ�ļ�ͬ�����Ա㸲�Ǿ��ļ�
	{
		if((fp=fopen("E:\\student_information.bin","wb"))==NULL)
		{
			printf("���ļ�����\n");
			exit(0);
		}
		p=head->nextaddr;
		while(p!=NULL)
		{
			student=p->one_stu;
			fwrite(&student,sizeof(stu_inf),1,fp);
			p=p->nextaddr;
		}
		printf("ɾ����ϣ�\n");
	}
	else
		printf("���޴���");
	giveoff(head);
	fclose(fp);
}
void re_password()//��������
{
	stu_inf student;
	FILE *fp;
	int i;
	char ch;
	char number[12];
	printf("������ѧ��ѧ�ţ�");
	gets(number);
	if((fp=fopen("E:\\student_information.bin","rb+"))==NULL)
	{
		printf("���ļ�����\n");
		exit(0);
	}
	while(1)//�ҵ�ָ��ѧ����
	{
		if(fread(&student,sizeof(stu_inf),1,fp)!=1)
		{
			i=0;
			break;
		}
		if(strcmp(student.stu_num,number)==0)
		{
			i=1;
			break;
		}
	}
	if(i==0)
	{
		printf("ϵͳ��û�и�ѧ����Ϣ��\n");
		fclose(fp);
	}
	else
	{
		printf("---------------------------------------------------------------------------------------------------------\n");
		printf("| ��� |    ѧ��    |   ����  |  �Ա�  |  ��������  |  ʵ��  |  רҵѡ�� |  רҵ  |  רҵ����  |  ����  |\n");
		printf("---------------------------------------------------------------------------------------------------------\n");
		printf("|  1   |%-12s|  %-7s|   %-5s|  %-10s|  %-6.2f|   %-7.2f | %-7.2f|   %-9.2f| %-7.2f|\n",student.stu_num,student.stu_nam,student.sex,student.stu_bir,student.real,student.pro_cho,student.pro,student.bas_pro,student.bas);
		printf("---------------------------------------------------------------------------------------------------------\n");
		printf("ȷ���������룡��Y/N��");
		scanf("%c",&ch);
		getchar();
		if(ch=='Y' || ch=='y')
		{
			strcpy(student.password,"000000");//��ѧ�����������ò�д���ļ�
			fseek(fp,-sizeof(stu_inf),SEEK_CUR); 
			fwrite(&student,sizeof(stu_inf),1,fp);
			printf("��ɣ�\n");
		}
		fclose(fp);
	}
}
void for_student()//����ѧ��ϵͳ
{
	FILE *fp;
	stu_inf student;
	int i,k=0;
	char ch;
	char number[12];
	char password[17];
	printf("������ѧ��ѧ�ţ���������Ϥ���ݿ��Խ������Աϵͳ�鿴ѧ����Ϣ�����������Ϊ000000��");
	gets(number);
	if((fp=fopen("E:\\student_information.bin","rb+"))==NULL)
	{
		printf("���ļ�����\n");
		exit(0);
	}
	while(1)
	{
		if(fread(&student,sizeof(stu_inf),1,fp)!=1)
		{
			i=0;
			break;
		}
		if(strcmp(student.stu_num,number)==0)
		{
			i=1;
			break;
		}
	}
	if(i==0)
	{
		printf("ϵͳ��û�и�ѧ����Ϣ��\n");
		fclose(fp);
	}
	else//����������֤��¼�������λ��ᣬ��getch()����������һ��������ʾ*��
	{
		printf("���������룺");
		while(1)
		{
			password[k]=getch();
			if(password[k]!='\r')
			{
				printf("*");
				k++;
			}
			else
				break;
		}
		password[k]='\0';
		k=0;
		if(strcmp(student.password,password)!=0)
		{
			printf("\n��������������������룺");
			while(1)
			{
				password[k]=getch();
				if(password[k]!='\r')
				{
					printf("*");
					k++;
				}
				else
					break;
			}
			password[k]='\0';
			k=0;
		}
		if(strcmp(student.password,password)!=0)
		{
			printf("\n��������������������룺");
			while(1)
			{
				password[k]=getch();
				if(password[k]!='\r')
				{
					printf("*");
					k++;
				}
				else
					break;
			}
			password[k]='\0';
			k=0;
		}
		if(strcmp(student.password,password)==0)
		{
			printf("\n��½�ɹ�\n1.�鿴��Ϣ\n2.�޸�����\n3.�˳���¼\n�����룺");
			scanf("%d",&i);
			getchar();
			while(i!=3)
			{
				if(i==1)
				{
					printf("---------------------------------------------------------------------------------------------------------\n");
					printf("| ��� |    ѧ��    |   ����  |  �Ա�  |  ��������  |  ʵ��  |  רҵѡ�� |  רҵ  |  רҵ����  |  ����  |\n");
					printf("---------------------------------------------------------------------------------------------------------\n");
					printf("|  1   |%-12s|  %-7s|   %-5s|  %-10s|  %-6.2f|   %-7.2f | %-7.2f|   %-9.2f| %-7.2f|\n",student.stu_num,student.stu_nam,student.sex,student.stu_bir,student.real,student.pro_cho,student.pro,student.bas_pro,student.bas);
					printf("---------------------------------------------------------------------------------------------------------\n");
				}
				else if(i==2)//�ٴ����������뷽����������޸�
				{
					printf("�����������룺");
					while(1)
					{
						while(1)
						{
							password[k]=getch();
							if(password[k]!='\r')
							{
								printf("*");
								k++;
							}
							else
								break;
						}
						password[k]='\0';
						k=0;
						printf("\n���������������룺");
						while(1)
						{
							student.password[k]=getch();
							if(student.password[k]!='\r')
							{
								printf("*");
								k++;
							}
							else
								break;
						}
						student.password[k]='\0';
						k=0;
						if(strcmp(password,student.password)==0)
							break;
						else
							printf("\n������������벻һ�������������룺");
					}
					printf("\nȷ���������룡��Y/N��");
					scanf("%c",&ch);
					getchar();
					if(ch=='Y' || ch=='y')
					{
						fseek(fp,-sizeof(stu_inf),SEEK_CUR); 
						fwrite(&student,sizeof(stu_inf),1,fp);
						printf("��ɣ�\n");
					}
				}
				printf("�����ѡ���ܣ�");
				scanf("%d",&i);
				getchar();
			}
		}
		else
			printf("�����������ϵ��ʦ��\n");
		fclose(fp);
	}
	printf("�����˳�ѧ��ϵͳ�����Ժ�....\n");
	Sleep(500);
	system("cls");//���ؽ���
	printf("**************************ѧ����Ϣ����***********************************\n");
	printf("                                                       ����11823020220����\n");
	printf("           1.����Աϵͳ    2.ѧ��ϵͳ     3.�˳�ϵͳ\n");
	printf("�������ȷ��ϵͳ��");
}
void find_one_student()//����ĳ��ѧ������Ϣ
{
	FILE *fp;
	stu_inf student;
	char num[12];
	int i=1;
	if((fp=fopen("E:\\student_information.bin","rb+"))==NULL)
	{
		printf("���ļ�����\n");
		exit(0);
	}
	printf("������ѧ�ţ�");
	gets(num);
	while((i=fread(&student,sizeof(stu_inf),1,fp))==1)
	{
		if(strcmp(num,student.stu_num)==0)
			break;
	}
	fclose(fp);
	if(i==1)
	{
		printf("---------------------------------------------------------------------------------------------------------\n");
		printf("| ��� |    ѧ��    |   ����  |  �Ա�  |  ��������  |  ʵ��  |  רҵѡ�� |  רҵ  |  רҵ����  |  ����  |\n");
		printf("---------------------------------------------------------------------------------------------------------\n");
		printf("|  1   |%-12s|  %-7s|   %-5s|  %-10s|  %-6.2f|   %-7.2f | %-7.2f|   %-9.2f| %-7.2f|\n",student.stu_num,student.stu_nam,student.sex,student.stu_bir,student.real,student.pro_cho,student.pro,student.bas_pro,student.bas);
		printf("---------------------------------------------------------------------------------------------------------\n");
	}
	else
		printf("���޴��˻�ѧ���������\n");
}
void find_class_student()//����һ���༶����Ϣ
{
	FILE *fp;
	stu_inf student;
	stu_link *head,*p,*p1,*p2;
	char cla[10];
	int i;
	printf("������༶�ţ�");
	gets(cla);
	head=calloc(1,sizeof(stu_link));
	head->nextaddr=NULL;
	if((fp=fopen("E:\\student_information.bin","rb+"))==NULL)
	{
		printf("���ļ�����\n");
		exit(0);
	}
	while(fread(&student,sizeof(stu_inf),1,fp)==1)//�Ѹð��ѧ������������
	{
		for(i=0;i<9;i++)
		{
			if(cla[i]!=student.stu_num[i])
				break;
		}
		if(i==9)
		{
			p=calloc(1,sizeof(stu_link));
			p->one_stu=student;
			p->nextaddr=head->nextaddr;
			head->nextaddr=p;
		}
	}
	fclose(fp);
	i=1;
	while(i==1)
	{
		i=0;
		p1=head;
		p=head->nextaddr;
		p2=head->nextaddr->nextaddr;
		while(p!=NULL)//��ð���������ѧ�ŵ�����
		{
			if(p2!=NULL)
			{
				if(strcmp(p->one_stu.stu_num,p2->one_stu.stu_num)>0)
				{
					p1->nextaddr=p2;
					p->nextaddr=p2->nextaddr;
					p2->nextaddr=p;
					i=1;
					p1=p2;
					p2=p->nextaddr;
				}
				else
				{
					p1=p1->nextaddr;
					p=p->nextaddr;
					p2=p2->nextaddr;
				}
			}
			else
				p=p2;
		}
	}
	p=head->nextaddr;
	i=1;
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("| ��� |    ѧ��    |   ����  |  �Ա�  |  ��������  |  ʵ��  |  רҵѡ�� |  רҵ  |  רҵ����  |  ����  |\n");
	printf("---------------------------------------------------------------------------------------------------------\n");
	while(p!=NULL)
	{
		printf("|  %-4d|%-12s|  %-7s|   %-5s|  %-10s|  %-6.2f|   %-7.2f | %-7.2f|   %-9.2f| %-7.2f|\n",i,p->one_stu.stu_num,p->one_stu.stu_nam,p->one_stu.sex,p->one_stu.stu_bir,p->one_stu.real,p->one_stu.pro_cho,p->one_stu.pro,p->one_stu.bas_pro,p->one_stu.bas);
		printf("---------------------------------------------------------------------------------------------------------\n");
		i++;
		p=p->nextaddr;

	}
	giveoff(head);
}
void find_not_pass_kind()//�鿴ĳ��γ�ѧ��δ����ѧ������
{
	FILE *fp;
	stu_inf student;
	int i,k;
	if((fp=fopen("E:\\student_information.bin","rb+"))==NULL)
	{
		printf("���ļ�����\n");
		exit(0);
	}
	printf("1.������ 2.רҵ������ 3.רҵ�� 4.רҵѡ�޿� 5.ʵ����\n");
	printf("�������Ӧ��ţ�(����0�˳�)");
	scanf("%d",&i);
	while(i)//����γ̣�����ж�
	{
		if(i==1)
		{
			k=1;
			printf("---------------------------------------------------------------------------------------------------------\n");
			printf("| ��� |    ѧ��    |   ����  |  �Ա�  |  ��������  |  ʵ��  |  רҵѡ�� |  רҵ  |  רҵ����  |  ����  |\n");
			printf("---------------------------------------------------------------------------------------------------------\n");
			while(fread(&student,sizeof(stu_inf),1,fp)==1)
			{
				if(student.bas<50)
				{
					printf("|  %-4d|%-12s|  %-7s|   %-5s|  %-10s|  %-6.2f|   %-7.2f | %-7.2f|   %-9.2f| %-7.2f|\n",k,student.stu_num,student.stu_nam,student.sex,student.stu_bir,student.real,student.pro_cho,student.pro,student.bas_pro,student.bas);
					printf("---------------------------------------------------------------------------------------------------------\n");
					k++;
				}
			}
			rewind(fp);
		}
		if(i==2)
		{
			k=1;
			printf("---------------------------------------------------------------------------------------------------------\n");
			printf("| ��� |    ѧ��    |   ����  |  �Ա�  |  ��������  |  ʵ��  |  רҵѡ�� |  רҵ  |  רҵ����  |  ����  |\n");
			printf("---------------------------------------------------------------------------------------------------------\n");
			while(fread(&student,sizeof(stu_inf),1,fp)==1)
			{
				if(student.bas_pro<50)
				{
					printf("|  %-4d|%-12s|  %-7s|   %-5s|  %-10s|  %-6.2f|   %-7.2f | %-7.2f|   %-9.2f| %-7.2f|\n",k,student.stu_num,student.stu_nam,student.sex,student.stu_bir,student.real,student.pro_cho,student.pro,student.bas_pro,student.bas);
					printf("---------------------------------------------------------------------------------------------------------\n");
					k++;
				}
			}
			rewind(fp);
		}
		if(i==3)
		{
			k=1;
			printf("---------------------------------------------------------------------------------------------------------\n");
			printf("| ��� |    ѧ��    |   ����  |  �Ա�  |  ��������  |  ʵ��  |  רҵѡ�� |  רҵ  |  רҵ����  |  ����  |\n");
			printf("---------------------------------------------------------------------------------------------------------\n");
			while(fread(&student,sizeof(stu_inf),1,fp)==1)
			{
				if(student.pro<36)
				{
					printf("|  %-4d|%-12s|  %-7s|   %-5s|  %-10s|  %-6.2f|   %-7.2f | %-7.2f|   %-9.2f| %-7.2f|\n",k,student.stu_num,student.stu_nam,student.sex,student.stu_bir,student.real,student.pro_cho,student.pro,student.bas_pro,student.bas);
					printf("---------------------------------------------------------------------------------------------------------\n");
					k++;
				}
			}
			rewind(fp);
		}
		if(i==4)
		{
			k=1;
			printf("---------------------------------------------------------------------------------------------------------\n");
			printf("| ��� |    ѧ��    |   ����  |  �Ա�  |  ��������  |  ʵ��  |  רҵѡ�� |  רҵ  |  רҵ����  |  ����  |\n");
			printf("---------------------------------------------------------------------------------------------------------\n");
			while(fread(&student,sizeof(stu_inf),1,fp)==1)
			{
				if(student.pro_cho<24)
				{
					printf("|  %-4d|%-12s|  %-7s|   %-5s|  %-10s|  %-6.2f|   %-7.2f | %-7.2f|   %-9.2f| %-7.2f|\n",k,student.stu_num,student.stu_nam,student.sex,student.stu_bir,student.real,student.pro_cho,student.pro,student.bas_pro,student.bas);
					printf("---------------------------------------------------------------------------------------------------------\n");
					k++;
				}
			}
			rewind(fp);
		}
		if(i==5)
		{
			k=1;
			printf("---------------------------------------------------------------------------------------------------------\n");
			printf("| ��� |    ѧ��    |   ����  |  �Ա�  |  ��������  |  ʵ��  |  רҵѡ�� |  רҵ  |  רҵ����  |  ����  |\n");
			printf("---------------------------------------------------------------------------------------------------------\n");
			while(fread(&student,sizeof(stu_inf),1,fp)==1)
			{
				if(student.real<40)
				{
					printf("|  %-4d|%-12s|  %-7s|   %-5s|  %-10s|  %-6.2f|   %-7.2f | %-7.2f|   %-9.2f| %-7.2f|\n",k,student.stu_num,student.stu_nam,student.sex,student.stu_bir,student.real,student.pro_cho,student.pro,student.bas_pro,student.bas);
					printf("---------------------------------------------------------------------------------------------------------\n");
					k++;
				}
			}
			rewind(fp);
		}
		printf("��������һ��γ���ţ�����0�˳�����");
		scanf("%d",&i);
	}
}
void find_class_notpass_student()//�鿴ĳ��δ���ҵҪ���ѧ������
{
	FILE *fp;
	stu_inf student;
	char cla[10];
	int i,j=1;
	printf("������༶�ţ�");
	gets(cla);
	if((fp=fopen("E:\\student_information.bin","rb+"))==NULL)
	{
		printf("���ļ�����\n");
		exit(0);
	}
	while(fread(&student,sizeof(stu_inf),1,fp)==1)
	{
		for(i=0;i<9;i++)//�ж��Ƿ���ָ���İ༶ѧ��
		{
			if(cla[i]!=student.stu_num[i])
				break;
		}
		if(i==9)
		{
			if(student.bas+student.bas_pro+student.pro+student.pro_cho+student.real<200)
			{
				if(j==1)
				{
					printf("---------------------------------------------------------------------------------------------------------\n");
					printf("| ��� |    ѧ��    |   ����  |  �Ա�  |  ��������  |  ʵ��  |  רҵѡ�� |  רҵ  |  רҵ����  |  ����  |\n");
					printf("---------------------------------------------------------------------------------------------------------\n");
				}
				printf("|  %-4d|%-12s|  %-7s|   %-5s|  %-10s|  %-6.2f|   %-7.2f | %-7.2f|   %-9.2f| %-7.2f|\n",j,student.stu_num,student.stu_nam,student.sex,student.stu_bir,student.real,student.pro_cho,student.pro,student.bas_pro,student.bas);
				printf("---------------------------------------------------------------------------------------------------------\n");
				j++;
			}
		}
	}
	if(j==1)
		printf("�ð�ȫ������\n");
	fclose(fp);
}
void all_not_pass_student()//�鿴����δ���ҵҪ���ѧ��
{
	FILE *fp;
	stu_inf student;
	int i;
	stu_link *head,*p,*p1,*p2;
	head=calloc(1,sizeof(stu_link));
	head->nextaddr=NULL;
	if((fp=fopen("E:\\student_information.bin","rb+"))==NULL)
	{
		printf("���ļ�����\n");
		exit(0);
	}
	while(fread(&student,sizeof(stu_inf),1,fp)==1)
	{
		if(student.bas+student.bas_pro+student.pro+student.pro_cho+student.real<200)
		{
			p=calloc(1,sizeof(stu_link));
			p->one_stu=student;
			p->nextaddr=head->nextaddr;
			head->nextaddr=p;
		}
	}
	fclose(fp);
	i=1;
	while(i==1)//��ð�����򷨽�������
	{
		i=0;
		p1=head;
		p=head->nextaddr;
		p2=head->nextaddr->nextaddr;
		while(p!=NULL)
		{
			if(p2!=NULL)
			{
				if((p->one_stu.bas+p->one_stu.bas_pro+p->one_stu.pro+p->one_stu.pro_cho+p->one_stu.real)>(p2->one_stu.bas+p2->one_stu.bas_pro+p2->one_stu.pro+p2->one_stu.pro_cho+p2->one_stu.real))
				{
					p1->nextaddr=p2;
					p->nextaddr=p2->nextaddr;
					p2->nextaddr=p;
					i=1;
					p1=p2;
					p2=p->nextaddr;
				}
				else
				{
					p1=p1->nextaddr;
					p=p->nextaddr;
					p2=p2->nextaddr;
				}
			}
			else
				p=p2;
		}
	}
	p=head->nextaddr;
	i=1;
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("| ��� |    ѧ��    |   ����  |  �Ա�  |  ��������  |  ʵ��  |  רҵѡ�� |  רҵ  |  רҵ����  |  ����  |\n");
	printf("---------------------------------------------------------------------------------------------------------\n");
	while(p!=NULL)
	{
		printf("|  %-4d|%-12s|  %-7s|   %-5s|  %-10s|  %-6.2f|   %-7.2f | %-7.2f|   %-9.2f| %-7.2f|\n",i,p->one_stu.stu_num,p->one_stu.stu_nam,p->one_stu.sex,p->one_stu.stu_bir,p->one_stu.real,p->one_stu.pro_cho,p->one_stu.pro,p->one_stu.bas_pro,p->one_stu.bas);
		printf("---------------------------------------------------------------------------------------------------------\n");
		i++;
		p=p->nextaddr;
	}
	giveoff(head);
}
void look_one_score()//�鿴ĳ��ѧ������ѧ��
{
	FILE *fp;
	stu_inf student;
	int i;
	float k;
	char number[12];
	printf("������ѧ��ѧ�ţ�");
	gets(number);
	if((fp=fopen("E:\\student_information.bin","rb+"))==NULL)
	{
		printf("���ļ�����\n");
		exit(0);
	}
	while(1)
	{
		if(fread(&student,sizeof(stu_inf),1,fp)!=1)
		{
			i=0;
			break;
		}
		if(strcmp(student.stu_num,number)==0)
		{
			i=1;
			break;
		}
	}
	if(i==0)
	{
		printf("ϵͳ��û�и�ѧ����Ϣ��\n");
	}
	else
	{
		k=student.bas+student.bas_pro+student.pro+student.pro_cho+student.real;
		printf("��������ѧ��Ϊ��%-5.2f\n",k);
	}
	fclose(fp);
}
void look_number_for_pass()//ͳ�ƿɱ�ҵ�벻�ɱ�ҵ�ڸ��������
{
	FILE *fp;
	stu_inf student;
	int i,pass=0,no_pass=0;
	stu_link *head,*p,*p1,*p2;
	head=calloc(1,sizeof(stu_link));
	head->nextaddr=NULL;
	if((fp=fopen("E:\\student_information.bin","rb+"))==NULL)
	{
		printf("���ļ�����\n");
		exit(0);
	}
	while(fread(&student,sizeof(stu_inf),1,fp)==1)
	{
		p=calloc(1,sizeof(stu_link));
		p->one_stu=student;
		p->nextaddr=head->nextaddr;
		head->nextaddr=p;
	}
	fclose(fp);
	i=1;
	while(i==1)//����ð������ѧ�Ŵ�С����
	{
		i=0;
		p1=head;
		p=head->nextaddr;
		p2=head->nextaddr->nextaddr;
		while(p!=NULL)
		{
			if(p2!=NULL)
			{
				if(strcmp(p->one_stu.stu_num,p2->one_stu.stu_num)>0)
				{
					p1->nextaddr=p2;
					p->nextaddr=p2->nextaddr;
					p2->nextaddr=p;
					i=1;
					p1=p2;
					p2=p->nextaddr;
				}
				else
				{
					p1=p1->nextaddr;
					p=p->nextaddr;
					p2=p2->nextaddr;
				}
			}
			else
				p=p2;
		}
	}
	p=head->nextaddr;
	p1=head->nextaddr;
	p2=head->nextaddr;
	printf("%c%c����\n",p->one_stu.stu_num[1],p->one_stu.stu_num[2]);//ѧ�ŵĵڶ�λ�͵���λΪ�꼶���ڰ�λ�͵ھ�λΪ�༶
	while(p!=NULL)
	{
		if(p->one_stu.stu_num[1]==p1->one_stu.stu_num[1] && p->one_stu.stu_num[2]==p1->one_stu.stu_num[2])//���꼶�������жϰ༶
		{
			if(p->one_stu.stu_num[7]==p2->one_stu.stu_num[7] && p->one_stu.stu_num[8]==p2->one_stu.stu_num[8])
			{
				p2=p;
				if(p->one_stu.bas+p->one_stu.bas_pro+p->one_stu.pro+p->one_stu.pro_cho+p->one_stu.real<200)
					no_pass++;
				else
					pass++;
			}
			else//���༶�ı�ʱ�����¼�İ����Ϣ
			{
				if(p2->one_stu.stu_num[7]!='0')
				printf("%c%c���У�δ���ҵҪ��������%-2d,�ﵽ��ҵҪ��������%-2d\n",p2->one_stu.stu_num[7],p2->one_stu.stu_num[8],no_pass,pass);
				else
				printf("%c���У�δ���ҵҪ��������%-2d,�ﵽ��ҵҪ��������%-2d\n",p2->one_stu.stu_num[8],no_pass,pass);
				p2=p;
				pass=0;
				no_pass=0;
				if(p->one_stu.bas+p->one_stu.bas_pro+p->one_stu.pro+p->one_stu.pro_cho+p->one_stu.real<200)
					no_pass++;
				else
					pass++;
			}
		}
		else//���꼶�ı�ʱ�������¼�İ����Ϣ
		{
			if(p2->one_stu.stu_num[7]!='0')
			printf("%c%c���У�δ���ҵҪ��������%-2d,�ﵽ��ҵҪ��������%-2d\n",p2->one_stu.stu_num[7],p2->one_stu.stu_num[8],no_pass,pass);
			else
			printf("%c���У�δ���ҵҪ��������%-2d,�ﵽ��ҵҪ��������%-2d\n",p2->one_stu.stu_num[8],no_pass,pass);
			p2=p;
			pass=0;
			no_pass=0;
			printf("%c%c����\n",p->one_stu.stu_num[1],p->one_stu.stu_num[2]);
			p1=p;//�꼶�ı�ʱ��p1�ı�
			p=p2;//��pǰ��һλ�������꼶�ı䵼�µ���Ϣȱʧ
			p2=p1;//���ð༶
		}
		p=p->nextaddr;
		if(p==NULL)
		{
			if(p2->one_stu.stu_num[7]!='0')
			printf("%c%c���У�δ���ҵҪ��������%-2d,�ﵽ��ҵҪ��������%-2d\n",p2->one_stu.stu_num[7],p2->one_stu.stu_num[8],no_pass,pass);
			else
			printf("%c���У�δ���ҵҪ��������%-2d,�ﵽ��ҵҪ��������%-2d\n",p2->one_stu.stu_num[8],no_pass,pass);
		}
	}
}
void class_score()//�鿴����γ�δ��������
{
	int base=0,base_profe=0,profe=0,profe_choos=0,real=0;
	FILE *fp;
	stu_inf student;
	if((fp=fopen("E:\\student_information.bin","rb+"))==NULL)
	{
		printf("���ļ�����\n");
		exit(0);
	}
	while(fread(&student,sizeof(stu_inf),1,fp)==1)
	{
		if(student.bas<50)
			base++;
		if(student.bas_pro<50)
			base_profe++;
		if(student.pro<36)
			profe++;
		if(student.pro_cho<24)
			profe_choos++;
		if(student.real<40)
			real++;
	}
	fclose(fp);
	printf("����γ�δ���ҵҪ����������\n�����ࣺ%-2d,רҵ�����ࣺ%-2d,רҵ�ࣺ%-2d,רҵѡ���ࣺ%-2d,ʵ���ࣺ%-2d\n",base,base_profe,profe,profe_choos,real);
}
