/* Write a program for an automatic SIM card details verification. The database will contain name , ID proof, sim ID no, address etc.
 * Not more than 3 SIM card should be given on one ID proof.*/

#include"10_sim.h"

void main()
{
	printf("\t\t================================\n\n");
	printf("\t\t SIM card details verification\n\n");
	printf("\t\t================================\n\n");

	myadhar(s);
	print(s);

}

void myadhar(struct sim *s)
{
	int test=0,m=0;
	printf("\t\tEnter the adhar card number\n\t\t\t");
	ret=scanf("%s",num);

	if(ret==0)
	{
		printf("\twrong input\n");
		scanf("%*s");
		myadhar(s);
	}

	for(i=0;i<3;i++)
	{
		if(strcmp(s[i].id,num)==0)
		{	
			printf("\t\t.................................\n");
			printf("\t\t\t   Matched\n");
			printf("\t\t.................................\n");
			test=1;
			m=i;
			myname(s,m);
			mycount(s,m);	
			break;
		}
	}
	if(test==0)
	{
		printf("\nwrong input\n");
		myadhar(s);
	}
}

void myname(struct sim *s,int i)
{
	int m;
	m=i;
	int test=0;
	printf("\t\tEnter the name\n\t\t\t");
	ret=scanf("%s",st);
	if(ret==0)
	{
		printf("\twrong input\n");
		scanf("%*s");
		myname(s,m);
		return;

	}

	for(;;)
	{
		if(strcmp(s[i].name,st)==0)
		{
			printf("\t\t.................................\n");
			printf("\t\t\t   Matched\n");
			printf("\t\t.................................\n");
			test=1;
			break;
		}
		else
		{
			printf("\twrong input\n");
			myname(s,m);
			return;
		}
	}
	if(test==0)
	{
		printf("\nwrong input\n");
		myname(s,m);
	}
}

void mycount(struct sim *s,int i)
{
	int k,count=0;
	int option;
	int m;
	m=i;
	for(;;)
	{
		for(k=0;k<3;k++)
		{
			if(s[i].sim[k]!=0)
				count++;
		}	
		printf("\t\tYou have = %d SIM card on your ID\n\n",count);
		do
		{
			printf("\t\t ---------------------------------\n");
l1:	printf("\t\tDo you want new SIM card\n \t\t1)Yes 2)No \n\t");
	ret=scanf("%d",&option);
	if(ret==0)
	{
		printf("\twrong input\n");
		scanf("%*s");
		goto l1;
	}
	switch(option)
	{	
		case 1:

			if(count==3)
			{
				printf("\t\tyou have already 3 sim cards\n");
				return;
			}
			else
			{

				printf("\t\tEnter the new mobile num\n\t");
				scanf("%ld",&s[i].sim[count]);
				count++;

			}
			break;

		case 2:
			return;

		default:printf("\twrong option\n");
			goto l1;
	}
		}while(option==1 || option==2);
	}
}
void print(struct sim *s)
{
	int m;
	printf("\t\t ---------------------------------\n");
	printf("\t\t    SIM card detail Informaton\n");
	printf("\t\t ---------------------------------\n");
l2:printf("\t\tEnter the your mobile num\n\t");
   scanf("%ld",&mob);

   for(j=0;j<3;j++)
   {
	   if((s[i].sim[j]==mob))
	   {
		   m=strlen(s[i].address);
		   printf("\t\t.................................\n");
		   printf("\t\t\t   Matched\n");
		   printf("\t\t.................................\n\n");

		   printf("\t\t -----------------------------------------\n");
		   printf("\t\t|\t  NAME \t\t-%s \n \t\t|\t  ID\t\t-%s \n \t\t|\t  SIM 1\t\t-%ld \n \t\t|\t  SIM 2\t\t-%ld \n \t\t|\t  SIM 3\t\t-%ld \n \t\t|\t ADDRESS\t-%s \n",s[i].name,s[i].id,s[i].sim[0],s[i].sim[1],s[i].sim[2],s[i].address);
		   printf("\t\t -----------------------------------------\n");
		   return;
	   }
	   if(j==2 && (s[i].sim[j]!=mob))
	   {
		   printf("\twrong mobile number\n");
		   goto l2;
	   }
   }
}
