#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma pack(1)
struct sim
{
        char name[20];
        char id[20];
        long int sim[3];
        char address[50];
        char state[20];
};

void myadhar(struct sim *);
void myname(struct sim *,int);
void mycount(struct sim *,int);
void print(struct sim *);

int i,j,k,count=0,ret=0;
char num[20],st[20];
long int mob;

struct sim s[3]={{"tushar","1234",{8804511511,9075833704},"Kolhapur Maharashtra"},{"virat","4321",{8804511511,1010101010,8698889897},"Delhi India"},{"msd","0707",{7777777777},"Ranchi Jharakhand"}};
