//from p.274 of <<Data structure>> (C language) of Tsinghua
//a[0] is the pivot

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int a[N+1];

int split(int A[], int low, int high)
{
	int pivot=A[low];
	A[0]=A[low];

	while(low<high)
	{
		while(low<high && A[high]>=pivot)
			high--;
		A[low]=A[high];
		while(low<high && A[low]<=pivot)
			low++;
		A[high]=A[low];
	}
	A[low]=A[0];
	return low;
}

void quick_sort(int A[], int low, int high)
{
	if(low<high)
	{
		int w;
		w=split(A,low,high);
		quick_sort(A,low,w-1);
		quick_sort(A,w+1,high);
	}
}


int main()
{
	int i;

	srand(time(NULL));
	for(i=1;i<=N;i++)
		a[i]=rand()%100;

	for(i=1;i<=N;i++)
		printf("%d ", a[i]);
	printf("\n");

	quick_sort(a,1,N);

	for(i=1;i<=N;i++)
		printf("%d ", a[i]);
	printf("\n");
}
