/* Write count main program that performs the following steps:
 *Prompt the user to enter count string, and let them type it in. This could be an entire sentence, with the newline indicating the end of the
 string. You may assume the string will be no more than 100 characters, so declare your array accordingly.Display the following menu:

 *A) Captialize case (First letter is captial of each word)
 *B) Alternative case (assume first letter to be in lower case in result)
 *C) Invert case

 *M) Display this menu
 *X) Exit the program

 *Enter count loop, allowing the user to type in count menu choice each time.
 *Loop should continue until the user enters the command to exit. 
 *Upper and lowercase letters should be allowed for the menu choices.
 */

#include"../inc/6_string.h"

void main()
{
	char string[SIZE];
	int option,i,j;

	printf("\nEnter a string :\n");
	scanf(" %[^\n]s",string);

	printf("\n.....................................................\n\n");
	for(i=0;string[i];i++)                         
	{
		if(string[i]==' ' && string[i+1]==' ')
		{
			for(j=i;string[j];j++)
				string[j]=string[j+1];
			i--;
		}
	}
	printf("current string :\t%s\n",string);
	printf("\n.....................................................\n");

		do
		{

			printf("\n.....................................................\n");
			printf("Enter the option \n 1)Captialize case\n 2)Alternative case\n 3)Invert case\n 4)Exit\n");
			printf("\n.....................................................\n\n");

			printf("\nEnter the option :\n ");
			scanf("%d",&option);


			printf("\n.....................................................\n\n");

			switch(option)
			{
				case 1:
					capitalize(string);
					break;
				case 2:
					alternative(string);
					break;
				case 3:
					invert(string);
					break;
				case 4:
					return;
				default:;
			}
		}while(1);
}

void capitalize(char *p)
{
int i;
	if(p==NULL)
	{
		printf("\nwrong input..\n");
		return;
	}

	for(i=0;p[i];i++)
	{
		if(i==0 && p[i]>=97 && p[i]<=122)
			p[i]=p[i]^32;

		else if(p[i]==' ' && p[i+1]>=97 && p[i+1]<=122)
			p[i+1]=p[i+1]^32;

	}
	printf("capitalized : %s\n",p);
} 

void alternative(char *p)
{
int i;
	if(p==NULL)
	{
		printf("\nwrong input..\n");
		return;
	}

	for(i=0;p[i];i++)
	{
		if(i==0 && (p[i]>=97 && p[i]<=122 || p[i]>=65 && p[i]<=91))
			p[i]=p[i]^32;

		else if(p[i]==' ' && (p[i+1]>=97 && p[i+1]<=122 || p[i+1]>=65 && p[i+1]<=91))
			p[i+1]=p[i+1]^32;

	}
	printf("\nalternative : %s\n",p);
}

void invert(char *p)
{
int i;
	if(p==NULL)
	{
		printf("\nwrong input..\n");
		return;
	}

	printf("\ninvert : ");

	for(i=0;p[i];i++)
	{
		if(p[i] && p[i]!=' ' && (p[i]>=65 && p[i]<=91 || p[i]>=97 && p[i]<=121))
			p[i]=p[i]^32;
	}
	printf("%s\n",p);
}
