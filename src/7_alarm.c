/* Write a program for Silent Message notification application using structure/union. User has to set some notification time in human readable format 
 * and application should compare it with system time and print the notification message on the screen. (Kind of an alarm). Make it as interactive as possible.
 */
#include"../inc/7_alarm.h"
void main()
{
	al s[10];
	char a[11],string[100],stime[20],c,x;
	int i,j,k,fd[2],hh,mm,ss,ret=0;
	if(pipe(fd)==-1)
	{
		perror("pipe");
		return;
	}
	printf("\n..................Alarm...................\n\n");    
	if(fork()==0)
	{
		for(i=0;i<=10;i++)
		{
			read(fd[0],s[i].notification,100);
			read(fd[0],s[i].time,100);
			read(fd[0],&x,1);

			if(x=='n'||x=='N')
				break;
		}
		k=i;
		while(k>-1)
		{
			time_t t=time(NULL);
			struct tm tm=*localtime(&t);

			sprintf(a,"%02d:%02d:%02d",tm.tm_hour,tm.tm_min,tm.tm_sec);

			for(j=0;j<=i;j++)
			{
				if(strcmp(a,s[j].time)==0)
				{
					printf("\n..................Alarm...................\n");    
					printf("Message:%s   Time:%s",s[j].notification,s[j].time);
					printf("\n..........................................\n");    
					k--;
					break;

				}
			}
			sleep(1);

		}


	}
	else
	{

		do
		{                      
			printf("\nenter the notification : ");
			scanf(" %[^\n]s",string);
			write(fd[1],string,strlen(string)+1);

			printf("\nSet the alarm time HH:MM:SS:-\n");
			printf(".........................................\n");

l1:     printf("Enter hours 'hh'      :");
	ret=scanf("%d",&hh);

	if(ret==0)
	{
		printf("Wrong input\n");
		scanf("%*s");
		goto l1;
	}

	else if((hh<0 || hh >24))
	{
		printf("Wrong input\n");
		goto l1;
	}

	if((hh != 0) && (hh != 24))
	{
		hh = hh;
	}


l2:     printf("Enter minute 'mm'     :");
	ret=scanf("%d",&mm);

	if(ret==0)
	{
		printf("Wrong input\n");
		scanf("%*s");
		goto l2;
	}

	else if((mm<0 || mm >59))
	{
		printf("Wrong input\n");
		goto l2;
	}

	if(mm <= 59)
	{
		if((mm !=0 ) && (mm !=60 ))
		{
			mm = mm;
		}
	}
l3:     printf("Enter Seconds 'ss'    :");
	ret=scanf("%d",&ss);

	if(ret==0)
	{
		printf("Wrong input\n");
		scanf("%*s");
		goto l3;
	}

	else if((ss<0 || ss >59))
	{
		printf("Wrong input\n");
		goto l3;
	}

	if(ss <= 59)
	{
		if((ss !=0 ) && (ss !=59 ))
		{
			ss = ss;
		}
	}

	sprintf(stime,"%02d:%02d:%02d",hh,mm,ss);

	printf(".........................................\n\n");

	printf("time=%s\n",stime);
	write(fd[1],stime,strlen(stime)+1);

	printf("\nalarm set");
	printf("\n\n.........................................\n");

l4:printf("\ndo you want to add new alarm y/n?");
   scanf(" %c",&c);
   if(!(c=='y' || c=='Y' || c=='n' || c=='N'))
   {
	   printf("wrong input\n");
	   goto l4;

   }
   write(fd[1],&c,1);

		}while(c=='y'||c=='Y');

	}               

}

