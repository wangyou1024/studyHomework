#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *R_order(char func[5],int rd,int rs,int rt){
	char *order=calloc(16,sizeof(char));
	*order='0';
	*(order+1)='0';
	*(order+2)='0';
	*(order+3)='0';
	
	if(rs>=2)
		*(order+4)='1';
	else
		*(order+4)='0';
	if(rs%2==1)
		*(order+5)='1';
	else
		*(order+5)='0';
	
	if(rt>=2)
		*(order+6)='1';
	else
		*(order+6)='0';
	if(rt%2==1)
		*(order+7)='1';
	else
		*(order+7)='0';
	
	if(rd>=2)
		*(order+8)='1';
	else
		*(order+8)='0';
	if(rd%2==1)
		*(order+9)='1';
	else
		*(order+9)='0';
	*(order+10)='0';
	*(order+11)='0';
	*(order+12)='0';

	if(strcmp(func,"or")==0)
	{
		*(order+13)='0';
		*(order+14)='0';
		*(order+15)='0';
	}
	if(strcmp(func,"and")==0)
	{
		*(order+13)='0';
		*(order+14)='0';
		*(order+15)='1';
	}
	if(strcmp(func,"add")==0)
	{
		*(order+13)='0';
		*(order+14)='1';
		*(order+15)='0';
	}
	if(strcmp(func,"sub")==0)
	{
		*(order+13)='0';
		*(order+14)='1';
		*(order+15)='1';
	}
	if(strcmp(func,"sllv")==0)
	{
		*(order+13)='1';
		*(order+14)='0';
		*(order+15)='0';
	}
	if(strcmp(func,"srlv")==0)
	{
		*(order+13)='1';
		*(order+14)='0';
		*(order+15)='1';
	}
	if(strcmp(func,"srav")==0)
	{
		*(order+13)='1';
		*(order+14)='1';
		*(order+15)='0';
	}
	if(strcmp(func,"slt")==0)
	{
		*(order+13)='1';
		*(order+14)='1';
		*(order+15)='1';
	}
	return order;
}
char *I_order(char func[5],int rt,int rs,int immediate){
	char *order=calloc(16,sizeof(char));
	int i;
	if(strcmp(func,"ori")==0)
	{
		*order='0';
		*(order+1)='0';
		*(order+2)='0';
		*(order+3)='1';
	}
	if(strcmp(func,"andi")==0)
	{
		*order='0';
		*(order+1)='0';
		*(order+2)='1';
		*(order+3)='0';
	}
	if(strcmp(func,"addi")==0)
	{
		*order='0';
		*(order+1)='0';
		*(order+2)='1';
		*(order+3)='1';
	}
	if(strcmp(func,"lw")==0)
	{
		*order='0';
		*(order+1)='1';
		*(order+2)='0';
		*(order+3)='0';
	}
	if(strcmp(func,"sw")==0)
	{
		*order='0';
		*(order+1)='1';
		*(order+2)='0';
		*(order+3)='1';
	}
	if(strcmp(func,"beq")==0)
	{
		*order='0';
		*(order+1)='1';
		*(order+2)='1';
		*(order+3)='0';
	}
	if(strcmp(func,"bgt")==0)
	{
		*order='0';
		*(order+1)='1';
		*(order+2)='1';
		*(order+3)='1';
	}
	if(rs>=2)
		*(order+4)='1';
	else
		*(order+4)='0';
	if(rs%2==1)
		*(order+5)='1';
	else
		*(order+5)='0';

	if(rt>=2)
		*(order+6)='1';
	else
		*(order+6)='0';
	if(rt%2==1)
		*(order+7)='1';
	else
		*(order+7)='0';
	for(i=15;i>=8;i--){
		*(order+i)=immediate%2+'0';
		immediate=immediate/2;
	}
	return order;
}
char *beq_bgt(char func[5],int rs,int rt,int offset){
	char *order=calloc(16,sizeof(char));
	int i;
	if(strcmp(func,"beq")==0)
	{
		*order='0';
		*(order+1)='1';
		*(order+2)='1';
		*(order+3)='0';
	}
	if(strcmp(func,"bgt")==0)
	{
		*order='0';
		*(order+1)='1';
		*(order+2)='1';
		*(order+3)='1';
	}
	if(rs>=2)
		*(order+4)='1';
	else
		*(order+4)='0';
	if(rs%2==1)
		*(order+5)='1';
	else
		*(order+5)='0';

	if(rt>=2)
		*(order+6)='1';
	else
		*(order+6)='0';
	if(rt%2==1)
		*(order+7)='1';
	else
		*(order+7)='0';
	for(i=15;i>=8;i--){
		*(order+i)=offset%2+'0';
		offset=offset/2;
	}
	return order;
}
char *J_order(char func[5],int address){
	char *order=calloc(16,sizeof(char));
	int i;
	*order='1';
	*(order+1)='0';
	*(order+2)='0';
	*(order+3)='0';
	for(i=15;i>=4;i--){
		*(order+i)=address%2+'0';
		address=address/2;
	}
	return order;
}
int main(){
	char func[5];
	char *order;
	int rs=0,rt=0,rd=0,immediate=0,address=0,offset=0;
	char ch;
	int i;
	FILE *fp;
	if((fp=fopen("test.txt","r+"))==NULL){
		printf("没有测试文件，请把测试文件命名为test.txt并放在当前目录下!");
		exit(0);
	}
	while(1){
		for(i=0;i<=5;i++){
			if((func[i]=fgetc(fp))==' ')
				break;
		}
		func[i]='\0';
		if(strcmp(func,"or")==0 || strcmp(func,"and")==0 || strcmp(func,"add")==0 || strcmp(func,"sub")==0 || 
			strcmp(func,"sllv")==0 || strcmp(func,"srlv")==0 || strcmp(func,"srav")==0 || strcmp(func,"slt")==0){
			while(1){
				ch=fgetc(fp);
				if(ch>='0' && ch<='9'){
					rd=(int)(ch-'0');
					break;
				}
			}
			while(1){
				ch=fgetc(fp);
				if(ch>='0' && ch<='9'){
					rs=(int)(ch-'0');
					break;
				}
			}
			while(1){
				ch=fgetc(fp);
				if(ch>='0' && ch<='9'){
					rt=(int)(ch-'0');
					break;
				}
			}
			ch=fgetc(fp);
			order=R_order(func,rd,rs,rt);
		}
		else if(strcmp(func,"ori")==0 || strcmp(func,"andi")==0 || strcmp(func,"addi")==0 || strcmp(func,"lw")==0 ||
			strcmp(func,"sw")==0){
			while(1){
				ch=fgetc(fp);
				if(ch>='0' && ch<='9'){
					rt=(int)(ch-'0');
					break;
				}
			}
			while(1){
				ch=fgetc(fp);
				if(ch>='0' && ch<='9'){
					rs=(int)(ch-'0');
					break;
				}
			}
			immediate=0;
			while(ch!='\n' && ch!=EOF){
				ch=fgetc(fp);
				if(ch>='0' && ch<='9'){
					immediate=immediate*10+(ch-'0');
				}
				
			}
			order=I_order(func,rt,rs,immediate);
		}
		else if(strcmp(func,"beq")==0 || strcmp(func,"bgt")==0){
			while(1){
				ch=fgetc(fp);
				if(ch>='0' && ch<='9'){
					rs=(int)(ch-'0');
					break;
				}
			}
			while(1){
				ch=fgetc(fp);
				if(ch>='0' && ch<='9'){
					rt=(int)(ch-'0');
					break;
				}
			}
			offset=0;
			while(ch!='\n' && ch!=EOF){
				ch=fgetc(fp);
				if(ch>='0' && ch<='9'){
					offset=offset*10+(ch-'0');
				}
				
			}
			order=beq_bgt(func,rs,rt,offset);
		}
		else{
			address=0;
			while(ch!='\n' && ch !=EOF){
				ch=fgetc(fp);
				if(ch>='0' && ch<='9')
				address=address*10+(int)(ch-'0');
			}
			order=J_order(func,address);
		}
		for(i=0;i<16;i++)
			printf("%c",*(order+i));
		printf("\n");
		free(order);
		order=NULL;
		if(ch==EOF)
			break;
	}
	fclose(fp);	
}