#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "menu_ourlib.h" 
void sortbyname(STU s[],int num)
{
	int i,j;
	STU t;
	for(i=0;i<num-1;i++)
	{
		for(j=i+1;j<num;j++)
		{
			if(strcmp(s[i].name,s[j].name)>0)
			{
				t=s[i];
				s[i]=s[j];
				s[j]=t;
			}
		}
	}
	return;
}
void  countscore(STU s[],int num)
{
	int i,j,sum;
	for(i=0;i<num;i++)
	{
		for(j=0,sum=0;j<10;j++)
		{
			sum+=s[i].score[j];
		}
		s[i].ave=sum/10.0;
	}
}

void sortbyscore(STU s[],int num)
{
	int i,j,k;
	STU t;
    countscore(s,num);
	for(j=0;j<100;j++)
    	for(i=0;i<99;i++)
	{
		for(j=i+1;j<100;j++)
		{
			if(s[i].ave<s[j].ave)
			{
				t=s[i];
				s[i]=s[j];
				s[j]=t;
			}
		}
	}
	return;         
}
