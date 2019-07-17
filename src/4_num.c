/* Run an infinite loop trying to accept user inputs, validate them for positivity. If number is invalid, don't process and go back to input request. If valid: check if it's even number add it to a variable which holds the sum of all even numbers input so far. If odd number, save it in another variable which always gets updated with odd numbers such that it has only the largest odd number entered so far. If user gives zero as input at any point, get out of the loop immediately and print the even-summation variable and the max odd number stored. Do not use 'else' anywhere in the code.*/

#include"../inc/4_num.h"
void main()
{
	int even=0,odd=0,num=1;
printf("\n..............................................\n\n");
printf("Enter even num will get sum of the even number\n");
printf("Enter odd num will get largest odd number\n");
printf("Enter 0 for output\n");
printf("\n..............................................\n\n");
	while(num!=0)
	{
		printf("Enter the number\n");
		scanf("%d",&num);
printf("\n");

		if(num<0)
		{
			printf("Invalid input\n");
			continue;
		}


		if(num%2==0)
		{
			printf("||......even num-%d...... ||\n\n",num);
		}
		if(num%2!=0)
		{
			printf("||......odd num-%d....... ||\n\n",num);
		}
		if(num%2==0)
		{
			even=even+num;
			continue;
		}

		if(num%2!=0)
		{
			if(num>odd)
			{
				odd=num;
			continue;
printf("||......odd num-%d ||\n",num);

			}
		}
	}
printf("\n.........................................\n\n");
	printf("sum of even    = %d \nlargest odd no = %d\n",even,odd);
printf("\n.........................................\n");

}
