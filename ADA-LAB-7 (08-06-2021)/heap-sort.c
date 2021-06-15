#include<stdio.h>
#include<time.h>
void main()
{
    int n,i;
    clock_t start,end;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    printf("\n");
    int a[n];
    for(i=0;i<n;i++)
    {
        a[i]=n-i;
    }
    start=clock();
    heap_sort(a,n);
    end=clock();
    printf("Time taken to sort %d numbers is %f secs",n,(((double)(end-start))/(CLOCKS_PER_SEC)));
}

heap_sort(int a[], int n)
{
    int i, temp;
    heap_cons(a,n);
    for(i=n-1;i>0;i--)
    {
        temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heap_adj(a,i);
    }
}

int heap_cons(int a[], int n)
{
    int i,j,k,item;
    for(k=1;k<n;k++)
    {
        item=a[k];
        i=k;
        j=(i-1)/2;
        while(i>0 && item>a[j])
        {
            a[i]=a[j];
            i=j;
            j=(i-1)/2;
        }
        a[i]=item;
    }
}

int heap_adj(int a[], int n)
{
    int i,j,item;
    j=0;
    item=a[j];
    i=2*j+1;
    while(i<=n-1)
    {
        if(i+1<=n-1)
        {
            if(a[i]<a[i+1])
            i++;
        }
        if(item<a[i])
        {
            a[j]=a[i];
            j=i;
            i=2*j+1;
        }
        else
            break;
    }
    a[j]=item;
}
