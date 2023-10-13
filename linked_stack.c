#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;	
};
typedef struct node stack;
stack *top=NULL;
void push(int e)
{
	stack *t;
	t=(stack *)malloc(sizeof(stack));
	t->data=e;
	t->next=top;
	top=t;
}
void pop()
{
	if(top==NULL)
	{
		printf("Empty stack");
	}
	else
	{
		printf("Poped element is %d", top->data);
		top=top->next;
	}
}
void main()
{
	push(20);
	push(30);
	push(40);
	pop();
	pop();
	pop();
	pop();
}
