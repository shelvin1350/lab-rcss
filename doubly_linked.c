#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

typedef struct node node;
node *head=NULL;
void insert(int e)
{
	if(head==NULL)
	{
		head=(node *)malloc(sizeof(node));
		head->data=e;
		head->next=NULL;
		head->prev=NULL;
	}
	else
	{
		node *temp=head;
		temp->next=(node *)malloc(sizeof(node));
		temp->next->data=e;
		temp->next->next=NULL;
		temp->next->prev=temp;
	}
}
void delete(int e)
{
	
	if(head==NULL)
	{
		printf("The list is empty!!");
	}
	else
	{
		if(head->data==e && head->next==NULL)
		{
			head=NULL;
		}
		else if(head->data == e)
		{
			
			head=head->next;
		}
		else
		{
			node *temp=head;
			while(temp->data!=e && temp->next!=NULL)
			{
				temp=temp->next;
			}
			if(temp->next==NULL)
			{
				printf("Element not found!!");
			}
			else
			{
				temp->prev->next=temp->next;
				temp->next->prev=temp->prev;
			}
		}
	}
}
void display()
{
	if(head==NULL)
	{
		printf("List is empty");
	}
	else
	{
		node *temp=head;
		while(temp!=NULL);
		{
			printf("%d\t", temp->data);
		}
	}
}
int menu()
{
	int ch;
	printf("1-Insert\n2-Display\n3-Delete\n4-exit\nUr choice:\t");
	scanf("%d", &ch);
	return ch;
}
void process()
{
	int ch, e;
	for(ch=menu(); ch!=4; ch=menu())
	{
		switch(ch)
		{
			case 1:
				printf("Enter a number to insert: ");
				scanf("%d", &e);
				insert(e);
				break;
			case 2:
				display();
				break;
			case 3:
				printf("Enter the element you want to delete: ");
				scanf("%d", &e);
				delete(e);
				break;
			default:
				printf("Invalid input!!");
		}
	}	
}
void main()
{
	process();
}
