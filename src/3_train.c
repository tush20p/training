#include"../inc/3_train.h"
typedef struct train
{
	char name[50];
	char s[5];
	int hh;
	int mm;
	int ss;
}st;

int main()
{
	int i;
	st train[2];
	
	
	for(i=0;i<2;i++)
	{
	printf("Enter the train name and time\n");
	scanf("%s",train[i].name);
		printf("Enter hours 'hh'     :\t");
		scanf("%d",&train[i].hh);

		printf("Enter minutes 'mm'   :\t");
		scanf("%d",&train[i].mm);

		printf("Enter seconds 'ss'   :\t");
		scanf("%d",&train[i].ss);

		printf("\n------------------------------\n\n");
		
		printf("Enter am or pm       :\t");
		scanf("%s",train[i].s);
	
		printf("\n...............................\n\n");
	}	
	printf("\n===============================\n\n");

	for(i=0;i<2;i++)
	{
			if(train[i].hh <= 12 && train[i].mm <= 59 && train[i].ss <= 59)      
			{

				if((strcmp(train[i].s,"PM") == 0) || (strcmp(train[i].s,"pm") == 0) 
						&& (train[i].hh != 0) && (train[i].hh != 12))
				{
					train[i].hh = train[i].hh + 12;
				}

				if((strcmp(train[i].s,"AM") == 0) || (strcmp(train[i].s,"am") == 0) && (train[i].hh == 12))
				{
					train[i].hh = 0;
				}

				printf("train name:\t Train timimg : \t");
				printf("%s- %02d:%02d:%02d",train[i].name,train[i].hh, train[i].mm, train[i].ss);

				printf("\n\n");

			}

			else
			{
			printf("wrong input give the correct inputs.\n");
			}
	}
	printf("=================================\n\n");
	
}
