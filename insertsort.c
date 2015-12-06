//from p.8 of <<Algorithms Design Techniques and Analysis>>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int a[N+1];


void insert_sort(int A[], int low, int high)
{
	int i,j,x;

	for(i=low+1;i<=high;i++)
	{
		x=A[i];
		j=i-1;
		while(j>=low&&A[j]>x)
		{
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=x;
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

	insert_sort(a,0,N);

	for(i=0;i<=N;i++)
		printf("%d ", a[i]);
	printf("\n");
}
