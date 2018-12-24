#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu_ourlib.h" 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int num,num1;
	char ch[16],sh[16],code1[16],name[16];
	int i,j,n,id;
	FILE *fp;
	XY xy[10];
	SEX sex[2];
	STU stu[100],re[100];
	char xueyuan[16]; 
	if((fp=fopen("code.txt","r"))==NULL)
	{
	   fp=fopen("code.txt","w");
	   printf("注册密码："); 
	   scanf("%s",ch);
	   fputs(ch,fp);	
	   fclose(fp);
	   printf("密码注册成功\n");//第二次进入该系统时必须重新输入该密码； 
	}
	else 
	{
		printf("输入密码："); 
		scanf("%s",code1);
		fp=fopen("code.txt","r");
        fscanf(fp,"%s",&ch);
		fclose(fp);
		if(strcmp(ch,code1)==0)printf("登录成功\n");
		else return 0; 
	}
	printf("******欢迎使用教务系统******\n"      );
    printf("1：读取学生的信息\n") ;
	printf("2：按照学生姓名排序得到学生名单 \n");
	printf("3：按照学生平均排序得到学生名单 \n");
	printf("4：输出给定学院学生 \n");
	printf("5: 修改给定学生的信息\n"); 
	printf("6: 按姓名查询学生\n");
	printf("7: 修改系统密码\n");
	printf("0: 返回上一级菜单\n");
	
    readall(stu,xy,sex,100,"Stu_lnfo3.txt","S_lnfo1","S_lnfo2.txt" );
	do
	{
	printf("输入需要执行的命令：");
	scanf("%d",&num);
	switch (num)
	{
		case 1:	{ 
		        for(i=0;i<100;i++)
				{
				
			    printf("%d %s %s %s  ",
                                      stu[i].id, stu[i].name, 
                                      stu[i].sname,stu[i].xname);
                                                     /*stu[i].scode, stu[i].xcode);*/
			 		for(j=0;j<10;j++)
					{
						 printf("%d  ",stu[i].score[j]);
					}
                printf("\n");
                }  break;}
		case 2:{
		        sortbyname(stu,100);
		        for(i=0;i<100;i++)
				{
				
			    printf("%d %s %s %s  ",
                                       stu[i].id, stu[i].name, 
                                       stu[i].sname,stu[i].xname);
                                                     /*stu[i].scode, stu[i].xcode);*/
			 		for(j=0;j<10;j++)
					{
						 printf("%d ",stu[i].score[j]);
					}
                printf("\n");
                } 
			    break;
		        } 
		
		case 3:{
		        sortbyscore(stu,100);
		        for(i=0;i<100;i++)
				{
				
			    printf("%d %s %s %s d ",
                                      stu[i].id, stu[i].name, 
                                      stu[i].sname,stu[i].xname);
                                                     /*stu[i].scode, stu[i].xcode);*/
			 		for(j=0;j<10;j++)
					{
						 printf("%d  ",stu[i].score[j]);
					}
				printf("%.1lf",stu[i].ave);
                printf("\n");
                } 
			    break;
		        } 
		
		case 4:{
			    printf("PS:1信息 2计算机 3文法 4外国语 5数理 6会金 7化工 8商 9航空 10艺术\n");
			    printf("输入要寻找的学院编码：");
				scanf("%d",&id);
				for(i=0;i<10;i++)
				{
					if(xy[i].xcode==id)strcpy(xueyuan,xy[i].name);
				} 
			    n=outputMsg(stu,100,re,id);
			    printf("%s的人数有%d",xueyuan,n);
			    for(i=0;i<n;i++)
			    {
			    	printf("%d %s %s %s  ",
                                         re[i].id, re[i].name, 
                                         re[i].sname,re[i].xname);
                                                     /*stu[i].scode, stu[i].xcode);*/
			 		for(j=0;j<10;j++)
					{
						 printf("%d  ",re[i].score[j]);
					}
					printf("\n");
			    }
			    break;
		       }
		case 5:{
			    printf("输入需要修改的学生学号：");
				scanf("%d",&id); 
                resivestu(stu,100,"Stu_lnfo3.txt",id);						
			    break;
		       }
		case 6:{
			    do
				{
				printf("输入要寻找的名字：");
		        scanf("%s",name);
			    n=searchbyname(stu,100,name,re);
			    }while (n==0); 
			    for(i=0;i<n;i++)
			    {
			    	printf("%d %s %s %s  ",
                                         re[i].id, re[i].name, 
                                         re[i].sname,re[i].xname);
                                                     /*stu[i].scode, stu[i].xcode);*/
			 		for(j=0;j<10;j++)
					{
						 printf("%d  ",re[i].score[j]);
					}
			    }printf("\n");
			    break;
		        }
		case 7:altercode("code.txt");break;
		case 0:printf("退出教务系统");
		break;
	}
	}while(num!=0);
	 
	return 0;
}
