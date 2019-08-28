#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
typedef struct cricket
{
		char name[100];
                int jersey;
		int run;
		int catch;
		int wickets;
		int six;
		int four;
		struct cricket *next;
}cricket;
FILE *fp;
int file(cricket **,const char *);
int filesave(cricket *,char *);
int delete(cricket **);
int linklist(cricket *,cricket **);
int database(cricket **);
int name(cricket **);
int ID(cricket **);
int print(cricket *);
int modify(cricket **);
int datachange(cricket **);
int moname(cricket **);
int moID(cricket **);
int r,count=0;
