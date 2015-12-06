#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int a[N+1];


void bubble_sort(int A[], int low, int high)
{
	int i,j,t;
	for(i=high;i>=low+1;i--)
		for(j=low;j+1<=i;j++)
			if(A[j]>A[j+1])
			{
				t=A[j];
				A[j]=A[j+1];
				A[j+1]=t;
			}
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

	bubble_sort(a,0,N);

	for(i=0;i<=N;i++)
		printf("%d ", a[i]);
	printf("\n");
}
