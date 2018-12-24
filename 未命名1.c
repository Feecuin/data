#include<stdio.h>
#include<string.h>
#include "menu_ourlib.h"
#define N 100;
int outputMsg(STU stu[],int num,STU re[],int id)
{
	int i, j=0;	
 	for(i=0;i<num;i++)
	 {
         if(id==stu[i].xcode)
                {
                	re[j]=stu[i];
                	j++;
                }
	 }
	return j;
}

int searchbyname(STU stu[],int num,char name[],STU re[])
{
	int i,j=0;
	for(i=0;i<num;i++)
	{
		if(strcmp(stu[i].name,name)==0)
		{
			re[j]=stu[i];
		    j++;
		}
	}
	return j;
}
