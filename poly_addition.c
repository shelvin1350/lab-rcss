#include <stdio.h>
int i, j, n3;
int coefsum[10], expsum[10];
void display(int n, int coef[], int expo[])
{

	for(i=0; i<n; i++)
	{
		
		if(expo[i]==0)
		{
			printf("%d", coef[i]);
		}
		else
		{
			printf("%dx^%d", coef[i], expo[i]);
		}
		if(i!=n-1)
		{
			printf(" + ");
		}
		
	}
	printf("\n");
}
void add(int coef1[], int exp1[], int coef2[], int exp2[], int n1, int n2)
{
	
	int i, j, k=0;
	i=0; 
	j=0;
	while(i<n1 && j<n2)
	{	
		if(exp1[i]==exp2[j])
		{
			expsum[k]=exp1[i];
			coefsum[k]=coef1[i]+coef2[j];
			i++;j++;k++;
		}
		else if(exp1[i]<exp2[j])
		{
			expsum[k]=exp2[j];
			coefsum[k]=exp2[j];
			j++;k++;
		}
		else
		{
			expsum[k]=exp1[i];
			coefsum[k]=coef1[i];
			i++; k++;
		}
	}
	if(i<n1)
	{
		expsum[k]=exp1[i];
		coefsum[k]=exp1[i];
		i++; k++;
	}
	else if(j<n2)
	{
		expsum[k]=exp2[j];
		coefsum[k]=coef2[j];
		j++; k++;
	}
	n3=k;
	display(n3, coefsum, expsum);
}
void read(int coef1[],int  expo1[], int coef2[], int expo2[], int n1, int n2)
{
	int n;
	printf("Enter the first polynomial for addition\n");
	for(i=0; i<n1; i++)
	{
		printf("Enter the coefficient and exponent: ");
		scanf("%d%d", &coef1[i], &expo1[i]);	
	}
	printf("Enter the second polynomial for addition\n");
	for(i=0; i<n2; i++)
	{
		printf("Enter the coefficient and exponent: ");
		scanf("%d%d", &coef2[i], &expo2[i]);	
	}
	printf("\n1st polynomials : ");
	display(n1, coef1, expo1);	
	printf("\n2nd polynomials : ");
	display(n2, coef2, expo2);
}

int main()
{
	int coef1[10], expo1[10], coef2[10], expo2[10], n1, n2;
	printf("Enter the number of digits in first polynomial: ");
	scanf("%d", &n1);
	printf("Enter the number of digits of second polynomial: ");
	scanf("%d", &n2);
	read(coef1, expo1, coef2, expo2, n1, n2);
	add(coef1, expo1, coef2, expo2, n1, n2);
	return 0;
}
