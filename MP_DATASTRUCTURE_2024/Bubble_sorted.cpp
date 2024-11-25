#include<stdio.h>
#include<conio.h>

int DATA[100];
int N;
void bubble_sort();
void create_array();
void display_array();

void bubble_sort()
{
	int temp,i,j;
	for(i=0;i<N;i++)
	{
		printf("\n After pass-%d",i+1);
		    for(j=0;j<N-i-1;j++)
		    {
		    	printf("\n COmparing between %d and %d",DATA[j],DATA[j+1]);
		    	if(DATA[j]>DATA[j+1])
		    	{
		    		temp=DATA[j];
		    		DATA[j]=DATA[j+1];
		    		DATA[j+1]=temp;
				}
			}
			display_array();
			getch();
		//	return 0;
	}
}

void create_array()
{
	int i;
	printf("\n Enter the limit of DATA[N]: ");
	scanf("%d",&N);
	printf("\n Enter unsorted element are DATA [%d]: \n",N);
	    for(i=0;i<N;i++)
	        scanf("%d\n",&DATA[i]);
}

void display_array()
{
	int k;
	printf("\n The sorted element are DATA[%d]=",N);
	    for(k=0;k<N;k++)
	        printf(" %d",DATA[k]);
}

int main()
{
	create_array();
	bubble_sort();
	display_array();
	getch();
}