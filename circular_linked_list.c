#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node node;
node *head=NULL;
void insert(int e)
{
	if(head==NULL)
	{
		head=(node *)malloc(sizeof(node));
		head->data=e;
		head->next=head;
	}
	else
	{
		node *t=head;
		while(t->next!=head)
		{
			t=t->next;
		}
		t->next=(node *)malloc(sizeof(node));
		t->next->data=e;
		t->next->next=head;
	}
}
void delete(int e)
{
	if(head==NULL)
	{
		printf("Empty list!!");
	}
	else
	{
		node *t;
		if(head->data==e && head->next==head)
		{
			printf("Deleted element is %d\n", head->data);
			head=NULL;
		}
		else if(head->data==e)
		{
			t=head;
			while(t->next!=head)
			{
				t=t->next;
			}
			t->next=head->next;
			head=head->next;
		}
		else
		{
			t=head;
			while(t->next->data!=e && t->next!=head)
			{
				t=t->next;
			}
			if(t->next==head)
			{
				printf("Element not found!!");
			}
			else
			{
				printf("Deleted element is %d\n", t->next->data);
				t->next=t->next->next;
			}
		}
	}
}
void display()
{
	if(head==NULL)
	{
		printf("Circular linked list is empty!!");
	}
	else
	{
		node *t=head;
		do
		{
			printf("%d\t", t->data);
			t=t->next;
		}while(t!=head);
		printf("\n");
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
