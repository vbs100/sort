//<<Algorithms Design Techniques and Analysis>>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define N 50

int a[N+1];

void sift_up(int H[],int i)
{
	int done=0,x;
	if(i==1)
		return;
	do 
	{
		if(H[i]>H[i/2])
		{
			x=H[i];
			H[i]=H[i/2];
			H[i/2]=x;
		}
		else
			done=1;
		i/=2;
	}while(i>1&&!done);
}

void sift_down(int H[],int i)
{
	int done=0,x;
	if(2*i>H[0])
		return;
	do
	{
		i*=2;
		if(i+1<=H[0]&&H[i+1]>H[i])
			i++;
		if(H[i/2]<H[i])
		{
			x=H[i/2];
			H[i/2]=H[i];
			H[i]=x;
		}
		else
			done=1;
	}while(2*i<=H[0]&&!done);

}

void insert(int H[], int x)
{
	H[0]++;
	H[H[0]]=x;
	sift_up(H,H[0]);
}

void delete(int H[], int i)
{
	int x,y;
	x=H[i];
	y=H[H[0]];
	H[0]--;
	if(i=H[0]+1)
		return;
	H[i]==y;
	if(y>=x)
		sift_up(H,i);
	else
		sift_down(H,i);
}

int delete_max(int H[])
{
	int x;
	x=H[1];
	delete(H,1);
	return x;
}

int makeup(int H[])
{
	int i;
	for(i=H[0]/2;i>=1;i--)
		sift_down(H,i);
}


void heap_sort(int H[])
{
	int i,x;
	makeup(H);
	for(i=H[0];i>=2;i--)
	{
		x=H[1];
		H[1]=H[i];
		H[i]=x;
		H[0]--;
		sift_down(H,1);
	}
}

void print(int H[], int n)
{
	int i;
	for(i=1;i<=n;i++)
		printf("%d ", H[i]);
	printf("\n");
}

void print_heap_tree(int H[], int n)
{
	int i,j,k=1,done=0;
	char fmt[32];
	memset(fmt,' ', sizeof(fmt));
	for(i=1;i<=ceil(log2(n))+1&&!done;i++)
	{
		for(j=1;j<=pow(2,i-1)&&!done;j++)
		{
			sprintf(fmt,"%%%ds%%d%%%ds",128/(int)pow(2,i),64/(int)pow(2,i));
			printf(fmt, " ",H[k++]," ");
			if(k>n)
				done=1;
		}
		printf("\n\n");
	}
}

void init(int H[], int n)
{
	int i;
	srand(time(NULL));
	for(i=1;i<=n;i++)
		H[i]=rand()%100;
	H[0]=n;
}
int main()
{

	init(a, 23);

	print_heap_tree(a, 23);
	print(a, 23);
	makeup(a);

	print_heap_tree(a, 23);
	print(a, 23);

	heap_sort(a);

	print_heap_tree(a, 23);
	print(a, 23);

}
