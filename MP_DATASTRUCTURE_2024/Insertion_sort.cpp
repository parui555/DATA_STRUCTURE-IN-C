#include<stdio.h>
#include<conio.h>
int main()
{
	void insertion_sort(int[],int);
	int a[4],i,N;
	N=4;
	printf("\n Enter the %d element to sort:\n",N);
	for(i=0;i<N;i++)
	scanf("%d",&a[i]);
	insertion_sort(a,N);
	
	printf("\n\n The sorted element are:\n");
	for(i=0;i<N;i++)
	printf("%d ",a[i]);
	
	getch();
}

void insertion_sort(int a[],int N)
{
	int i=0,j=0,temp;
	
	for(i=0;i<N;i++)
	{
		printf("\nAfter pass- %d",i+1);
		temp=a[i];
		printf("\n Temp=%d",temp);
		
		for(j=i-1;j>=0;j--)
		{
			if(a[j]>temp)
			{
				printf("\n Compre between %d and %d",a[j],temp);
				a[j+1]=a[j];
			}
			else
			break;
		}
		a[j+1]=temp;
		
		printf("\n\n The partially sorted elements are:\n");
		for(int k=0;k<N;k++)
		printf("%d ",a[k]);
		getch();
	}
}

