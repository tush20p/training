/*Write a program for polynomial addition, subtraction, and multiplication. Use dynamic memory allocation to take in the polynomial enetred by the user.*/

#include"15_polynomial.h"

int main()
{
	printf("\n==========polynomial addition===========");
	int *p=0,*p2=0,*p3=0,size=0,check=0,num1=0,num2=0;
	int option=0,ret=0;
	static int test;
	do
	{
		printf("\n\nenter total number for 1st polynomial function : ");
		ret=scanf("%d",&num1);
		if(ret==0)
		{
			scanf("%*s");
			printf("\nwrong input");
		}
	}while(ret==0);

	p=malloc(sizeof(int)*num1);
	do
	{
		ret=input(p,num1);
	}while(ret==0);
	do
	{
		printf("\n\nenter total number for 2nd polynomial function : ");
		ret=scanf("%d",&num2);
		if(ret==0)
		{
			scanf("%*s");
			printf("\nwrong input");
		} 
	}while(ret==0);

	p2=malloc(sizeof(int)*num2);
	do
	{
		ret=input(p2,num2);
	}while(ret==0);
	size=num1>num2?num1:num2;
	p3=malloc(sizeof(int)*size);        

	while(1)
	{
		test++;
		printf("\n");
		for(;;)
		{
			printf("\n\n1)addition\n2)subtraction\n3)multiplication\n4)Multiple operation with result\n5)exit\nenter a option : ");
			check=scanf("%d",&option);
			if(check==0)
			{
				printf("wrong input\n");
				scanf("%*s");
				continue;
			}
			switch(option)
			{

				case 1:
					do
					{
						ret=addition(p,p2,p3,size);
					}while(ret==0);
					printf("\n");

					do
					{
						ret=display(p,num1);
					}while(ret==0);
					printf("  +\n\n");

					do
					{
						ret=display(p2,num2);
					}while(ret==0);
					printf("\n\n---------------------------------\n");

					do
					{
						ret=display(p3,size);
					}while(ret==0);
					break;
				case 2:
					do
					{
						ret=subtraction(p,p2,p3,size);
					}while(ret==0);
					printf("\n");

					do
					{
						ret=display(p,num1);
					}while(ret==0);
					printf("  -\n\n");

					do
					{
						ret=display(p2,num2);
					}while(ret==0);
					printf("\n\n---------------------------------\n");

					do
					{
						ret=display(p3,size);
					}while(ret==0);
					break;
				case 3:
					size=num1+num2-1;

					do
					{	
						ret=multiplication(p,p2,p3,num1,num2,size);
					}while(ret==0);
					printf("\n");

					do	
					{
						ret=display(p,num1);
					}while(ret==0);
					printf("  *\n\n");

					do
					{
						ret=display(p2,num2);
					}while(ret==0);
					printf("\n\n---------------------------------\n");

					do
					{
						ret=display(p3,size);
					}while(ret==0);
					break;
				case 4:
					if(test)
					{
						printf("\nyou haven't did any operation yet");
						test--;
					}
					else
					{

						free(p);
						p=malloc(sizeof(int)*size);

						for(int i=0;i<size;i++)                                                                            							p[i]=p3[i];

						num1=size;
						free(p3);
						free(p2);
						do
						{
							printf("\nenter total number for polynomial function\n");
							ret=scanf("%d",&num2);
							if(ret==0)
							{
								scanf("%*s");
								printf("\nwrong input");
							}
						}while(ret==0);
						p2=malloc(sizeof(int)*num2);
						do
						{
							ret=input(p2,num2);
						}while(ret==0);
						size=num1>num2?num1:num2;
						p3=malloc(sizeof(int)*size);        
					}
					break;

				case 5:return 0;
				default:
				       printf("\nwrong choice");
			}
		} 
		test--;
	}
}
int input(int *p,int size)
{
	if(p==NULL)
	{
		printf("\nsystem error occured");
		return 0;
	}
	int i,check;
	for(i=0;i<size;i++)
	{
		printf("\n\nenter number : ");
		check=scanf("%d",&p[i]);
		if(check==0)
		{
			printf("\nwrong input..enter again..");
			scanf("%*s");
			i--;
			continue;
		}
		display(p,i);
	}
	return 1;
}

int addition(int *p,int *p2,int *p3,int size)
{
	if(p==NULL&&p2==NULL&&p3==NULL)
	{
		printf("\nsystem error occured");
		return 0;
	}
	int count;
	for(count=0;count<size;count++)
	{
		p3[count]=p[count]+p2[count];
	}
	return 1;
}
int subtraction(int *p,int *p2,int *p3,int size)
{
	if(p==NULL&&p2==NULL&&p3==NULL)
	{
		printf("\nsystem error occured");
		return 0;
	}
	int count;
	for(count=0;count<size;count++)
	{
		p3[count]=p[count]-p2[count];
	}
	return 1;
}
int multiplication(int *p,int *p2,int *p3,int num1,int num2,int size)
{
	if(p==NULL&&p2==NULL&&p3==NULL)
	{
		printf("\nsystem error occured");
		return 0;
	}
	int count,i,j;
	int *temp=malloc(sizeof(int)*size);
	free(p3);
	p3=calloc(size,sizeof(int));
	for(i=0;i<num2;i++)
	{
		for(j=0;j<num1;j++)
			temp[j]=p[j]*p2[i];
		for(count=0;count<size;count++)
			p3[count+i]=p3[count+i]+temp[count];
	}
	return 1;
}
int display(int *p,int size)
{
	if(p==NULL)
	{
		printf("\nsystem error occured");
		return 0;
	}
	int count;
	for(count=size;count>=0;count--)
	{
		if(p[count]==0)
			continue;
		else
		{
			if(p[count]>0)
				printf("+");
			printf("%d",p[count]);
			if(count!=0)
				printf("x^%d",count);
		}
	}
	return 1;
}


