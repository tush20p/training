/*Write a program  to accept and store student data base. The database should consist of any 4 attributes of a student.  User must be able to access the student details by entering the name/roll no. The database must be storst some where so that it may accessst at anytime (even after the program is quit). The data base should have the functionality to :
  1) Add student data
  2) Delete an existing data
  3) Modify any existing data.*/
#include"../inc/studentdata.h"

int main()
{
	int r=0,d=0;
	char option;
	st *hptr=0;
	char c;
	fp=fopen("memory","r");
	if(fp==0)
	{
		fp=fopen("memory","a");
	}
	printf("\n\n_______________Previous Data___________________\n\n");
	if(fp==0)
	{
		fclose(fp);
		printf("File not present\n");
		return 0;
	}
	else
		file(&hptr);
	printf("\n\t\t====================Student Database===================\n");
	while(1)
	{
		printf("\n");
		printf("\t\tMenu\n");
		for(;;)
		{
			printf("\n 1)Add data\n 2)Delete data\n 3)Serach\n 4)modify data\n 5)Print\n 6)Exit\n  Enter a option : ");
			d=scanf(" %c",&option);
			if(d==0)
			{
				printf("wrong input\n");
				scanf("%*s");
				continue;
			}

			system("clear");
			if(option=='1')
			{
				while(1)
				{
					int test=0;
					char ret=1;
					r=add(&hptr);
					if(r==0)
					{
						continue;
					}
					else
					{
						printf("\ndo you want to continue y/n : ");
						scanf(" %c",&c);
						if(c=='y' || c=='Y')
						{
							continue;
						}


					}
					break;

				}
			}


			else if(option=='2')
				{
				do
				{
					r=delete_node(&hptr);
					filesave(&hptr);
					break;
				}while(r==0);
			}
			else if(option=='3')
			{
				do
				{
					r=search(hptr);
				}while(r==0);
			}
			else if(option=='4')
			{
				do
				{
					r=modify(&hptr);
				}while(r==0);
			}
			else if(option=='5')
			{
				do
				{
					r=print(hptr);
				}while(r==0);
			}
			else if(option=='6')
			{
				filesave(&hptr);
				exit(0);
			}
			else
			{
				printf("\nwrong choice...try again");
				continue;
			}
			sleep(1);
		}
	}

}
int file(st **p)
{

	char arr[100];
	fp=fopen("memory","r");
	if(fp==0)
	{
		printf("File nt prst\n");
		return 0;
	}
	while((fgets(arr,100,fp))!=0)
		printf("%s\n",arr);
	if(p==NULL)
	{
		printf("\nsystem error occurst....1");
		return 0;
	}
	fp=fopen("memory","r");
	if(fp!=NULL)
	{
		st *temp=(st*)malloc(sizeof(st));
		while(fscanf(fp,"%s%d%d%s",temp->name,&temp->id,&temp->age,temp->sex)!=EOF)
		{
			do
			{
				r=link1(temp,p);
			}while(r==0);
			temp=(st*)malloc(sizeof(st));
		}
		free(temp);
	}
	return 1;
}

int filesave(st **temp)
{
	st *ptr=*temp;
	fp=fopen("memory","w");
	if(fp==NULL)
	{
		if(ptr==NULL)
		{
			printf("\nsystem error occurst 2");
			return 0;
		}
	}
	char c=0;
	while(1)
	{
		printf("\ndo you want to save the date for future reference..y/n : ");
		scanf(" %c",&c);
		if(c=='Y' || c=='y' )
		{
			while(ptr!=0)
			{
				fprintf(fp,"%s %d %d %s \n",ptr->name,ptr->id,ptr->age,ptr->sex);
				ptr=ptr->next;
			}
			printf("\nStudent details are storst in file..\n");
			fclose(fp);
			return 0;

		}
		else if(c=='n' || c=='N')
			return 1;
		else
			printf("wrong ip\n");
		continue;	
	}
}
int count(st *p)
{
	if(p==NULL)
	{
		printf("\nerror occurst....2\n");
		return 0;
	}

	int c=0;
	while(p)
	{
		c++;
		p=p->next;
	}
	return c;
}


int add(st **temp)
{
	if(temp==NULL)
	{
		printf("\nsystem error occurst....3");
		return 0;
	}
	int r;
	st *new=*temp;
	new=(st *)malloc(sizeof(st));

	if(new==NULL)
	{
		printf("\nmalloc failst\n");
		return 0;
	}

	printf("\nEnter Student Name : ");
	scanf(" %[^\n]s",new->name);
	do{
		printf("\nenter Student ID: ");
		r=scanf("%d",&new->id);
		if(r!=1)
		{
			printf("\nwrong input try again..");
			scanf("%*s");
		}
	}while(r!=1);
	do
	{
		printf("\nEnter Student age : ");
		r=scanf("%d",&new->age);
		if(r!=1)
		{
			printf("\nwrong input try again..");
			scanf("%*s");
		}
	}while(r!=1);

	printf("\nEnter sex - male/female : ");
	scanf(" %s",new->sex);

	if(*temp==0)
	{
		new->next=*temp;
		*temp=new;
	}
	else
	{

		st *last=*temp;
		while(last->next!=0)    
			last=last->next;
		new->next=last->next;
		last->next=new;

	}

	return 1;

}

int link1(st *temp,st **ptr)
{

	if(temp==NULL&&ptr==NULL)
	{
		printf("\nsystem error occured...");
		return 0;
	}
	st *last;
	temp->next=0;
	if(*ptr==0)
	{
		*ptr=temp;}
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

int print(st *p)
{
	if(fp==NULL)
	{
		if(p==NULL)
		{
			printf("\nerror occurst...1\n");
			return 0;
		}
	}
	printf("Name-\t| ID-\t| Age-\t| Sex-\t  |\n");
	printf("___________________________________________\n");
	while(p)
	{
		printf("%s\t| %d\t| %d\t| %s  \t| \n",p->name,p->id,p->age,p->sex);
		p=p->next;
	}
	return 1;
}

int delete_node(st **hptr)
{
	if(hptr==NULL)
	{
		printf("\nerror occurst....3\n");
		return 0;
	}
	int k=0,n=0;
	k=count(*hptr);
	printf("count1=%d\n",k);
	printf("enter the node num...\n");
	scanf("%d",&n);

	if(n<=0 || n>k)
	{
		printf("invalid...\n");
		delete_node(hptr);
		return 0;
	}
	else if(n==1)
	{
		st *temp=*hptr;
		*hptr=temp->next;
		temp->next=NULL;
		free(temp);
		printf("node deleted ..1\n");
	}
	else
	{
		st *p=*hptr,*q;

		int i=1;
		while(i<n-1)
		{
			p=p->next;
			i++;
		}
		q=p->next;
		p->next=q->next;
		q->next=NULL;
		free(q);
		printf("node deleted ..2\n");
	}
return 1;
}



int search(st *p)
{
	int l=0;
	char m=0;
	if(p==NULL)

		printf("\nerror occurst....4\n");

	while(1)
	{
		do
		{	printf("Enter the option 1)search by name 2)search by id 3)new data 4)exit\n ");
			l=scanf(" %c",&m);
			if(l==0)
			{
				printf("wrong input\n");
				scanf("%*d");
			}
			switch(m)
			{
				case '1':searchname(p);
					 break;

				case '2':searchid(p);
					 break;

				case '3':
					 main();

				case '4':exit(0);

				default:printf("wrong option\n");
					break;
			}
		}while(l==0);
	}
}

int searchname(st *p)
{
	if(p==NULL)
	{
		printf("\nerror occurst....5\n");
	}
	char s[20];
	int re=0;
	do
	{
		printf("Enter Name\n");
		re=scanf("%s",s);
		if(re==0)
		{
			printf("wrong input ..1\n");
			scanf("%*s");
		}
	}while(re==0);
	while(p)
	{
		if(strcmp(s,p->name)==0)
		{
			printf("%s %d %d %s \n",p->name,p->id,p->age,p->sex);
			printf(".................................................\n");
			return 0;
		}
		p=p->next;
	}
	printf("name not found\n");
	return 0;
}
int searchid(st *p)
{
	if(p==NULL)
	{
		printf("\nerror occurst...6\n");
	}
	int s=0,ret=0;
	do{
		printf("enetr id\n");
		ret=scanf("%d",&s);
		if(ret==0)
		{
			printf("wrong input ..1\n");
			scanf("%*s");

		}
	}while(ret==0);
	while(p)
	{
		if((s==p->id))
		{
			printf("%s %d %d %s \n",p->name,p->id,p->age,p->sex);
			printf("..................................................\n");
			return 0;

		}
		p=p->next;
	}
	printf("id not found\n");
	return 0;
}

int modify(st **ptr)
{

	if(ptr==NULL)
	{
		printf("\nsystem error occurst....7");
		return 0;
	}
	int test=0,check=0;
	do
	{
		printf("\nenter\n1)name\n2)ID\noption : ");
		check=scanf("%d",&test);
		if(check==0)
		{
			printf("\nwrong choice....");
			scanf("%*s");
			continue;
		}
	}while(check==0);

	if(test==1)
	{
		do
		{
			test=modify_name(ptr);
		}while(test==0);
	}
	else if(test==2)
	{
		do
		{
			test=modify_id(ptr);
		}while(test==0);
	}
	else
	{
		printf("\nwrong choice...\n");
		modify(ptr);
	}
	return 1;
}


int modify_name(st **ptr)
{
	if(ptr==NULL)
	{
		printf("\nsystem error occurst...8\n");
		return 0;
	}
	int check=0;
	char sname[50];
	st *test=*ptr;
	printf("\nEnter Student the name: ");
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
		do
		{
			check=modify_id(ptr);
		}while(check==0);
	}
	else
		printf("\nStudent name not found..\n");
	return 1;
}

int modify_id(st **ptr)
{
	if(ptr==NULL)
	{
		printf("\nsystem error occurst....9\n");
		return 0;
	}
	int check=0,newid=0;
	st *test=*ptr;
	do
	{
		printf("\nEnter the Student id: ");
		check=scanf("%d",&newid);
		if(check==0)
		{
			printf("\nwrong input..");
			scanf("%*s");
		}
	}while(check==0);
	check=0;
	while(test!=0)
	{
		if(test->id==newid)
		{
			datachange(&test);
			check=1;
			break;
		}
		test=test->next;
	}
	if(check==0)
		printf("\nStudent ID not found......");
	return 1;
}
int datachange(st **ptr)
{
	system("clear");
	int check=0,t=0;
	st *test=*ptr;
	while(1)
	{
		printf("1)Name-%s 2)id-%d 3)age-%d 4)sex-%s \n",test->name,test->id,test->age,test->sex);
		printf("Enter the which you have to modify:\n");
		t=scanf("%d",&check);
		if(t==0)
		{
			printf("wrong option\n");
			scanf("%*s");
			continue;
		}

		switch(check)
		{
			case 1:printf("\nenter name : ");
			       scanf(" %[^\n]",test->name);
			       break;
			case 2: printf("\nenter ID : ");
				scanf("%d",&test->id);
				break;
			case 3:printf("\nenter age : ");
			       scanf("%d",&test->age);
			       break;
			case 4:printf("\nenter sex : ");
			       scanf(" %[^\n]",test->sex);
			       break;
			default:printf("\nwrong choice\n");
				datachange(ptr);
		}
		return 0;
	}
}
