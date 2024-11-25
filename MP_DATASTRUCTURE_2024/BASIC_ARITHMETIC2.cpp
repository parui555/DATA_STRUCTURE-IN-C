#include<stdio.h>
#include<conio.h>


void add();
void sub();
void multi();
void div();


int main()
{
	add();
	sub();
	multi();
	div();
	getch();
	return 0;
}


void add()
{
	int x,y;
	printf("\n\n..........ADDITION........");
	printf("\nEnter value of X=");
	scanf("%d",&x);
	printf("\nEnter value of Y=");
	scanf("%d",&y);
	int sum=x+y;
	printf("\n Addition of the two number=%d",sum);
}

void sub()
{
	int x,y;
	printf("\n\n..........SUBTRACTION........");
	printf("\nEnter value of X=");
	scanf("%d",&x);
	printf("\nEnter value of Y=");
	scanf("%d",&y);
	int sub=x-y;
	printf("\n Subtraction of the two number=%d",sub);
	
}


void multi()
{
	int x,y;
	printf("\n\n..........MULTIPLICATION........");
	printf("\nEnter value of X=");
	scanf("%d",&x);
	printf("\nEnter value of Y=");
	scanf("%d",&y);
	int multi=x*y;
	printf("\n Multiplication of the two number=%d",multi);
	
}


void div()
{
	float x,y;
	printf("\n\n..........DIVITION........");
	printf("\nEnter value of X=");
	scanf("%d",&x);
	printf("\nEnter value of Y=");
	scanf("%d",&y);
	float div=x/y;
	printf("\n Divition of the two number=%d",div);
	
}