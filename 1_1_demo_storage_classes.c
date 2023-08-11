#include <stdio.h>
int a_global;
void demo_global()
{
	printf("\na_global inside the function = %d", a_global);
	printf("\nExited from function\n\n");
}
void reg()
{
	register int r;

	printf("Value of register is %d", r);
	printf("\nExited from function\n\n");
}
void stat()
{
	int i=0;
	while(i<=5)
	{
		static int a_static=0;
		printf("\na_static=%d", a_static);
		a_static++;
		i++;	
	}
	printf("\nExited from function\n\n");
}
void main()
{
	int a_local;
	printf("Before initialization: \n");
	printf("______________________\n");
	printf("\na_global= %d", a_global);
	printf("\na_local = %d", a_local);
	printf("\n\nChange in value of static variable in iteration\n");
	printf("____________________________________________________\n");
	
	stat();
	demo_global();
	reg();
	
}
