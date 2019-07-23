/*Write a Program to find the paricular "word_to_search" in the string and if found replace it by a user defined word. Use dyanmic memory allocation to take in user defined word.*/

#include"../inc/8_replace.h"

int main() 
{ 
	input();
	result=string_word(str,word,word1);
	output(result);
} 
void input(void)
{

	word1=malloc(sizeof(char)*20);

	if(word1==0)
	{
		printf("malloc failed\n");
		return ;
	}

	printf("\n\n\t\tEnter the string\n\n");
	scanf("%[^\n]s",str);
	printf("......................................\n");
	printf("\nstr=%s\n\n",str);

	printf("......................................\n");
        
while(1)
{
	printf("\t\tEnter the old string\n");
	scanf(" %[^\n]s",word);
	printf("c=%s\n",word);

	if(strstr(str,word)!=NULL)
	{
		break;
	}
		printf("\tword not present\n \tEnter again\n\n");

}
	printf("......................................\n");

	printf("\t\tEnter the new string\n");
	scanf(" %[^\n]s",word1);
	printf("d=%s\n",word1);

	printf("......................................\n");


}
char *string_word(const char *string, const char *old,const char *new) 
{ 
	char *result; 
	int i, count = 0; 
	int new_len = strlen(new); 
	int old_len = strlen(old); 

	if(string==NULL && old==NULL && new==NULL)
	{
		printf("\nwrong input..\n");
		return 0;
	}
	for(i=0;string[i];i++) 
	{ 
		if (strstr(&string[i],old)==&string[i]) 
		{
			count++; 
			i =i+old_len - 1; 
		} 
	} 

	result = (char *)malloc(i + count * (new_len - old_len) + 1); 

	i = 0; 
	while (*string) 
	{ 
		if (strstr(string, old) == string) 
		{ 
			strcpy(&result[i], new); 
			i = i+new_len; 
			string = string+old_len; 
		} 
		else
			result[i++] = *string++; 
	} 

	result[i] = '\0'; 
	return result; 
} 

void output(char *op)
{
	printf("\t\tOutput\n\n");
	printf("Old string: %s\n\n", str); 
	printf("New String: %s\n", op); 
	printf("......................................\n");
} 
