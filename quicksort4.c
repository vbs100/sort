//from SCL
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int a[N+1];

void quick_sort(int A[], int low, int high)
{
	int i=low,j=high,x=A[(i+j)/2],y;
	do{
		while(a[i]<x)
			i++;
		while(a[j]>x)
			j--;
		if(i<=j)
		{
			y=A[i];
			A[i]=A[j];
			A[j]=y;
			i++;j--;
		}
	}while(i<j);
	if(i<high)
		quick_sort(A,i,high);
	if(j>low)
		quick_sort(A,low,j);
}


int main()
{
	int i;

	srand(time(NULL));
	for(i=0;i<=N;i++)
		a[i]=rand()%100;

	for(i=0;i<=N;i++)
		printf("%d ", a[i]);
	printf("\n");

	quick_sort(a,0,N);

	for(i=0;i<=N;i++)
		printf("%d ", a[i]);
	printf("\n");
}
