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
    printf("������ԭ���룺"); 
    scanf("%s",code1);
    }while(strcmp(ch,code1)==0); 
	do
	{    
	printf("�����������룺");
	scanf("%s",ch);
	printf("��ȷ�������룺");
	scanf("%s",sh);
	}while(strcmp(ch,sh)!=0);
    if(ch!='\0')
    fputs(ch,fp);
	printf("�����޸ĳɹ�");
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
	       printf("δ�ҵ���ѧ��\n"); 
    else
	{
	 
	fp=fopen(filename,"w");
	printf("�޸������밴1���޸��Ա����밴2���޸�ѧԺ����밴3���޸ĳɼ��밴4���ٰ�1��10�ųɼ��ĵڼ��ųɼ�\n"); 
	printf("��������Ҫ�޸ĵ������");
	scanf("%d",&m);
	switch(m)
	{
		case 1:{
			    scanf("%s",name);
			    strcpy(stu[i].name,name);
			    break;
		       }
		case 2:{
			    printf("�������޸ĺ��ѧԺ���룺");
			    scanf("%d",&xid);
				stu[i].xcode=xid; 
			    break;
		       }
		case 3:{
			    printf("�������޸ĺ���Ա���룺");
			    scanf("%d",&sid);
				stu[i].scode=sid;
			    break;
		       }
		case 4:{
		       do
			   {
			    printf("������Ҫ�޸ĵڼ��ųɼ���"); 
			    scanf("%d",&k);
			   }while(k>10||k<0);
			    printf("�������޸ĺ�ĳɼ�");
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
	 printf("�޸ĳɹ�");
	 }
     return ;
}
