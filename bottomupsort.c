//p.10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20
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

void bottomup_sort(int A[], int B[], int low, int high)
{
	int i,s,t=1;
	while(t<high)
	{
		s=t; t=2*s; i=low-1;
		while(i+t<=high)
		{
			merge(A,B,i+1,i+s,i+t);
			i+=t;
		}
		if(i+s<high)
			merge(A,B,i+1,i+s,high);
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

	bottomup_sort(a,b,0,N);

	for(i=0;i<=N;i++)
		printf("%d ", a[i]);
	printf("\n");
}
