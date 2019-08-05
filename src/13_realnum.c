/* :write a program to input a list of real numbers of unknown length and output : sum and count of all positive & negative numbers. Perform the * output using following cases * a) Pointer to array * b) Pointer to Pointer * **/

#include"../inc/13_realnum.h"

int main()
{
	int size=0,i=0,test=0,ret=0;
	int option=0,back=0;
	float result=0;
	while(1)
	{
		printf("\nEnter how many real number you want  : \n");
		back=scanf("%d",&size);
		if(back==0)
		{
			printf("wrong input\n");
			scanf("%*s");
			continue;
		}
		float *pointer[size];
		float *array=0;
		array=malloc(sizeof(float)*size);
		printf("==============================================");
		for(i=0;i<size;i++)
		{
			printf("\nenter number %d : ",i+1);
			scanf("%f",&array[i]);		
			pointer[i]=&array[i];
		}	

		printf("\n==============================================");

		while(1)
		{
			for(;;)
			{
				printf("\n\n1)pointer to pointer\n 2)pointer to an array\n 3)exit program\n Enter a option : ");
				ret=scanf("%d",&option);
				if(ret==0)
				{
					printf("wrong input\n");
					scanf("%*s");
					continue;
				}

				switch(option)
				{
					case 1:
						result=pointer_to_pointer(pointer,size);
						printf("\nsum=%f\n",result);
						break;

					case 2:
						result=pointer_to_array(array,size);
						printf("\nsum=%f\n",result);
						break;

					case 3:
						exit(0);

					default:printf("wrong option\n");

				}test=1;
			}
		}
		if(test==0)
			return 0;
	}
}

float pointer_to_pointer(float **array,int size)
{
	int count=0,positive=0,negative=0;
	float sum=0;
	if(array==NULL)
	{
		printf("\nsystem error occured ");
		return 0;
	}
	for(count=0;count<size;count++)
	{
		if(*array[count]<=-1)
		{
			negative++;
		}
		else
			positive++;
		sum=sum+*array[count];
	}
	printf("\npositive=%d\nnegative=%d\n",positive,negative);
	return sum;
}
float pointer_to_array(float (*array),int size)
{
	if(array==NULL)
	{
		printf("\nsystem error occured ");
		return 0;
	}
	int count,positive=0,negative=0;
	float sum=0;
	for(count=0;count<size;count++)
	{
		if(array[count]<=-1)
			negative++;
		else
			positive++;
		sum=sum+array[count];

	}
	printf("\npositive=%d\nnegative=%d\n",positive,negative);
	return sum;
}

