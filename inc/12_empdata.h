#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
typedef struct employee
{
        char name[20];
        int id;
        int age;
        char sex[10];
        char address[100];
        char branch[100];
        char designation[50];
        char doj[15];
        struct employee *next;
        struct employee *prv;
}ed;
int r;
FILE *fp;
char array[100];
int add(ed **);
int link1(ed *,ed **);
int print(ed *);
int count(ed *);
int delete_node(ed **);
int file(ed **);
int filesave(ed **);
int search(ed *p);
int searchname(ed *p);
int searchid(ed *p);
int modify(ed **ptr);
int modify_name(ed **ptr);
int modify_id(ed **ptr);
int datachange(ed **ptr);

