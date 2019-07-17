/* Write a program to accepts name and arrival time of 5 trains and display the name with railway time format (2PM is written as 14:00). The information must be entered by the user. */

//#include"../inc/3_train.h"
#include"../inc/3_train.h"
int main()
{
	int i,ret=0;
	st train[3];

	for(i=0;i<3;i++)
	{
		printf("Enter the train name and time\n");
		scanf("%s",train[i].name);

l1:	printf("Enter hours 'hh'      :");
	ret=scanf("%d",&train[i].hh);

	if(ret==0)
	{
		printf("Wrong input\n");
		scanf("%*s");
		goto l1;	
	}

	else if((train[i].hh<0 || train[i].hh >12))
	{
		printf("Wrong input\n");
		goto l1;	
	}


l2:	printf("Enter minute 'mm'     :");
	ret=scanf("%d",&train[i].mm);

	if(ret==0)
	{
		printf("Wrong input\n");
		scanf("%*s");
		goto l2;	
	}

	else if((train[i].mm<0 || train[i].mm >59))
	{
		printf("Wrong input\n");
		goto l2;	
	}

	if(train[i].mm <= 59)
	{
		if((train[i].mm !=0 ) && (train[i].mm !=60 ))
		{
			train[i].mm = train[i].mm;
		}
	}

l3:	printf("Enter Seconds 'ss'    :");
	ret=scanf("%d",&train[i].ss);

	if(ret==0)
	{
		printf("Wrong input\n");
		scanf("%*s");
		goto l3;	
	}

	else if((train[i].ss<0 || train[i].ss >59))
	{
		printf("Wrong input\n");
		goto l3;	
	}

	if(train[i].ss <= 59)
	{
		if((train[i].ss !=0 ) && (train[i].ss !=59 ))
		{
			train[i].ss = train[i].ss;
		}
	}

	printf("Enter the am or pm    :");
	scanf("%s",train[i].s);


	if((strcmp(train[i].s,"PM") == 0) || (strcmp(train[i].s,"pm") == 0 ||(strcmp(train[i].s,"P") == 0) || (strcmp(train[i].s,"p") == 0)) 
			&& (train[i].hh != 0) && (train[i].hh != 12))
	{
		train[i].hh = train[i].hh + 12;
	}

	if((strcmp(train[i].s,"AM") == 0) || (strcmp(train[i].s,"am") == 0) && (train[i].hh == 12) || (strcmp(train[i].s,"A") == 0) || (strcmp(train[i].s,"a") == 0))
	{
		train[i].hh = train[i].hh;
	}
	printf("\n.........................................................\n");
	printf("\tTrain Name:%s       |\t Train time: %02d:%02d:%02d",train[i].name,train[i].hh, train[i].mm, train[i].ss);
	printf("\n.........................................................\n");

	printf("\n\n");

	}

}
