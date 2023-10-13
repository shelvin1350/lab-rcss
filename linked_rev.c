#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
void insert(int e)
{
	struct node *t;
	if(head==NULL)
	{
		head=(struct node *)malloc(sizeof(struct node));
		head->data=e;
		head->next=NULL;
	}
	else
	{
		t=head;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=(struct node *)malloc(sizeof(struct node));
		t->next->data=e;
		t->next->next=NULL;
	}
}
void disp()
{
	struct node *t;
	if(head==NULL)
	{
		printf("Empty list");
	}
	else
	{
		t=head;
		while(t!=NULL)
		{
			printf("%d\t", t->data);
			t=t->next;
		}
	}
}
void reverse(struct node *temp)
{
	if(head==NULL)
	{
		printf("Empty list");
	}
	else
	{
		if(temp!=NULL)
		{
			reverse(temp->next);
			printf("%d\t", temp->data);
		}
	}
}
void main()
{
	insert(10);
	insert(20);
	insert(30);
	insert(40);
	insert(50);
	disp();
	reverse(head);
}
