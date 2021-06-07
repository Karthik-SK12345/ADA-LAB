#include<stdio.h>
#include<time.h>
#include<stdlib.h>
insertion_sort(int a[],int n)
{
	int y,i,j;
for(i=1;i<n;i++)
{
y=a[i];
j=i-1;
while(j>=0&&a[j]>y)
{
a[j+1]=a[j];
j=j-1;
}
a[j+1]=y;
}
}

int main()
{
int i,n,sort;
clock_t start,end;
while(1)
{
printf("enter the number of the elements\n");
scanf("%d",&n);
int a[n];
for(i=0;i<n;i++)
{
a[i]=n-i;
}
start=clock();
sort=insertion_sort(a,n);
end=clock();
double time_taken=((double)end-start)/CLOCKS_PER_SEC;
printf("time taken for sorting %d elements is %f sec\n",n,time_taken);
printf("\n");
}
}
