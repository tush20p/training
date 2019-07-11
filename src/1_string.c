/*Write a main program that performs the following steps:
 *	Prompt the user to enter a string, and let them type it in. This 
 *	could be an entire sentence, with the newline indicating the end of the 
 *	string. You may assume the string will be no more than 100 characters, so 
 *	declare your array accordingly.Display the following menu:
 *
 *	A) Count the number of vowels in the string
 *	B) Count the number of consonants in the string
 *	C) Convert the string to uppercase
 *	D) Convert the string to lowercase
 *	E) Display the current string
 *	I) Enter another string
 *		
 *	M) Display this menu
 *	X) Exit the program
 *
 *	Enter a loop, allowing the user to type in a menu choice each time. 
 *	Loop should continue until the user enters the command to exit. Upper and 
 *	lowercase letters should be allowed for the menu choices. 
 */

#include"header.h"
#define size 100

void vowels(char *);
void consonants(char *);
void uppercase(char *);
void lowercase(char *);
void currentstring(char *);
void newstring(char *);

void main()
{
	char p[size];
	char option;
	int i,c=0,m=0,n=0,t=0;
	printf("\n\n\tEnter the string:\n\n\t");
	scanf("%[^\n]",p);
	printf("_________________________________\n");
	printf("\nstring name:\n");
	printf("\t%s\n\n",p);

	printf("__________________________________\n");

	do
	{
		//		system("clear");
		printf("\n\nEntered String: %s\n\n",p);
		printf("\t\n\nenter the option \n\t1)vowels \n\t2)consonants \n\t3)uppercase \n\t4)lowercase \n\t5)current string \n\t6)enter new string \n\t7)exit...\n");
		scanf(" %c",&option);
		//m=0;
		//		n=0;
		switch(option)
		{
			case '1':vowels(p);
				 break;


			case '2':consonants(p);
				 break;

			case '3':uppercase(p);
				 break;


			case '4':lowercase(p);
				 break;

			case '5':currentstring(p);
				 break;

			case '6':newstring(p);
				 break;

			case '7':option='8';


		}
		//		sleep(3);
		if(option=='8')
			break;
	}while(1);
}

void vowels(char *s)
{
	int i,m=0;

	printf("total number of vowels counts in the string-\n");

	for(i=0;s[i];i++)
	{
		if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
		{
			m++;
		}

	}
	printf("\tvowels=%d\n",m);
	printf("____________________________________\n");

}

void consonants(char *s)
{

	int i,n=0;
	printf("total number of consonants counts in the string-\n");

	for(i=0;s[i];i++)
	{
		if((s[i]!='A' && s[i]!='E' && s[i]!='I' && s[i]!='O' && s[i]!='U' && s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u')&&((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')))
			n++;
	}
	printf("\tconsonants=%d\n",n);
	printf("____________________________________\n");


}

void uppercase(char *s)
{

	int i;
	printf("convert string into uppercase-\n");
	for(i=0;s[i];i++)
	{
		if(s[i]>='a' && s[i]<='z')
		{
			s[i]=s[i]-32;

		}
	}
	printf("\t%s\n",s);
	printf("____________________________________\n");

}

void lowercase(char *s)
{

	int i;
	printf("convert the string into lowercase-\n");
	for(i=0;s[i];i++)
	{
		if(s[i]>='A' && s[i]<='Z')
		{
			s[i]=s[i]+32;

		}
	}
	printf("\t%s\n",s);
	printf("____________________________________\n");

}

void currentstring(char *s)
{

	printf("current string-\n");
	printf("%s\n",s);
	printf("____________________________________\n");

}

void newstring(char *s)
{

	bzero(s,sizeof(s));
	printf("Enter new string-\n");
	scanf(" %[^\n]",s);

}
