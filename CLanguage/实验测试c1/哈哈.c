#include<string.h>
#include<stdio.h>
/*============================workB5��ʼ==============================*/ 
/*
	5����д������ɾ��������ָ�����ַ�����������Ԫ��Ψһ����
	���麯��ԭ�ͣ�void delch(char *string,char ch)
*/ 
void delch(char *string,char ch)
{
	int i;
	int j;
	
	for(i=0;*(string+i)!='\0';i++)
	{
		if(*(string+i)==ch)
		{
			for(j=i;*(string+j+1)!='\0';j++)
			{
				*(string+j)=*(string+j+1);
			}
			*(string+j)='\0';
		}
	}
}
int workB5()
{
	char str[30];
	char ch;
	
	fflush(stdin);
	printf("������һ���ַ���(����30��)��");
	gets(str); 
	
	fflush(stdin);
	printf("\n������Ҫɾȥ���ַ���"); 
	scanf("%c",&ch);
	
	delch(str,ch);
	
	printf("������ĺ���ַ�����");
	puts(str);
	
	return 0;
}
/*============================workB5����==============================*/


/*============================workB6��ʼ==============================*/ 
/*
	6����д���������ַ����в�ѯָ�����ַ����������±ꡣ 
	���麯��ԭ�ͣ�int searchch(char *string,char ch) 
*/ 
int searchch(char *string,char ch)
{
	int temp;
	
	for(temp=0;*(string+temp)!='\0';temp++)
	{
		if(*(string+temp)==ch)
		{
			return temp;
		}
	}
	return -1;
}
int workB6()
{
	char str[30];
	char ch;
	int i;
	
	fflush(stdin);
	printf("������һ���ַ���(����30��)��");
	gets(str); 
	
	fflush(stdin);
	printf("\n������Ҫ��ѯ���ַ���"); 
	scanf("%c",&ch);
	
	i=searchch(str,ch);
	
	printf("���ַ����±�Ϊ��%d\n",i);
	
	return 0;
}
/*============================workB6����==============================*/

18-��-���� 2018/12/15 20:09:43
/*============================workB11��ʼ=============================*/ 
/*
	11����д�������ж��ַ���s2�Ƿ񱻰�����s1��
	���麯��ԭ�ͣ�char *strin(char *s1,char *s2) 
*/ 
char *strin(char *s1,char *s2)
{
	int temp=0,i=0,flag=0,tem=0;
	
	for(temp=0;*(s1+temp)!='\0';temp++)
	{
		if(*(s1+temp)=*s2)
		{
			tem=temp;
			for(i=0;*(s1+tem)!='\0' && *(s2+i)!='\0';tem++,i++)
			{
				if(*(s1+tem)==*(s2+i))
				{
					flag=1;
				}
				else
				{
					flag=0;
					break;
				}
			}
			if(flag==1 && *(s2+i)=='\0')
			{
				return (s1+temp);	
			}
			else
			{
				return (s1+temp+1);
			}
		}
	}
}
int workB11()
{
	int len1,len2;
	printf("��ֱ�����ԭʼ�ַ������ж��ַ������ַ�������");
	scanf("%d%d",&len1,&len2); 
	
	char *str1=(char *)malloc((len1+1)*sizeof(char));
	char *str2=(char *)malloc((len2+1)*sizeof(char));
	
	fflush(stdin); 
	printf("������ԭʼ���飺");
	gets(str1);
	
	fflush(stdin);
	printf("�������ж����飺");
	gets(str2); 
	
	char *address=strin(str1,str2);
	
	if(*address!='\0')
	{
		printf("%d,%c\n",address,*(address));
	}
	else
	{
		printf("ԭʼ�ַ����������ж��ַ�����\n");
	}

	free(str1);
	str1=NULL;
	free(str2);
	str2=NULL;
	
	return 0;
} 
/*============================workB11����=============================*/
