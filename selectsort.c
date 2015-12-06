//from p.8 of <<Algorithms Design Techniques and Analysis>>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int a[N+1];


void select_sort(int A[], int low, int high)
{
	int i,j,k,t;
	for(i=low;i<=high-1;i++)
	{
		k=i;
		for(j=i+1;j<=high;j++)
			if(A[j]<A[k])
				k=j;
		if(k!=i)
		{
			t=A[i];
			A[i]=A[k];
			A[k]=t;
		}
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

	select_sort(a,0,N);

	for(i=0;i<=N;i++)
		printf("%d ", a[i]);
	printf("\n");
}
