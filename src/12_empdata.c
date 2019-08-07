/*Write a program to implement Employee database program using Double linked list. The database should be permanent.    
 * Database should have members like Employee ID, age, sex, name, address, branch, designation, date of joining etc. There should be options to add, delete, modify, search,print database. */

#include"12_empdata.h"
int main()
{
	int r=0,d=0;
	char option;
	ed *hptr=0;
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
		printf("File nt prst\n");
		return 0;
	}
	else
		file(&hptr);
	printf("\n\t\t====================Employee Database===================\n");
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
					r=add(&hptr);
					if(r==0)
						continue;
					printf("\ndo you want to continue y/n : ");
					scanf(" %c",&c);
					fflush(stdout);
					if(c=='n'||c=='N')
						break;
				}
			}
			else if(option=='2')
			{
				do
				{
					r=delete_node(&hptr);
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
			sleep(2);
		}
	}

}
int file(ed **p)
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
		printf("\nsystem error occured....1");
		return 0;
	}
	fp=fopen("memory","r");
	if(fp!=NULL)
	{
		ed *temp=(ed*)malloc(sizeof(ed));
		while(fscanf(fp,"%s%d%d%s%s%s%s%[^\n]s",temp->name,&temp->id,&temp->age,temp->sex,temp->address,temp->branch,temp->designation,temp->doj)!=EOF)
		{
			do
			{
				r=link1(temp,p);
			}while(r==0);
			temp=(ed*)malloc(sizeof(ed));
		}
		free(temp);
	}
	return 1;
}

int filesave(ed **temp)
{
	ed *ptr=*temp;
	fp=fopen("memory","w");
	if(fp==NULL)
	{
		if(ptr==NULL)
		{
			printf("\nsystem error occured 2");
			return 0;
		}
	}
	char c=0;
	printf("\ndo you want to save the date for future reference..y/n : ");
	scanf(" %c",&c);
	while(ptr!=0)
	{
		fprintf(fp,"%s %d %d %s %s %s %s %s\n",ptr->name,ptr->id,ptr->age,ptr->sex,ptr->address,ptr->branch,ptr->designation,ptr->doj);
		ptr=ptr->next;
	}
	printf("\nstudent details are stored in file..\n");
	fclose(fp);
	return 1;
}

int count(ed *p)
{
        if(p==NULL)
        {
                printf("\nerror occured....2\n");
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


int add(ed **temp)
{
	if(temp==NULL)
	{
		printf("\nsystem error occured....3");
		return 0;
	}
	int r;
	ed *new=*temp;
	new=(ed *)malloc(sizeof(ed));

	if(new==NULL)
	{
		printf("\nmalloc failed\n");
		return 0;
	}

	printf("\nenter Employee name : ");
	scanf(" %[^\n]s",new->name);
	do{
		printf("\nenter Employee ID : ");
		r=scanf("%d",&new->id);
		if(r!=1)
		{
			printf("\nwrong input try again..");
			scanf("%*s");
		}
	}while(r!=1);
	do
	{
		printf("\nenter Employee age : ");
		r=scanf("%d",&new->age);
		if(r!=1)
		{
			printf("\nwrong input try again..");
			scanf("%*s");
		}
	}while(r!=1);

	printf("\nEnter sex - male/female : ");
	scanf(" %s",new->sex);

	printf("\nEnter employee address : ");
	scanf(" %[^\n]s",new->address);

	printf("\nenter Employee branch : ");
	scanf(" %s",new->branch);

	printf("\nenter Employee designation : ");
	scanf(" %s",new->designation);

	printf("\nenter Employee doj : ");
	scanf(" %s",new->doj);


	if(*temp==0)	
	{
		new->prv=0;
		new->next=0;
		*temp=new;
	}
	else
	{
		new->prv=(*temp)->prv;
		(*temp)->prv=new;
		new->next=*temp;
		*temp=new;
	}
	return 1;

}

int link1(ed *temp,ed **m)
{
	if(temp==NULL&&m==NULL)
	{
		printf("\nsystem error occured...");
		return 0;
	}
	ed *p=temp;
	if(*m==0)
	{
		p->next=p->prv=0;
		*m=p;
	}
	else
	{
		ed *la=*m;
		if(la==NULL)
		{
			printf("\nerror occured\n");
			return 0;
		}
		while(la->next!=0)
			la=la->next;
		p->next=0;
		p->prv=la;
		la->next=p;

	}return 1;

}

int print(ed *p)
{
	if(fp==NULL)
	{
		if(p==NULL)
		{
			printf("\nerror occured...1\n");
			return 0;
		}
	}
	printf("Name-\t| ID-\t| Age-\t| Sex-\t  |      Address-\t\t| Branch-\t| Designation-\t| DOJ-\n");
	printf("____________________________________________________________________________________________\n");
	while(p)
	{
		printf("%s\t| %d\t| %d\t| %s   \t| %s\t  | %s\t| %s\t| %s\n",p->name,p->id,p->age,p->sex,p->address,p->branch,p->designation,p->doj);
		p=p->next;
	}
	return 1;
}

int delete_node(ed **hptr)
{
	if(fp==NULL)
	{
		if(hptr==NULL)
		{
			printf("\nerror occured....3\n");
			return 0;
		}
	}
	int i,c,n;
	ed *p=*hptr;
	if(fp==NULL)
	{
		if(p==NULL)
		{
			printf("\nerror occured....2\n");
			return 0;
		}
	}
	c=count(*hptr);
	printf("enter the node num...\n");
	scanf("%d",&n);
	for(i=0;i<c;i++)
	{
		if(i==(n-1))
		{
			if((*hptr)==p)
			{
				if(p->next!=0)
					p->next->prv=0;
				*hptr=p->next;

			}
			else if(p->next==0)
			{
				p->prv->next=0;
			}
			else
			{
				p->prv->next=p->next;
			}

			free(p);

		}
		p=p->next;
	}
	printf("delete node\n");
	return 1;
}


int search(ed *p)
{
	int l=0;
	char m=0;
	if(p==NULL)

		printf("\nerror occured....4\n");

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

int searchname(ed *p)
{
	if(p==NULL)
	{
		printf("\nerror occured....5\n");
	}
	char s[20];
	int re=0;
	do
	{
		printf("enetr name\n");
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
			printf("%s %d %d %s %s %s %s %s\n",p->name,p->id,p->age,p->sex,p->address,p->branch,p->designation,p->doj);
			printf("...........................................................................\n");
			return 0;
		}
		p=p->next;
	}
	printf("name not found\n");
	return 0;
}
int searchid(ed *p)
{
	if(p==NULL)
	{
		printf("\nerror occured...6\n");
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
			printf("%s %d %d %s %s %s %s %s\n",p->name,p->id,p->age,p->sex,p->address,p->branch,p->designation,p->doj);
			printf("...........................................................................\n");
			return 0;

		}
		p=p->next;
	}
	printf("id not found\n");
return 0;
}

int modify(ed **ptr)
{

	if(ptr==NULL)
	{
		printf("\nsystem error occured....7");
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


int modify_name(ed **ptr)
{
	if(ptr==NULL)
	{
		printf("\nsystem error occured...8\n");
		return 0;
	}
	int check=0;
	char sname[50];
	ed *test=*ptr;
	printf("\nenter the name: ");
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
		printf("\nname not found......");
	return 1;
}

int modify_id(ed **ptr)
{
	if(ptr==NULL)
	{
		printf("\nsystem error occured....9\n");
		return 0;
	}
	int check=0,newid=0;
	ed *test=*ptr;
	do
	{
		printf("\nEnter the employment id: ");
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
		printf("\nEmplyoment ID not found......");
	return 1;
}
int datachange(ed **ptr)
{
	system("clear");
	int check=0,t=0;
	ed *test=*ptr;
	while(1)
	{
		printf("1)Name-%s 2)id-%d 3)age-%d 4)sex-%s 5)address-%s 6)branch-%s 7)designation-%s 8)doj-%s\n",test->name,test->id,test->age,test->sex,test->address,test->branch,test->designation,test->doj);
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
			case 5:printf("\nenter address : ");
			       scanf(" %[^\n]",test->address);
			       break;
			case 6:printf("\nenter branch : ");
			       scanf(" %[^\n]",test->branch);
			       break;
			case 7:printf("\nenter designation : ");
			       scanf(" %[^\n]",test->designation);
			       break;
			case 8:printf("\nenter doj : ");
			       scanf(" %[^\n]",test->doj);
			       break;
			default:printf("\nwrong choice\n");
				datachange(ptr);
		}
	}
}
