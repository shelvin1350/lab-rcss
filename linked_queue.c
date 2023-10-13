#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node queue;
queue *f=NULL, *r=NULL;
void enqueue(int e)
{
	queue *t=(queue *)malloc(sizeof(queue));
	t->data=e;
	t->next=NULL;
	if(f==NULL)
	{
		f=t;
		r=t;
	}
	else
	{
		r->next=t;
		r=t;
	}
}

void dequeue()
{
	if(f==NULL)
	{
		printf("Empty list");
	}
	else
	{
		printf("Dequeued element is %d\n", f->data);
		f=f->next;
		if(f==NULL)
			r=NULL;
	}
}

void main()
{
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	dequeue();
}
