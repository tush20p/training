#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<stdio.h>
typedef struct student
{
        char name[20];
        int id;
        int age;
        char sex[10];
        struct student *next;
}st;
int r;
FILE *fp;
char array[100];
int add(st **);
int link1(st *,st **);
int print(st *);
int count(st *);
int delete_node(st **);
int file(st **);
int filesave(st **);
int search(st *p);
int searchname(st *p);
int searchid(st *p);
int modify(st **ptr);
int modify_name(st **ptr);
int modify_id(st **ptr);
int datachange(st **ptr);

