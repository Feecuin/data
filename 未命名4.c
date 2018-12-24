#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu_ourlib.h" 
void altercode(char filename[])
{
	FILE *fp;
	char ch[16],sh[16],code1[16];
	fp=fopen(filename,"w+");
	fscanf(fp,"%s",ch);
    do
    {
    printf("请输入原密码："); 
    scanf("%s",code1);
    }while(strcmp(ch,code1)==0); 
	do
	{    
	printf("请输入新密码：");
	scanf("%s",ch);
	printf("请确认新密码：");
	scanf("%s",sh);
	}while(strcmp(ch,sh)!=0);
    if(ch!='\0')
    fputs(ch,fp);
	printf("密码修改成功");
    fclose(fp);
}
void resivestu(STU stu[],int num,char filename[],int id)
{
	FILE *fp;
	STU he;
	char name[16];
	int xid,sid;
	int score;
	int i,j,k,n,m;
	for(i=0;i<=100;i++)
	{
		if(id==stu[i].id)
		  {
		    break;
	      }
		        
	}
	if(i==100)
	       printf("未找到该学生\n"); 
    else
	{
	 
	fp=fopen(filename,"w");
	printf("修改名字请按1，修改性别编号请按2，修改学院编号请按3，修改成绩请按4，再按1到10门成绩的第几门成绩\n"); 
	printf("请输入需要修改的情况：");
	scanf("%d",&m);
	switch(m)
	{
		case 1:{
			    scanf("%s",name);
			    strcpy(stu[i].name,name);
			    break;
		       }
		case 2:{
			    printf("请输入修改后的学院编码：");
			    scanf("%d",&xid);
				stu[i].xcode=xid; 
			    break;
		       }
		case 3:{
			    printf("请输入修改后的性别编码：");
			    scanf("%d",&sid);
				stu[i].scode=sid;
			    break;
		       }
		case 4:{
		       do
			   {
			    printf("请输入要修改第几门成绩："); 
			    scanf("%d",&k);
			   }while(k>10||k<0);
			    printf("请输入修改后的成绩");
			    scanf("%d",&score);
			    stu[i].score[k]=score;
			    break;
		       }
	}
	 fp=fopen(filename,"w+");
	 fflush(stdin);
	 fflush(stdout);
	 for(i=0;i<num;i++)
	 {
	 	fprintf(fp,"%ld %s %ld %ld ",stu[i].id,stu[i].name,stu[i].scode,stu[i].xcode);
	 	for(j=0;j<10;j++)
	 	fprintf(fp,"%ld ",stu[i].score[j]); 
		fprintf(fp,"\n");
	 }
	 fclose(fp); 
	 printf("修改成功");
	 }
     return ;
}
