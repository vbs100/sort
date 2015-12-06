//from p.113 of <<Algorithms Design Techniques and Analysis>>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int a[N+1];

int split(int A[], int low, int high)
{
	int i=low;//the end ptr of <= x
	int j;    //the end ptr of >= x
	int x=A[i],t;
	for(j=i+1;j<=high;j++)
	{
		if(A[j]<=x)
		{
			i++;//enlarge end of <= x, A[i] must > x
			if(i!=j)
			{
				t=A[i];
				A[i]=A[j];
				A[j]=t;
			}
		}
	}
	t=A[low];
	A[low]=A[i];
	A[i]=t;
	return i;
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
