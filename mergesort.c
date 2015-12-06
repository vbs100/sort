#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 2
int a[N+1];
int b[N+1];

void merge(int A[], int B[], int p, int q, int r)
{
	int s,t,k;
	s=p;
	t=q+1;
	k=p;
	while(s<=q&&t<=r)
	{
		if(A[s]<=A[t])
			B[k++]=A[s++];
		else
			B[k++]=A[t++];
	}
	while(s<=q)
		B[k++]=A[s++];
	while(t<=r)
		B[k++]=A[t++];

	for(k=p;k<=r;k++)
		A[k]=B[k];
}

void merge_sort(int A[], int B[], int low, int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		merge_sort(A,B,low,mid);
		merge_sort(A,B,mid+1,high);
		merge(A,B,low,mid,high);
	}
}

int main()
{
	srand(time(NULL));
	int i;
	for(i=0;i<=N;i++)
		a[i]=rand()%100;

	for(i=0;i<=N;i++)
		printf("%d ", a[i]);
	printf("\n");

	merge_sort(a,b,0,N);

	for(i=0;i<=N;i++)
		printf("%d ", a[i]);
	printf("\n");
}
