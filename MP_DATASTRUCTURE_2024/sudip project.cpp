/* student details */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student{
	char name[10];
	int day1;
	int month1;
	int year1;
	int age;
	char s1[10];
	char s2[10];
	char s3[10];
	char s4[10];
	char s5[10];
	char grade1;
	char grade2;
	char grade3;
	char grade4;
	char grade5;
	char adhaar[15];
	float m1;
	float m2;
	float m3;
	float m4;
	float m5;
	float total;
	float percentage;
	int rank;
	struct student *link;
}node;
int len=0;
int count=2;
int r=-1;
char b;
char c;
char grade(float x)
{
	if (x>=90)
	{
		return 'O';
	}
	else if (x>=80 && x<90)
	{
		return 'E';
	}
	else if (x>=70 && x<80)
	{
		return 'A';
	}
	else if(x>=60 && x<70)
	{
		return 'B';
	}
	else if(x>=50 && x<60)
	{
		return 'C';
	}
	else{
		return 'F';
	}
}
void student_detail(node head,float total_rank){
	node *new1;
	int age;
	new1=(node*)malloc(sizeof(node));
	printf("ENTER %d STUDENT DETAILS\n",count);
	printf("enter %d student name\n",count);
	scanf("%s",&new1->name);
	printf("enter %d student  DATE OF BIRTH\n",count);
	printf("enter DAY\n");
	scanf("%d",&new1->day1);
	printf("enter MONTH\n");
	scanf("%d",&new1->month1);
	printf("enter YEAR\n");
	scanf("%d",&new1->year1);
	age=age_calculate(new1->day1,new1->month1,new1->year1);
	new1->age=age;
	printf("ENTER YOUR ADHAAR NUMBER\n");
	scanf("%s",&new1->adhaar);
	printf("ENTER SUBJECT NAME AND MARKS\n");
	printf("ENTER FIRST SUBJECT NAME\n");
	scanf("%s",&new1->s1);
	printf("ENTER %s MARKS\n",new1->s1);
	scanf("%f",&new1->m1);
	printf("ENTER SECOND SUBJECT NAME\n");
	scanf("%s",&new1->s2);
	printf("ENTER %s MARKS\n",new1->s2);
	scanf("%f",&new1->m2);
	printf("ENTER THIRD SUBJECT NAME\n");
	scanf("%s",&new1->s3);
	printf("ENTER %s MARKS\n",new1->s3);
	scanf("%f",&new1->m3);
	printf("ENTER FOURTH SUBJECT NAME\n");
	scanf("%s",&new1->s4);
	printf("ENTER %s MARKS\n",new1->s4);
	scanf("%f",&new1->m4);
	printf("ENTER FIFTH SUBJECT NAME\n");
	scanf("%s",&new1->s5);
	printf("ENTER %s MARKS\n",new1->s5);
	scanf("%f",&new1->m5);
	b=grade(new1->m1);
	new1->grade1=b;
	b=grade(new1->m2);
	new1->grade2=b;
	b=grade(new1->m3);
	new1->grade3=b;
	b=grade(new1->m4);
	new1->grade4=b;
	b=grade(new1->m5);
	new1->grade5=b;
    new1->total=(new1->m1+new1->m2+new1->m3+new1->m4+new1->m5);
	new1->percentage=(new1->total)/5;
	total_rank[++r]=(new1->total);
	new1->rank=0;
	new1->link=NULL;
	len++;
	count++;
	while(head->link!=NULL)
	{
		head=head->link;
	}
    head->link=new1;
}
void rank(node head,float total_rank){
	int i,j;
	float temp;
	printf("%d is length\n",len);
	for(i=0;i<len-1;i++)
	{
		for(j=i+1;j<len;j++)
		{
			if(total_rank[i]<total_rank[j])
			{
				temp=total_rank[i];
				total_rank[i]=total_rank[j];
				total_rank[j]=temp;
			}
		}
	}
	printf("the sorted array is\n");
	for(i=0;i<len;i++){
			printf("%f ",total_rank[i]);
	}
    while(head!=NULL){
		for(i=0;i<len;i++)
		{
			if(head->total==total_rank[i])
			{
				head->rank=i+1;
			}
		}
		head=head->link;
	}
	printf("1:to add students detail ,2: to display result ,3 : to clear screen,4 : to search student detail\n");
}
void display(node *pts){
	int count1=1,c,i=-1;
	printf("this is output\n");
	while(pts!=NULL){
		c=1;
		printf("the %d person name is: %s\n",count1,pts->name);
		printf("the %d person DATE_OF_BIRTH is: ",count1);
		printf("%d / %d / %d\n",pts->day1,pts->month1,pts->year1);
		printf("the %d person AGE is: %d\n",count1,pts->age);
		printf("the %s ADHAAR NUMBER is : %s\n",pts->name,pts->adhaar);
		printf("the subjcet and marks of %s is\n",pts->name);
		printf("%d number subjcet and marks and grade is:- %s - %f - %c:\n",c,pts->s1,pts->m1,pts->grade1);
		c=c+1;
		printf("%d number subjcet and marks and grade is:- %s - %f - %c:\n",c,pts->s2,pts->m2,pts->grade2);
		c=c+1;
		printf("%d number subjcet and marks and grade is:- %s - %f - %c:\n",c,pts->s3,pts->m3,pts->grade3);
		c=c+1;
		printf("%d number subjcet and marks and grade is:- %s - %f - %c:\n",c,pts->s4,pts->m4,pts->grade4);
		c=c+1;
		printf("%d number subjcet and marks and grade is:- %s - %f - %c:\n",c,pts->s5,pts->m5,pts->grade5);
		printf("THE TOTAL OF %s %s %s %s %s is %f\n",pts->s1,pts->s2,pts->s3,pts->s4,pts->s5,pts->total);
		printf("THE PERCENTAGE OF %s %s %s %s %s is %f\n",pts->s1,pts->s2,pts->s3,pts->s4,pts->s5,pts->percentage);
		printf("%s rank: %d",pts->name,pts->rank);
		pts=pts->link;
		count1++;
		printf("\n...................\n");
	}
}
void search(node* pts){
	char password[8];
	int rank1;
	printf("enter your password\n");
	scanf("%s",&password);
	if(strlen(password)==8){
		printf("enter your rank\n");
		scanf("%d",&rank1);
		while(pts!=NULL){
		if(rank1==pts->rank){
			int c=0;
		printf("THIS IS THE DETAIL OF %S\n",pts->name);
		printf("\n");
		printf("the person name is: %s\n",pts->name);
		printf("%s DATE_OF_BIRTH is: ",pts->name);
		printf("%d / %d / %d\n",pts->day1,pts->month1,pts->year1);
		printf("the person AGE is: %d\n",pts->age);
		printf("the %s ADHAAR NUMBER is : %s\n",pts->name,pts->adhaar);
		printf("the subjcet and marks of %s is\n",pts->name);
		c=c+1;
		printf("%d number subjcet and marks and grade is:- %s - %f - %c:\n",c,pts->s1,pts->m1,pts->grade1);
		c=c+1;
		printf("%d number subjcet and marks and grade is:- %s - %f - %c:\n",c,pts->s2,pts->m2,pts->grade2);
		c=c+1;
		printf("%d number subjcet and marks and grade is:- %s - %f - %c:\n",c,pts->s3,pts->m3,pts->grade3);
		c=c+1;
		printf("%d number subjcet and marks and grade is:- %s - %f - %c:\n",c,pts->s4,pts->m4,pts->grade4);
		c=c+1;
		printf("%d number subjcet and marks and grade is:- %s - %f - %c:\n",c,pts->s5,pts->m5,pts->grade5);
		printf("THE TOTAL OF %s %s %s %s %s is %f\n",pts->s1,pts->s2,pts->s3,pts->s4,pts->s5,pts->total);
		printf("THE PERCENTAGE OF %s %s %s %s %s is %f\n",pts->s1,pts->s2,pts->s3,pts->s4,pts->s5,pts->percentage);
		printf("the rank of %s is: %d\n",pts->name,pts->rank);
		}
		else{
			printf("the given rank not matched\n");
		}
		pts=pts->link;
		}
	}
	else{
		printf("ALERT:password must shoulid be 8 didgit or 8 character\n");
		printf("1:to add students detail ,2: to display result ,3 : to clear screen,4 : to search student detail\n");
	}
}
int age_calculate(int d2,int m2,int y2){
	int y1,m1,d1;
	printf("enter today year\n");
	scanf("%d",&y1);
	printf("enter today month\n");
	scanf("%d",&m1);
	printf("enter today day\n");
	scanf("%d",&d1);	
	if(d1>=d2)
	{
		d2=d1-d2;
	}
	else{
		m1--;
		d1=d1+30;
		d2=d1-d2;
	}
	if(m1>=m2)
	{
	   m2=m1-m2;
	}
	else{
		y1--;
		m1=m1+12;
		m2=m1-m2;
	}
	y2=y1-y2;
	printf("%d year %d month %d day\n",y2,m2,d2);
    return y2;
}
int main(){
	float total_rank[10];
	int age;
	node *head;
	head=(node*)malloc(sizeof(node));
	printf("ENTER 1 STUDENT DETAILS\n");
	printf("enter student name\n");
	scanf("%s",&head->name);
	printf("enter student  DATE OF BIRTH\n");
	printf("enter DAY\n");
	scanf("%d",&head->day1);
	printf("enter MONTH\n");
	scanf("%d",&head->month1);
	printf("enter YEAR\n");
	scanf("%d",&head->year1);
	age=age_calculate(head->day1,head->month1,head->year1);
	head->age=age;
	printf("ENTER YOUR ADHAAR NUMBER\n");
	scanf("%s",&head->adhaar);
	printf("ENTER SUBJECT NAME AND MARKS\n");
	printf("ENTER FIRST SUBJECT NAME\n");
	scanf("%s",&head->s1);
	printf("ENTER %s MARKS\n",head->s1);
	scanf("%f",&head->m1);
	printf("ENTER SECOND SUBJECT NAME\n");
	scanf("%s",&head->s2);
	printf("ENTER %s MARKS\n",head->s2);
	scanf("%f",&head->m2);
	printf("ENTER THIRD SUBJECT NAME\n");
	scanf("%s",&head->s3);
	printf("ENTER %s MARKS\n",head->s3);
	scanf("%f",&head->m3);
	printf("ENTER FOURTH SUBJECT NAME\n");
	scanf("%s",&head->s4);
	printf("ENTER %s MARKS\n",head->s4);
	scanf("%f",&head->m4);
	printf("ENTER FIFTH SUBJECT NAME\n");
	scanf("%s",&head->s5);
	printf("ENTER %s MARKS\n",head->s5);
	scanf("%f",&head->m5);
	c=grade(head->m1);
	head->grade1=c;
	c=grade(head->m2);
	head->grade2=c;
	c=grade(head->m3);
	head->grade3=c;
	c=grade(head->m4);
	head->grade4=c;
	c=grade(head->m5);
	head->grade5=c;
    head->total=(head->m1+head->m2+head->m3+head->m4+head->m5);
	head->percentage=(head->total)/5;
	total_rank[++r]=(head->total);
	len=len+1;
	head->rank=0;
	head->link=NULL;
	printf("1:to add students detail ,2: to display result ,3 : to clear screen,4 : to search student detail\n");
	int choice=0;
	while(choice!=10){
		printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				student_detail(head,total_rank);
				printf("1:to add students detail ,2: to display result ,3 : to clear screen,4 : to search student detail\n");
				break;
			case 2:
				rank(head,total_rank);
				display(head);
				break;
			case 3:
				system("cls");
				break;
			case 4:
				search(head);
				break;
		}
	}
	return 0;
}