/*Implement a binary seacrh tree to find a particular word from an array of 50 names.*/

#include"16_bst.h"    

int main()
{
	root=NULL;
	char str[SIZE],c=0,n[RANGE];
	struct node *t=NULL;
	int op=0,ret=0;
	while(1)
	{
		printf("\n\nchoose option: 1)add BST 2)print 3)search 4)exit\n");
		printf("enter the option\n");
		ret=scanf("%d",&op);
		if(ret==0)
		{
			printf("wrong input\n");
			scanf("%*s");
			continue;
		}
		switch(op)
		{
			case 1:
				while(1)
				{
					printf("Enter name: ");
					scanf("%s",str);	
					insert(str);
					printf("Wants to insert more item: ");
					scanf(" %c",&c);
					if(c=='y')
						continue;
					else
						break;
				}
				break;

			case 2:printf("print BST\n");
			       displayin(root);
			       break;

			case 3:
			       while(1)
			       {
				       if(root==NULL)
				       {
					       printf("empty tree\n");
					       main();
				       }
				       printf("\nsearch the word from BST\n");
				       printf("enter new name\n");
				       scanf("%s",n);    
				       t= search(root,n);
				       if(t==0)
				       {		
					       printf("not found\n");
					       main();
				       }
				       else
					       printf("word is found %s\n",t->name);
				       main();
				
			       }

			case 4:return 0;

			default:printf("wrong option\n");
				break;
		}
	}
}

void insert(char *str)
{
	struct node *parent=0,*location=0,*temp=0;
	find(str,&parent,&location);
	if(location!=NULL)
	{
		return;
	}
	temp=(struct node*)malloc(sizeof(struct node));

	temp->name=strdup(str);

	temp->lchild=NULL;
	temp->rchild=NULL;

	if(parent==NULL)
		root=temp;
	else
		if(strcmp(str,parent->name)<0)
			parent->lchild=temp;
		else
			parent->rchild=temp;
}

void find(char *str,struct node **par,struct node **loc)
{
	struct node *ptr=0,*ptrsave=0;
	if(root==NULL)
	{
		*loc=NULL;
		*par=NULL;
		return;
	}
	if(!(strcmp(str,root->name)))
	{
		*loc=root;
		*par=NULL;
		return;
	}
	if(strcmp(str,root->name)<0)
	{
		ptr=root->lchild;
	}

	else
	{
		ptr=root->rchild;
	}
	ptrsave=root;
	while(ptr!=NULL)
	{
		if(!(strcmp(str,ptr->name)))
		{
			*loc=ptr;
			*par=ptrsave;
			return;
		}
		ptrsave=ptr;
		if(strcmp(str,ptr->name)<0)
			ptr=ptr->lchild;
		else
			ptr=ptr->rchild;
	}
	*loc=NULL;
	*par=ptrsave;
}


struct node* search(struct node *root,char *temp)
{
	if(root==NULL || strcmp(root->name,temp)==0)
		return root;

	if(strcmp(root->name,temp)<0)
		return search(root->rchild,temp);
	return search(root->lchild,temp);
}

void displayin(struct node *ptr)
{
	if(root==NULL)
	{
		printf("Tree is empty");
		return;
	}
	if(ptr!=NULL)
	{
		displayin(ptr->lchild);
		printf("%s -> ",ptr->name);
		displayin(ptr->rchild);
	}
}


