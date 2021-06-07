#include<stdio.h>
int binarySearch(int arr[], int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;
        if (arr[mid] == x)  return mid;
        if (arr[mid] > x) return binarySearch(arr, l, mid-1, x);
        return binarySearch(arr, mid+1, r, x);
   }
   return -1;
}
int recSearch(int arr[], int l,int r, int x)
{
    if (r < l)
        return -1;
    if (arr[l] == x)
        return l;
    if (arr[r] == x)
        return r;
    return recSearch(arr, l + 1,r - 1, x);
}
int main()
{
    int a[100],n,x,c,s,t;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
        for(;;)
        {

    printf("Enter the element to be searched\n");
    scanf("%d",&x);
    printf("1.Recursive linear search\n2.Recursive binary search\n3.Exit\n");
    scanf("%d",&c);
    switch(c)
    {
        case 1:s=recSearch(a,0,n-1,x);
            if(s==-1)
                 printf("Element not found\n");
                 else
                    printf("Element found at position %d\n",s+1);
                    break;
        case 2:t=binarySearch(a,0,n-1,x);
            if(t==-1)
                 printf("Element not found\n");
                 else
                    printf("Element found at position %d\n",t+1);
                    break;
        default:exit(0);
    }
        }
    return 0;
}
