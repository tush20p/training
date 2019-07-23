/*write function to add two 2D arrays of variable dimension (dimension to be taken from user). Function should catch 1st array using pointer to array and 2nd using array of pointers.
  Print the resultant array using user defined printf() function which catches 2D array using double pointer. */

#include"../inc/9_sum.h"

int main()
{
	int **p1,**p2,**p3,i,j,r,c,l,m,ret;


	while(1)
	{

here:printf("Enter the rows and column for matricx1:\n\n");
     ret=scanf("%d",&r);
     ret=scanf("%d",&c);
     printf("row1=%d col1=%d\n\n",r,c);  
printf(".............................................\n\n");
     if(ret==0)
     {
	     scanf("%*s");
	     printf("\n\nInvalid Option Entered...\nChoose Again...\n\n");
	     goto here;
     }



l1:printf("Enter the rows and column matrcsx2:\n\n");
   ret=scanf("%d",&l);
   ret=scanf("%d",&m);
   printf("row2=%d col2=%d\n\n",l,m);  
printf(".............................................\n\n");

   if(ret==0)
   {
	   scanf("%*s");
	   printf("\n\nInvalid Option Entered...\nChoose Again...\n\n");
	   goto l1;
   }

   if(r == l && c==m)
   {
	   p1=my_malloc(r,c);
	   p2=my_malloc(l,m);
	   p3=my_malloc(r,c);
	   pointer_to_array(r,c,p1);
	   array_of_pointer(r,c,p2);
	   sum(p1,p2,p3,r,c);
printf(".............................................\n");
	   print(p1,r,c);

	   printf("\t  __|__\n");
	   printf("\t    |  \n");

	   print(p2,r,c);

printf("=============================================\n\n");
	   print(p3,r,c);
	   break;
   }
   printf("wrong input\n\n");
	}
}

int **my_malloc(int r,int c)
{
	int **p;
	p=malloc(sizeof(int*)*r);
	for(int i=0;i<r;i++)
		p[i]=(int *)malloc(sizeof(int*)*c);
	return p;
}

void pointer_to_array(int r,int c,int **p)
{
	int ret;
l2:printf("Enter the data\n");
   for(int i=0;i<r;i++)
	   for(int j=0;j<c;j++)
		   ret=scanf("%d",&p[i][j]);

   if(ret==0)
   {
	   scanf("%*s");
	   printf("\n\nInvalid Option Entered...\nChoose Again...\n\n");
	   goto l2;
   }

}

void array_of_pointer(int r,int c,int *p[])
{
	int ret;
l2:printf("Enter the data\n");
   for(int i=0;i<r;i++)
	   for(int j=0;j<c;j++)
		   ret=scanf("%d",&p[i][j]);

   if(ret==0)
   {
	   scanf("%*s");
	   printf("\n\nInvalid Option Entered...\nChoose Again...\n\n");
	   goto l2;
   }

}

void sum(int **p1,int **p2,int **p3,int r,int c)
{
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			p3[i][j]=p1[i][j]+p2[i][j];
}

void print(int **p,int r,int c)
{
	printf("\n\n");
	for(int i=0;i<r;i++)
	{
		printf("\t|");
		for(int j=0;j<c;j++)
			printf(" %d ",p[i][j]);
		printf("|\n");
	}
	printf("\n");
}
