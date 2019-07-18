/*	Write a program for a matchstick game being played between the computer and a user. 
 *	Your program should ensure that the computer always wins. 
 * 	
 *	Rules for the game are as follows:
 *	There are 21 matchsticks.Maximum number of matchsticks a player can pick is 4.i.e The player can pick 1, 2, 3, or 4 
 *	matchsticks.After the person picks, the computer does its picking.Whoever is forced to pick up the last matchstick
 *	loses the game.
 */

#include"../inc/2_matchstik.h"
void main()
{
	int matchstick=NUMBER_OF_MATCHSTICKS;
	int comp,user,r;
	while(matchstick>=1)
	{
		system("clear");
		printf("\t-------Welcome to Matchstick Game-------\n");
		printf("\n---------------------------------------\n\n");
		if(matchstick==1)
		{
			printf("remaining matchstick=%d\n",matchstick);
			printf("have to pick 1-4....\n");
		
			printf("\t user turn:");
			scanf("%d",&user);
			printf("user=%d",user);

		printf("\n---------------------------------------\n");
			printf("\ncomputer won the game...\n");
		printf("\n---------------------------------------\n\n");
			break;
		}

		while(1)
		{
			printf("remaining matchstick=%d\n",matchstick);

			printf("\n---------------------------------------\n");
		
			printf("have to pick 1-4....\n");
		
			l1:printf("\t user turn:");
			r=scanf("%d",&user);
			printf("user=%d",user);
			printf("\n---------------------------------------\n");
			
			if(r==0)
			{
			printf("wrong input\n");
			scanf("%*s");
			goto l1;
			}

			if(user<=0 ||user>4)
			{
				printf("\nWrong pick no...\n");
				continue;
			}

			comp=5-user;

			printf("\n\t computer turn:");
			printf("\n");
			printf("copmuter take =%d\n",comp);

			sleep(2);
			matchstick=matchstick-user-comp;
			break;

		}
	}
}
