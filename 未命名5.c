#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu_ourlib.h"
void readall(STU stu[],XY xy[],SEX sex[],int num,char f1[],char f2[],char f3[] )
{
	FILE *fp;
	int i,j;
	fp=fopen(f1,"r");
	if(fp==NULL)
	   {
	      printf("打开文件错误");   
		  return;
	  }
	for(i=0;i<num;i++)
		{
		fscanf(fp, "%d%s%d%d",&stu[i].id, stu[i].name, &stu[i].scode,&stu[i].xcode);
					for(j=0;j<10;j++)
					{
						 fscanf(fp, "%d",&stu[i].score[j]);
                    }
	    }
	fclose(fp);
	fp=fopen(f2,"r");
	if(fp==NULL)
	   {
	   	printf("打开文件错误");
		return; 
	   }
	 for(i=0;i<10;i++)
	    {
	 	fscanf(fp,"%d%s",&xy[i].xcode,xy[i].name);
	    }   
	    fclose(fp);
	    fp=fopen(f3,"r");
      if(fp==NULL)
      {
          printf("打开文件错误");      
	      return; 
	  }
	  for(i=0;i<2;i++)
	     {
	 	    fscanf(fp,"%d%s",&sex[i].scode,sex[i].name);
	     }   
	     fclose(fp);
	  	 for(i=0;i<100;i++)
				{
					for(j=0;j<2;j++)
					{
						if(stu[i].scode==sex[j].scode)
						    strcpy(stu[i].sname,sex[j].name);
					}
				}
		  for(i=0;i<100;i++)
				{
					for(j=0;j<10;j++)
					{
						if(stu[i].xcode==xy[j].xcode)
						    strcpy(stu[i].xname,xy[j].name);
					}
				}
	return;
}
