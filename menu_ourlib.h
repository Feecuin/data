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
//��ȡѧ������Ϣ 
void countave(STU stu[],int num);
//����ѧ����ƽ���� 
void sortbyname(STU stu[],int num);
//ͨ��ѧ���������� 
void sortbyscore(STU stu[],int num);
//ͨ��ѧ��ƽ�������� 
int outputMsg(STU stu[],int num,STU re[],int id);
//ͨ��ѧԺ���ţ�����ѧԺ��ѧ�������ϼ�¼���� 
void resivestu(STU stu[],int num,char filename[],int id);
//ͨ��һ��ѧ�ţ��ҳ���ѧ�����޸����ѧ������Ϣ,�������޸���������ļ��� 
int searchbyname(STU stu[],int num,char name[],STU re[]);
//ͨ�����֣��ҳ����ѧ����
void altercode(char filename[]);
//�޸Ľ���ϵͳ���� 
