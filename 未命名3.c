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
	   printf("ע�����룺"); 
	   scanf("%s",ch);
	   fputs(ch,fp);	
	   fclose(fp);
	   printf("����ע��ɹ�\n");//�ڶ��ν����ϵͳʱ����������������룻 
	}
	else 
	{
		printf("�������룺"); 
		scanf("%s",code1);
		fp=fopen("code.txt","r");
        fscanf(fp,"%s",&ch);
		fclose(fp);
		if(strcmp(ch,code1)==0)printf("��¼�ɹ�\n");
		else return 0; 
	}
	printf("******��ӭʹ�ý���ϵͳ******\n"      );
    printf("1����ȡѧ������Ϣ\n") ;
	printf("2������ѧ����������õ�ѧ������ \n");
	printf("3������ѧ��ƽ������õ�ѧ������ \n");
	printf("4���������ѧԺѧ�� \n");
	printf("5: �޸ĸ���ѧ������Ϣ\n"); 
	printf("6: ��������ѯѧ��\n");
	printf("7: �޸�ϵͳ����\n");
	printf("0: ������һ���˵�\n");
	
    readall(stu,xy,sex,100,"Stu_lnfo3.txt","S_lnfo1","S_lnfo2.txt" );
	do
	{
	printf("������Ҫִ�е����");
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
			    printf("PS:1��Ϣ 2����� 3�ķ� 4����� 5���� 6��� 7���� 8�� 9���� 10����\n");
			    printf("����ҪѰ�ҵ�ѧԺ���룺");
				scanf("%d",&id);
				for(i=0;i<10;i++)
				{
					if(xy[i].xcode==id)strcpy(xueyuan,xy[i].name);
				} 
			    n=outputMsg(stu,100,re,id);
			    printf("%s��������%d",xueyuan,n);
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
			    printf("������Ҫ�޸ĵ�ѧ��ѧ�ţ�");
				scanf("%d",&id); 
                resivestu(stu,100,"Stu_lnfo3.txt",id);						
			    break;
		       }
		case 6:{
			    do
				{
				printf("����ҪѰ�ҵ����֣�");
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
		case 0:printf("�˳�����ϵͳ");
		break;
	}
	}while(num!=0);
	 
	return 0;
}
