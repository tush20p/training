#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

struct node
{
        char *name;
        struct node *lchild;
        struct node *rchild;
};
struct node *root=0;
void insert(char *);
void find(char *,struct node **,struct node **);
struct node* search(struct node *,char *);
void displayin(struct node *);
#define SIZE 50
#define RANGE 20
