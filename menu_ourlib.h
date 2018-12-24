#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	int id;
	char name[16];
	int scode;
	int xcode;
	int score [10];
	float ave;
	char xname[32];
	char sname[4];
} STU;
typedef struct
{
	int xcode;
	char name[32];
}XY;
typedef struct 
{
	int scode;
	char name[4];
}SEX;
struct student
{
	int id;
	char name[16];
	int scode;
	int xcode;
	int score [10];
	float ave;
};

void readall(STU stu[],XY xy[],SEX sex[],int num,char filename1[],char filename2[],char filename3[]);
//读取学生的信息 
void countave(STU stu[],int num);
//计算学生的平均分 
void sortbyname(STU stu[],int num);
//通过学生姓名排序 
void sortbyscore(STU stu[],int num);
//通过学生平均分排序 
int outputMsg(STU stu[],int num,STU re[],int id);
//通过学院代号，将该学院的学生的资料记录起来 
void resivestu(STU stu[],int num,char filename[],int id);
//通过一个学号，找出该学生，修改这个学生的信息,并将其修改情况输入文件中 
int searchbyname(STU stu[],int num,char name[],STU re[]);
//通过名字，找出这个学生；
void altercode(char filename[]);
//修改教务系统密码 
