/*	Write a program for a matchstick game being played between the computer and a user. 
 *	Your program should ensure that the computer always wins. 
 * 	
 *	Rules for the game are as follows:
 *	There are 21 matchsticks.Maximum number of matchsticks a player can pick is 4.i.e The player can pick 1, 2, 3, or 4 
 *	matchsticks.After the person picks, the computer does its picking.Whoever is forced to pick up the last matchstick
 *	loses the game.
 */

#include"../inc/2_matchstik.h"

int main()
{
	int matchstick=21;
	int comp,user;
	while(matchstick>=1)
	{
		system("clear");
		printf("\t-------Welcome to Matchstick Game-------\n");
		printf("\n---------------------------------------\n\n");
		if(matchstick==1)
		{
			printf("computer won the game...\n");
			break;
		}

		printf("remaining matchstick=%d\n",matchstick);
		printf("\n---------------------------------------\n");
l1:printf("have to pick 1-4....\n");
   printf("\t user turn:");
   scanf("%d",&user);
   printf("user=%d",user);
   printf("\n---------------------------------------");
   if(user<=0 ||user>4)
   {
	   printf("\nWrong pick no...\n");
	   goto l1;
   }

   comp=5-user;

   printf("\n\t computer turn:");
   printf("\n");
   printf("copmuter take =%d\n",comp);

   matchstick=matchstick-user-comp;
   sleep(2);
   continue;
	
	}
	matchstick--;
}
