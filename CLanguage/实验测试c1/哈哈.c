#include<string.h>
#include<stdio.h>
/*============================workB5开始==============================*/ 
/*
	5、编写函数，删除数组中指定的字符（假设所有元素唯一）。
	建议函数原型：void delch(char *string,char ch)
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
	printf("请输入一串字符串(少于30个)：");
	gets(str); 
	
	fflush(stdin);
	printf("\n请输入要删去的字符："); 
	scanf("%c",&ch);
	
	delch(str,ch);
	
	printf("输出更改后的字符串：");
	puts(str);
	
	return 0;
}
/*============================workB5结束==============================*/


/*============================workB6开始==============================*/ 
/*
	6、编写函数，在字符串中查询指定的字符并返回其下标。 
	建议函数原型：int searchch(char *string,char ch) 
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
	printf("请输入一串字符串(少于30个)：");
	gets(str); 
	
	fflush(stdin);
	printf("\n请输入要查询的字符："); 
	scanf("%c",&ch);
	
	i=searchch(str,ch);
	
	printf("该字符的下标为：%d\n",i);
	
	return 0;
}
/*============================workB6结束==============================*/

18-软工-高毅 2018/12/15 20:09:43
/*============================workB11开始=============================*/ 
/*
	11、编写函数，判断字符串s2是否被包含在s1中
	建议函数原型：char *strin(char *s1,char *s2) 
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
	printf("请分别输入原始字符串和判断字符串中字符个数：");
	scanf("%d%d",&len1,&len2); 
	
	char *str1=(char *)malloc((len1+1)*sizeof(char));
	char *str2=(char *)malloc((len2+1)*sizeof(char));
	
	fflush(stdin); 
	printf("请输入原始数组：");
	gets(str1);
	
	fflush(stdin);
	printf("请输入判断数组：");
	gets(str2); 
	
	char *address=strin(str1,str2);
	
	if(*address!='\0')
	{
		printf("%d,%c\n",address,*(address));
	}
	else
	{
		printf("原始字符串不包含判断字符串。\n");
	}

	free(str1);
	str1=NULL;
	free(str2);
	str2=NULL;
	
	return 0;
} 
/*============================workB11结束=============================*/
