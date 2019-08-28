/*write a program that will accept the cricket match performance details (runs scored, catches taken, wickets taken, number of fours hit and number of sixes hit) of every player in a match. This data will be entered for each player in each team, for 3 matches of a series. These details must be available even after the program has been terminated. Restrict the number of players in a team to 3 and the number of teams to 2.
Also make a custom menu. This menu must display the names of all the players currently present in the database. The menu must also give the player the ability to view, modify and delete the information of the players.*/

#include"17_cricket.h"
int main()
{

	cricket *hptr1=0,*hptr2=0,**team;
	char c,filename[20];
	int option;

	fp=fopen("india","r");
	if(fp==0)
	{
		fp=fopen("india","a");
	}
	fp=fopen("australia","r");
	if(fp==0)
	{
		fp=fopen("australia","a");
	}
//	printf("\n\n_______________Previous Data___________________\n\n");
	if(fp==0)
	{
		fclose(fp);
		printf("File not present\n");
		return 0;
	}
	else
	{
		do
		{
			r=file(&hptr1,"india");
		}while(r==0);
		do
		{
			r=file(&hptr2,"australia");
		}while(r==0);
	}
	printf("\n=====================CRICKET MATCH PERFORMANCE DETAILS=======================");
	while(1)
	{
		while(1)
		{
			printf("\n1)INDIA\n2)AUSTRAILIA\nenter option : ");
			r=scanf("%d",&option);
			if(r==0)
			{
				printf("\nwrong input..");
				scanf("%*s");
				continue;
			}
			if(option==1)
			{
				team=&hptr1;
				strcpy(filename,"india"); 
				break;
			}
			else if(option==2)
			{
				team=&hptr2;
				strcpy(filename,"australia");
				break;
			}
			else
				printf("\nwrong input..");
		}
		while(1)
		{       

			printf("\nA)Add match performance details\nB)delete performance details\nc)modify performance details\nD)print match details\nS)save details\nE)change team\nX)exit\nenter a option : ");
			scanf(" %c",&c);
			system("clear");
			if(c=='a'||c=='A')
			{
				do
				{
					r=database(team);
				}while(r==0);	
			}
			else if(c=='b'||c=='B')
			{
				do
				{	
					r=delete(team);
				}while(r==0);
			}
			else if(c=='c'||c=='C')
			{
				do
				{
					r=modify(team);
				}while(r==0);
			}
			else if(c=='d'||c=='D')
			{      
				do
				{	
					r=print(*team);
				}while(r==0);	
			}
			else if(c=='E'||c=='e')
			{
				break;
			}
			else if(c=='s'||c=='S')
			{
				do
				{
					r=filesave(*team,filename);
				//	r=filesave(*team,filename);
				}while(r==0);
			}
			else if(c=='x'||c=='X')
			{
				return 0;
			}
			else
			{
				printf("\nwrong choice...try again");
				continue;
			}
			sleep(1);
		}
            if(c=='x'||c=='X')
            break;
	}
	fclose(fp);
}

int file(cricket **ptr,const char *filename)       /*adding file data's into program*/
{   
	int i,j,fsize;
	if(ptr==NULL&&filename==NULL)
	{
		printf("\nsystem error occured....");
		return 0;
	}   
	fp=fopen(filename,"a+");
	fseek(fp,-2,2);
	fsize=ftell(fp);
	rewind(fp);
        if(fsize!=0)
	{
		cricket *temp=(cricket*)malloc(sizeof(cricket));
			while(fscanf(fp,"%s%d%d%d%d%d%d",temp->name,&temp->jersey,&temp->run,&temp->catch,&temp->wickets,&temp->six,&temp->four)!=EOF)
			{
			do
			{
				r=linklist(temp,ptr);
			}while(r==0);      
			temp=(cricket*)malloc(sizeof(cricket));
                        }
	}
	fclose(fp);
	return 1;
}                                              
int database(cricket **ptr)                     
{       
	if(ptr==NULL)
	{
		printf("\nsystem error occured..");
		return 0;
	}
	int r;
	cricket *temp;	
		temp=(cricket*)malloc(sizeof(cricket));  
		printf("\nenter player name : ");
		scanf(" %[^\n]s",temp->name); 
		do
		{
			printf("\nenter runs taken : ");
			r=scanf("%d",&temp->run);
			if(r!=1)
			{
				printf("\nwrong input try again..");
				scanf("%*s");
			}
		}while(r!=1);
		do
		{
			printf("\nenter jersey number : ");
			r=scanf("%d",&temp->jersey);
			if(r!=1)
			{
				printf("\nwrong input try again..");
				scanf("%*s");
			}
		}while(r!=1);
		do
		{
			printf("\nenter number of catch : ");
			r=scanf("%d",&temp->catch);
			if(r!=1)
			{
				printf("\nwrong input try again..");
				scanf("%*s");
			}
		}while(r!=1);
		do
		{
			printf("\nenter total wickets : ");
			r=scanf("%d",&temp->wickets);
			if(r!=1)
			{
				printf("\nwrong input try again..");
				scanf("%*s");
			}
		}while(r!=1);
		do
		{
			printf("\nenter total sixes : ");
			r=scanf("%d",&temp->six);
			if(r!=1)
			{
				printf("\nwrong input try again..");
				scanf("%*s");
			}
		}while(r!=1);
		do
		{
			printf("\nenter total four : ");
			r=scanf("%d",&temp->four);
			if(r!=1)
			{
				printf("\nwrong input try again..");
				scanf("%*s");
			}
		}while(r!=1);
		do
		{
			r=linklist(temp,ptr);
		}while(r==0);
	
	return 1;

}
int delete(cricket **ptr)
{
	if(ptr==NULL)
	{
		printf("\nsystem error occured");
		return 0;
	}
	int test,check;
	do
        {
        printf("\nusing\n1)name\n2)jersey num\noption : ");
        check=scanf("%d",&test);
	if(check==0)
        {
                printf("\nwrong chioce...");
		scanf("%*s");
        }
        }while(check==0);

	if(test==1)
	{
		do{test=name(ptr);}while(test==0);
                printf("\nplayer details deleted.....");
	}
	else if(test==2)
	{
		do{test=ID(ptr);}while(test==0);
                printf("\nplayer details deleted.....");
	}
	else
	{
		printf("\nwrong choice...\n");
		delete(ptr);
	}
	return 1;
}
int modify(cricket **ptr)
{
	if(ptr==NULL)
	{
		printf("\nsystem error occured");
		return 0;
	}
	int test,check;
	do
        {
        printf("\nenter\n1)name\n2)jersey num\noption : ");
	check=scanf("%d",&test);
        if(check==0)
	{
                printf("\nwrong choice....");
		scanf("%*s");
	
	}
        }while(check==0);
	if(test==1)
	{
		do{test=moname(ptr);}while(test==0);               
                printf("\nplayer details updated.....");
	}
	else if(test==2)
	{
		do{test=moID(ptr);}while(test==0);
                printf("\nplayer details updated....");
	}
	else
	{
		printf("\nwrong choice...\n");
		modify(ptr);
	}
	return 1;
}
int linklist(cricket *temp,cricket **ptr)                        //funtion will make datas in linklist format
{
	if(temp==NULL&&ptr==NULL)
	{
		printf("\nsystem error occured...");
		return 0;
	}
	cricket *last;
	temp->next=0; 
	if(*ptr==0)
	{
		*ptr=temp;
        }
	else
	{       
	
		last=*ptr;
		while(last->next!=0)
		{	
                   last=last->next;		
		}
		last->next=temp;
	}
	return 1;
}
int name(cricket **ptr)                             
{ 
	if(ptr==NULL)
	{
		printf("\nsystem error occured..");
		return 0;
	}
	int check=0,j;
	char sname[50];
	cricket *test=*ptr,*last;
	printf("\nenter player name: ");
	scanf(" %[^\n]s",sname);
	while(test!=0)
	{
			if(strcmp(test->name,sname)==0)  //to check repeatation of given name 
			{
				check++;
			}
		test=test->next;
	}
	if(check==1)
	{ 
		test=*ptr;
		while(test!=0)
                {
				if(strcmp(test->name,sname)==0)
				{
					if(*ptr==test)
					{
						*ptr=test;
						free(test);
					}
					else
					{
						last->next=test->next;
						free(test);
					}
					break;
				}
			last=test;
			test=test->next;
		}
	}
	else if(check>=2)
	{
		printf("\nThere are more number of %s\n",sname);
		do{check=ID(ptr);}while(check==0);
	}
	else
		printf("\nname not found......");
	return 1;
}
int ID(cricket **ptr)
{
	if(ptr==NULL)
	{
		printf("\nsystem error occured..");
		return 0;
	}
	int check=0,s_id;
	cricket *test=*ptr,*last;
	do
        {
        printf("\nenter player jersey num : ");
	check=scanf("%d",&s_id);
        if(check==0)
        {
                printf("\nwrong choice....");
                scanf("%*s");

        }
        }while(check==0);
        check=0;
	while(test!=0)
	{
		if(test->jersey==s_id)
		{
			if(*ptr==test)
			{ 
				*ptr=test;
				free(test);
			}
			else
			{
				last->next=test->next;
				free(test);
			}
			check=1;
                        break;
		}
		last=test;
		test=test->next;
	}
	if(check==0)
		printf("\njersey number not found......");
	return 1;
}
int moname(cricket **ptr)         
{
	if(ptr==NULL)
	{
		printf("\nsystem error occured..");
		return 0;
	}
	int check=0;
	char sname[50];
	cricket *test=*ptr;
	printf("\nenter player  name: ");
	scanf(" %[^\n]s",sname);
	while(test!=0)
	{
		if(strcmp(test->name,sname)==0)
		{
			check++;
		}
		test=test->next;
	}
	if(check==1)
	{
		test=*ptr;
		while(test!=0)
		{
			if(strcmp(test->name,sname)==0)
			{
				datachange(&test);
				break;
			}
		test=test->next;

		}
	}
	else if(check>=2)
	{
		printf("\nThere are more number of %s\n",sname);
		do{check=moID(ptr);}while(check==0);
	}
	else
	printf("\nplayer name not found......");
return 1;
}
int moID(cricket **ptr)
{
	if(ptr==NULL)
	{
		printf("\nsystem error occured..");
		return 0;
	}
	int check=0,s_id;
	cricket *test=*ptr;
       do
       {
	printf("\nenter jersey number : ");
	check=scanf("%d",&s_id);
        if(check==0)
         {
          printf("\nwrong input..");
          scanf("%*s");
          }
        }while(check==0);
        check=0;
        while(test!=0)
	{
		if(test->jersey==s_id)
		{
			datachange(&test);
			check=1;
			break;
		}
		test=test->next;
	}
	if(check==0)
		printf("\njersey num not found......");
return 1;
}
int datachange(cricket **ptr)
{
	system("clear");
	int check;
	cricket *test=*ptr;
	printf("\n1)jersey:%d\n2)NAME:%s\n3)Run:%d\n4)Catch:%d\n5)Wickets:%d\n6)Six:%d\n7)Four:%d\nenter a option : ",test->jersey,test->name,test->run,test->catch,test->wickets,test->six,test->four);
	scanf("%d",&check);
	switch(check)
	{
		case 1: printf("\nenter jersey num : ");
			scanf("%d",&test->jersey);
			break;
		case 2:printf("\nenter name : ");
		       scanf(" %[^\n]",test->name);
		       break;
		case 3:printf("\nenter runs : ");
		       scanf("%d",&test->run);
		       break;
		case 4:printf("\nenter catchs : ");
		       scanf("%d",&test->catch);
		       break;
		case 5:printf("\nenter wickets : ");
		       scanf("%d",&test->wickets);
		       break;
		case 6:printf("\nenter no.of six : ");
		       scanf("%d",&test->six);
		       break;
		case 7:printf("\nenter no.of four : ");
		       scanf("%d",&test->four);
		       break;
		default:printf("\nwrong choice");
			datachange(ptr);
	}
}
int print(cricket *temp)
{
	if(temp==NULL)
	{
		if(fp==NULL)
		{
			printf("\nfile not present..\n");
			return 0;
		}

		printf("\nsystem error occured..\n");
		return 0;
	}
	while(temp!=0)
	{         
	printf("\n=========================");
	printf("\nname     : %s\nJersey no: %d\nRuns     : %d\nCatch    : %d\nWickets  : %d\nSix      : %d\nFour     : %d\n\n",temp->name,temp->jersey,temp->run,temp->catch,temp->wickets,temp->six,temp->four);
	temp=temp->next;
	}
return 1;
}
int filesave(cricket *temp,char *filename)
{
int j;
        fp=fopen(filename,"w");
	if(temp==NULL)
	{
		printf("\nsystem error occured ");
		return 0;
	}
	char c;
      while(1)
      {
	printf("\ndo you want to save the data for future reference..y/n : ");
	scanf(" %c",&c);
        if(c=='y'||c=='Y')
        {
	while(temp!=0)
	{
			fprintf(fp,"%s %d %d %d %d %d %d\n",temp->name,temp->jersey,temp->run,temp->catch,temp->wickets,temp->six,temp->four);	
		temp=temp->next;
	}
	printf("\nplayer details are stored in file..\n");
        break;
        }
        else if(c=='n'||c=='N')
        break;	
        else
        printf("\nwrong input");
      }
       return 1;
}
