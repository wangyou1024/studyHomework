typedef struct student_information
{
	char stu_num[12];//学号，其中含有班级信息
	char stu_nam[8];//姓名
	char sex[4];//性别
	char stu_bir[11];//生日
	float bas;//基础类
	float bas_pro;//专业基础类
	float pro;//专业类
	float pro_cho;//专业选修类
	float real;//实践类
	char password[17];//密码
}stu_inf;
typedef struct student_link//制作链表的结构体
{
	stu_inf one_stu;
	struct student_link *nextaddr;
}stu_link;
void giveoff(stu_link *head)//释放动态内存
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
void view_all_inf()//浏览全部信息
{
	stu_inf student;
	FILE *fp;
	int i=1;
	if((fp=fopen("E:\\student_information.bin","rb+"))==NULL)
	{
		printf("打开文件错误！\n");
		exit(0);
	}
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("| 序号 |    学号    |   姓名  |  性别  |  出生日期  |  实践  |  专业选修 |  专业  |  专业基础  |  基础  |\n");
	printf("---------------------------------------------------------------------------------------------------------\n");
	while(fread(&student,sizeof(stu_inf),1,fp)==1)
	{
		printf("|  %-4d|%-12s|  %-7s|   %-5s|  %-10s|  %-6.2f|   %-7.2f | %-7.2f|   %-9.2f| %-7.2f|\n",i,student.stu_num,student.stu_nam,student.sex,student.stu_bir,student.real,student.pro_cho,student.pro,student.bas_pro,student.bas);
		printf("---------------------------------------------------------------------------------------------------------\n");
		i++;
	}
	fclose(fp);
}
void add_information()//添加学生信息函数
{
	FILE *fp;
	stu_inf student;
	if((fp=fopen("E:\\student_information.bin","ab"))==NULL)
	{
		printf("添加时打开文件失败！");
		exit(0);
	}
	printf("请输入学号：");
	gets(student.stu_num);
	printf("请输入姓名：");
	gets(student.stu_nam);
	printf("请输入性别：");
	gets(student.sex);
	printf("请输入出生日期：");
	gets(student.stu_bir);
	printf("请输入各项成绩( 实践,专业选修,专业,专业基础,基础),用空格间隔：");
	scanf("%f%f%f%f%f",&student.real,&student.pro_cho,&student.pro,&student.bas_pro,&student.bas);
	strcpy(student.password,"000000");
	fwrite(&student,sizeof(stu_inf),1,fp);
	printf("完成\n");
	fclose(fp);
	Sleep(500);
}
void modification_stu_inf()//修改学生信息
{
	stu_inf student;
	FILE *fp;
	int i;
	char Y;
	char number[12];
	printf("请输入学生学号：");
	gets(number);
	if((fp=fopen("E:\\student_information.bin","rb+"))==NULL)
	{
		printf("打开文件错误！\n");
		exit(0);
	}
	while(1)//寻找学生信息与文件中的位置
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
		printf("系统中没有该学生信息！\n");
	else
	{
		printf("---------------------------------------------------------------------------------------------------------\n");
		printf("| 序号 |    学号    |   姓名  |  性别  |  出生日期  |  实践  |  专业选修 |  专业  |  专业基础  |  基础  |\n");
		printf("---------------------------------------------------------------------------------------------------------\n");
		printf("|  1   |%-12s|  %-7s|   %-5s|  %-10s|  %-6.2f|   %-7.2f | %-7.2f|   %-9.2f| %-7.2f|\n",student.stu_num,student.stu_nam,student.sex,student.stu_bir,student.real,student.pro_cho,student.pro,student.bas_pro,student.bas);
		printf("---------------------------------------------------------------------------------------------------------\n");
		printf("1.学号 2.姓名 3.性别  4.出生日期  5.基础课学分  6.专业基础课学分  7.专业课学分  8.专业选修课学分  9.实践类学分\n");
		printf("请输入相应的序号进行修改（输入0，完成修改）：");
		scanf("%d",&i);
		getchar();
		while(i)//修改学生信息，循环修改不同信息
		{
			if(i==1)
			{
				printf("请输入新学号：");
				gets(student.stu_num);
			}
			else if(i==2)
			{
				printf("请输入新姓名：");
				gets(student.stu_nam);
			}
			else if(i==3)
			{
				printf("请输入性别：");
				gets(student.sex);
			}
			else if(i==4)
			{
				printf("请输入出生日期（格式1999-8-14）");
				gets(student.stu_bir);
			}
			else if(i==5)
			{
				printf("请输入基础课学分：");
				scanf("%f",&student.bas);
			}
			else if(i==6)
			{
				printf("请输入专业基础课学分：");
				scanf("%f",&student.bas_pro);
			}
			else if(i==7)
			{
				printf("请输入专业课学分 ：");
				scanf("%f",&student.pro);
			}
			else if(i==8)
			{
				printf("请输入专业选修课学分：");
				scanf("%f",&student.pro_cho);
			}
			else if(i==9)
			{
				printf("请输入实践课学分：");
				scanf("%f",&student.real);
			}
			else
				i=0;
			printf("请输入下一项修改内容或退出：");
			scanf("%d",&i);
			getchar();
		}
		printf("---------------------------------------------------------------------------------------------------------\n");
		printf("| 序号 |    学号    |   姓名  |  性别  |  出生日期  |  实践  |  专业选修 |  专业  |  专业基础  |  基础  |\n");
		printf("---------------------------------------------------------------------------------------------------------\n");
		printf("|  1   |%-12s|  %-7s|   %-5s|  %-10s|  %-6.2f|   %-7.2f | %-7.2f|   %-9.2f| %-7.2f|\n",student.stu_num,student.stu_nam,student.sex,student.stu_bir,student.real,student.pro_cho,student.pro,student.bas_pro,student.bas);
		printf("---------------------------------------------------------------------------------------------------------\n");
		printf("是否确认（Y/N）");
		scanf("%c",&Y);
		if(Y=='y' || Y=='Y')
		{
			fseek(fp,-sizeof(stu_inf),SEEK_CUR);//文件指针前移一个结构体空间
			fwrite(&student,sizeof(stu_inf),1,fp);//用新信息覆盖原位的信息，
			printf("完成！\n");
		}	
	}
	fclose(fp);
}
void del_inf()//删除学生信息
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
		printf("打开文件错误！\n");
		exit(0);
	}
	printf("请输入需要删除的学生学号：");
	gets(num);
	while(fread(&student,sizeof(stu_inf),1,fp)==1)//将除指定学生外的学生信息加入链表中
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
			printf("| 序号 |    学号    |   姓名  |  性别  |  出生日期  |  实践  |  专业选修 |  专业  |  专业基础  |  基础  |\n");
			printf("---------------------------------------------------------------------------------------------------------\n");
			printf("|  1   |%-12s|  %-7s|   %-5s|  %-10s|  %-6.2f|   %-7.2f | %-7.2f|   %-9.2f| %-7.2f|\n",student.stu_num,student.stu_nam,student.sex,student.stu_bir,student.real,student.pro_cho,student.pro,student.bas_pro,student.bas);
			printf("---------------------------------------------------------------------------------------------------------\n");
		}
	}
	fclose(fp);
	if(i==1)//若有该学生就可以重写文件，将链表中的信息写入新文件，新文件与原文件同名，以便覆盖旧文件
	{
		if((fp=fopen("E:\\student_information.bin","wb"))==NULL)
		{
			printf("打开文件错误！\n");
			exit(0);
		}
		p=head->nextaddr;
		while(p!=NULL)
		{
			student=p->one_stu;
			fwrite(&student,sizeof(stu_inf),1,fp);
			p=p->nextaddr;
		}
		printf("删除完毕！\n");
	}
	else
		printf("查无此人");
	giveoff(head);
	fclose(fp);
}
void re_password()//重置密码
{
	stu_inf student;
	FILE *fp;
	int i;
	char ch;
	char number[12];
	printf("请输入学生学号：");
	gets(number);
	if((fp=fopen("E:\\student_information.bin","rb+"))==NULL)
	{
		printf("打开文件错误！\n");
		exit(0);
	}
	while(1)//找到指定学生，
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
		printf("系统中没有该学生信息！\n");
		fclose(fp);
	}
	else
	{
		printf("---------------------------------------------------------------------------------------------------------\n");
		printf("| 序号 |    学号    |   姓名  |  性别  |  出生日期  |  实践  |  专业选修 |  专业  |  专业基础  |  基础  |\n");
		printf("---------------------------------------------------------------------------------------------------------\n");
		printf("|  1   |%-12s|  %-7s|   %-5s|  %-10s|  %-6.2f|   %-7.2f | %-7.2f|   %-9.2f| %-7.2f|\n",student.stu_num,student.stu_nam,student.sex,student.stu_bir,student.real,student.pro_cho,student.pro,student.bas_pro,student.bas);
		printf("---------------------------------------------------------------------------------------------------------\n");
		printf("确认重置密码！（Y/N）");
		scanf("%c",&ch);
		getchar();
		if(ch=='Y' || ch=='y')
		{
			strcpy(student.password,"000000");//将学生的密码重置并写入文件
			fseek(fp,-sizeof(stu_inf),SEEK_CUR); 
			fwrite(&student,sizeof(stu_inf),1,fp);
			printf("完成！\n");
		}
		fclose(fp);
	}
}
void for_student()//建立学生系统
{
	FILE *fp;
	stu_inf student;
	int i,k=0;
	char ch;
	char number[12];
	char password[17];
	printf("请输入学生学号：（若不熟悉内容可以进入管理员系统查看学生信息，重置密码后为000000）");
	gets(number);
	if((fp=fopen("E:\\student_information.bin","rb+"))==NULL)
	{
		printf("打开文件错误！\n");
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
		printf("系统中没有该学生信息！\n");
		fclose(fp);
	}
	else//输入密码验证登录，有三次机会，用getch()函数，输入一个数字显示*号
	{
		printf("请输入密码：");
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
			printf("\n密码错误，请重新输入密码：");
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
			printf("\n密码错误，请重新输入密码：");
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
			printf("\n登陆成功\n1.查看信息\n2.修改密码\n3.退出登录\n请输入：");
			scanf("%d",&i);
			getchar();
			while(i!=3)
			{
				if(i==1)
				{
					printf("---------------------------------------------------------------------------------------------------------\n");
					printf("| 序号 |    学号    |   姓名  |  性别  |  出生日期  |  实践  |  专业选修 |  专业  |  专业基础  |  基础  |\n");
					printf("---------------------------------------------------------------------------------------------------------\n");
					printf("|  1   |%-12s|  %-7s|   %-5s|  %-10s|  %-6.2f|   %-7.2f | %-7.2f|   %-9.2f| %-7.2f|\n",student.stu_num,student.stu_nam,student.sex,student.stu_bir,student.real,student.pro_cho,student.pro,student.bas_pro,student.bas);
					printf("---------------------------------------------------------------------------------------------------------\n");
				}
				else if(i==2)//再次输入新密码方可完成密码修改
				{
					printf("请输入新密码：");
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
						printf("\n请重新输入新密码：");
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
							printf("\n两次输入的密码不一样，请重新输入：");
					}
					printf("\n确认重置密码！（Y/N）");
					scanf("%c",&ch);
					getchar();
					if(ch=='Y' || ch=='y')
					{
						fseek(fp,-sizeof(stu_inf),SEEK_CUR); 
						fwrite(&student,sizeof(stu_inf),1,fp);
						printf("完成！\n");
					}
				}
				printf("请继续选择功能：");
				scanf("%d",&i);
				getchar();
			}
		}
		else
			printf("密码错误，请联系老师！\n");
		fclose(fp);
	}
	printf("正在退出学生系统，请稍后....\n");
	Sleep(500);
	system("cls");//重载界面
	printf("**************************学分信息管理***********************************\n");
	printf("                                                       ——11823020220王游\n");
	printf("           1.管理员系统    2.学生系统     3.退出系统\n");
	printf("请进入正确的系统：");
}
void find_one_student()//查找某个学生的信息
{
	FILE *fp;
	stu_inf student;
	char num[12];
	int i=1;
	if((fp=fopen("E:\\student_information.bin","rb+"))==NULL)
	{
		printf("打开文件错误！\n");
		exit(0);
	}
	printf("请输入学号：");
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
		printf("| 序号 |    学号    |   姓名  |  性别  |  出生日期  |  实践  |  专业选修 |  专业  |  专业基础  |  基础  |\n");
		printf("---------------------------------------------------------------------------------------------------------\n");
		printf("|  1   |%-12s|  %-7s|   %-5s|  %-10s|  %-6.2f|   %-7.2f | %-7.2f|   %-9.2f| %-7.2f|\n",student.stu_num,student.stu_nam,student.sex,student.stu_bir,student.real,student.pro_cho,student.pro,student.bas_pro,student.bas);
		printf("---------------------------------------------------------------------------------------------------------\n");
	}
	else
		printf("查无此人或学号输入错误！\n");
}
void find_class_student()//查找一个班级的信息
{
	FILE *fp;
	stu_inf student;
	stu_link *head,*p,*p1,*p2;
	char cla[10];
	int i;
	printf("请输入班级号：");
	gets(cla);
	head=calloc(1,sizeof(stu_link));
	head->nextaddr=NULL;
	if((fp=fopen("E:\\student_information.bin","rb+"))==NULL)
	{
		printf("打开文件错误！\n");
		exit(0);
	}
	while(fread(&student,sizeof(stu_inf),1,fp)==1)//把该班的学生加入链表中
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
		while(p!=NULL)//有冒泡排序法完成学号的排序
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
	printf("| 序号 |    学号    |   姓名  |  性别  |  出生日期  |  实践  |  专业选修 |  专业  |  专业基础  |  基础  |\n");
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
void find_not_pass_kind()//查看某类课程学分未满的学生名单
{
	FILE *fp;
	stu_inf student;
	int i,k;
	if((fp=fopen("E:\\student_information.bin","rb+"))==NULL)
	{
		printf("打开文件错误！\n");
		exit(0);
	}
	printf("1.基础课 2.专业基础课 3.专业课 4.专业选修课 5.实践课\n");
	printf("请输入对应序号：(输入0退出)");
	scanf("%d",&i);
	while(i)//五类课程，五个判断
	{
		if(i==1)
		{
			k=1;
			printf("---------------------------------------------------------------------------------------------------------\n");
			printf("| 序号 |    学号    |   姓名  |  性别  |  出生日期  |  实践  |  专业选修 |  专业  |  专业基础  |  基础  |\n");
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
			printf("| 序号 |    学号    |   姓名  |  性别  |  出生日期  |  实践  |  专业选修 |  专业  |  专业基础  |  基础  |\n");
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
			printf("| 序号 |    学号    |   姓名  |  性别  |  出生日期  |  实践  |  专业选修 |  专业  |  专业基础  |  基础  |\n");
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
			printf("| 序号 |    学号    |   姓名  |  性别  |  出生日期  |  实践  |  专业选修 |  专业  |  专业基础  |  基础  |\n");
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
			printf("| 序号 |    学号    |   姓名  |  性别  |  出生日期  |  实践  |  专业选修 |  专业  |  专业基础  |  基础  |\n");
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
		printf("请输入下一项课程序号（输入0退出）：");
		scanf("%d",&i);
	}
}
void find_class_notpass_student()//查看某班未达毕业要求的学生名单
{
	FILE *fp;
	stu_inf student;
	char cla[10];
	int i,j=1;
	printf("请输入班级号：");
	gets(cla);
	if((fp=fopen("E:\\student_information.bin","rb+"))==NULL)
	{
		printf("打开文件错误！\n");
		exit(0);
	}
	while(fread(&student,sizeof(stu_inf),1,fp)==1)
	{
		for(i=0;i<9;i++)//判断是否是指定的班级学生
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
					printf("| 序号 |    学号    |   姓名  |  性别  |  出生日期  |  实践  |  专业选修 |  专业  |  专业基础  |  基础  |\n");
					printf("---------------------------------------------------------------------------------------------------------\n");
				}
				printf("|  %-4d|%-12s|  %-7s|   %-5s|  %-10s|  %-6.2f|   %-7.2f | %-7.2f|   %-9.2f| %-7.2f|\n",j,student.stu_num,student.stu_nam,student.sex,student.stu_bir,student.real,student.pro_cho,student.pro,student.bas_pro,student.bas);
				printf("---------------------------------------------------------------------------------------------------------\n");
				j++;
			}
		}
	}
	if(j==1)
		printf("该班全部及格！\n");
	fclose(fp);
}
void all_not_pass_student()//查看所有未达毕业要求的学生
{
	FILE *fp;
	stu_inf student;
	int i;
	stu_link *head,*p,*p1,*p2;
	head=calloc(1,sizeof(stu_link));
	head->nextaddr=NULL;
	if((fp=fopen("E:\\student_information.bin","rb+"))==NULL)
	{
		printf("打开文件错误！\n");
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
	while(i==1)//用冒泡排序法进行排序
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
	printf("| 序号 |    学号    |   姓名  |  性别  |  出生日期  |  实践  |  专业选修 |  专业  |  专业基础  |  基础  |\n");
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
void look_one_score()//查看某个学生的总学分
{
	FILE *fp;
	stu_inf student;
	int i;
	float k;
	char number[12];
	printf("请输入学生学号：");
	gets(number);
	if((fp=fopen("E:\\student_information.bin","rb+"))==NULL)
	{
		printf("打开文件错误！\n");
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
		printf("系统中没有该学生信息！\n");
	}
	else
	{
		k=student.bas+student.bas_pro+student.pro+student.pro_cho+student.real;
		printf("请生的总学分为：%-5.2f\n",k);
	}
	fclose(fp);
}
void look_number_for_pass()//统计可毕业与不可毕业在各班的人数
{
	FILE *fp;
	stu_inf student;
	int i,pass=0,no_pass=0;
	stu_link *head,*p,*p1,*p2;
	head=calloc(1,sizeof(stu_link));
	head->nextaddr=NULL;
	if((fp=fopen("E:\\student_information.bin","rb+"))==NULL)
	{
		printf("打开文件错误！\n");
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
	while(i==1)//先用冒泡排序按学号从小到大
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
	printf("%c%c级：\n",p->one_stu.stu_num[1],p->one_stu.stu_num[2]);//学号的第二位和第三位为年级，第八位和第九位为班级
	while(p!=NULL)
	{
		if(p->one_stu.stu_num[1]==p1->one_stu.stu_num[1] && p->one_stu.stu_num[2]==p1->one_stu.stu_num[2])//当年级不变是判断班级
		{
			if(p->one_stu.stu_num[7]==p2->one_stu.stu_num[7] && p->one_stu.stu_num[8]==p2->one_stu.stu_num[8])
			{
				p2=p;
				if(p->one_stu.bas+p->one_stu.bas_pro+p->one_stu.pro+p->one_stu.pro_cho+p->one_stu.real<200)
					no_pass++;
				else
					pass++;
			}
			else//当班级改变时输出记录的班的信息
			{
				if(p2->one_stu.stu_num[7]!='0')
				printf("%c%c班中，未达毕业要求人数：%-2d,达到毕业要求人数：%-2d\n",p2->one_stu.stu_num[7],p2->one_stu.stu_num[8],no_pass,pass);
				else
				printf("%c班中，未达毕业要求人数：%-2d,达到毕业要求人数：%-2d\n",p2->one_stu.stu_num[8],no_pass,pass);
				p2=p;
				pass=0;
				no_pass=0;
				if(p->one_stu.bas+p->one_stu.bas_pro+p->one_stu.pro+p->one_stu.pro_cho+p->one_stu.real<200)
					no_pass++;
				else
					pass++;
			}
		}
		else//当年级改变时，输出记录的班的信息
		{
			if(p2->one_stu.stu_num[7]!='0')
			printf("%c%c班中，未达毕业要求人数：%-2d,达到毕业要求人数：%-2d\n",p2->one_stu.stu_num[7],p2->one_stu.stu_num[8],no_pass,pass);
			else
			printf("%c班中，未达毕业要求人数：%-2d,达到毕业要求人数：%-2d\n",p2->one_stu.stu_num[8],no_pass,pass);
			p2=p;
			pass=0;
			no_pass=0;
			printf("%c%c级：\n",p->one_stu.stu_num[1],p->one_stu.stu_num[2]);
			p1=p;//年级改变时，p1改变
			p=p2;//将p前移一位，避免年级改变导致的信息缺失
			p2=p1;//重置班级
		}
		p=p->nextaddr;
		if(p==NULL)
		{
			if(p2->one_stu.stu_num[7]!='0')
			printf("%c%c班中，未达毕业要求人数：%-2d,达到毕业要求人数：%-2d\n",p2->one_stu.stu_num[7],p2->one_stu.stu_num[8],no_pass,pass);
			else
			printf("%c班中，未达毕业要求人数：%-2d,达到毕业要求人数：%-2d\n",p2->one_stu.stu_num[8],no_pass,pass);
		}
	}
}
void class_score()//查看各类课程未达标的人数
{
	int base=0,base_profe=0,profe=0,profe_choos=0,real=0;
	FILE *fp;
	stu_inf student;
	if((fp=fopen("E:\\student_information.bin","rb+"))==NULL)
	{
		printf("打开文件错误！\n");
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
	printf("各类课程未达毕业要求人数如下\n基础类：%-2d,专业基础类：%-2d,专业类：%-2d,专业选修类：%-2d,实践类：%-2d\n",base,base_profe,profe,profe_choos,real);
}
