/* Run an infinite loop trying to accept user inputs, validate them for positivity. If number is invalid, don't process and go back to input request. If valid: check if it's even number add it to a variable which holds the sum of all even numbers input so far. If odd number, save it in another variable which always gets updated with odd numbers such that it has only the largest odd number entered so far. If user gives zero as input at any point, get out of the loop immediately and print the even-summation variable and the max odd number stored. Do not use 'else' anywhere in the code.*/

#include"../inc/4_num.h"

void main()
{
	int even=0,odd=0,num,count[100];

l1:do
   {
l2: printf("Enter the number\n");
    scanf("%d",&num);

    printf("num=%d\n",num);
    if(num<0)
    {
	    printf("Invalid input\n");
	    goto l1;
    }

    if(num==0)
    {
	    printf("Sum of even no=%d\n",even);
	    printf("max odd number=%d\n",odd);
	    return;
    }
    while(num)
    {
	    if(num%2==0)
	    {
		    even=even+num;
		    //		   printf("Sum of even no=%d\n",even);
l3:			goto l2;
	    }

	    if(num%2!=0)
	    {
		    if(num>odd)
		    {
			    odd=num;
			    //					printf("max odd number=%d\n",odd);

		    }
		    goto l3;
	    }
    }

   }while(1);
}
