/*write function to add two 2D arrays of variable dimension (dimension to be taken from user). Function should catch 1st array using pointer to array and 2nd using array of pointers.
  Print the resultant array using user defined printf() function which catches 2D array using double pointer. */

/* TODO: Include only header name and not the whole path. */
#include"../inc/9_sum.h"

/* TODO: The program takes in 0 and 0 as a value of matrix rows and columns. This is wrong. Correct it..*/
/* TODO: The program takes in negative value of matrix rows and columns. This is wrong. Correct it. */
/* Please eliminate goto */

int main()
{
	int **p1=0,**p2=0,**p3=0,r=0,c=0,l=0,m=0,ret=0,here=0,test=0;


	while(1)
	{

		while(ret==0)
		{
			printf("Enter the rows and column for matricx1:\n\n");
			ret=scanf("%d",&r);
			ret=scanf("%d",&c);
			printf("row1=%d col1=%d\n\n",r,c);  
			printf(".............................................\n\n");
			if(ret==0)
			{
				scanf("%*s");
				printf("\n\nInvalid Option Entered...\nChoose Again...\n\n");
				ret=0;
				continue;     
			}


			while(here==0)
			{
				printf("Enter the rows and column matrcsx2:\n\n");
				here=scanf("%d",&l);
				here=scanf("%d",&m);
				printf("row2=%d col2=%d\n\n",l,m);  
				printf(".............................................\n\n");

				if(here==0)
				{
					printf("\n\nInvalid Option Entered...\nChoose Again...\n\n");
					scanf("%*s");
					here=0;
					continue;
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
					printf("\n\n");
					for(int i=0;i<r;i++)
					{
						printf("\t|");
						for(int j=0;j<c;j++)
							printf(" %d ",p1[i][j]);
						printf("|\n");
					}

					printf("\t  __|__\n");
					printf("\t    |  \n");

					printf("\n\n");
					for(int i=0;i<r;i++)
					{
						printf("\t|");
						for(int j=0;j<c;j++)
							printf(" %d ",p2[i][j]);
						printf("|\n");
					}

					printf("=============================================\n\n");
					printf("\n\n");
					for(int i=0;i<r;i++)
					{
						printf("\t|");
						for(int j=0;j<c;j++)
							printf(" %d ",p3[i][j]);
						printf("|\n");
					}
					break;
				}
				printf("wrong input\n\n");
				test=1;
			}
			ret=0;
			if(test==0)
				continue;
		}
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

