#include<stdio.h>
int partition(int *arr,int p,int r)
{
    int i,j,x,temp=0;
    x=arr[r];
    i=p-1;
    for(j=p;j<r;j++)
    {
        if(arr[j]<=x)
        {
            i++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    temp=arr[i+1];
    arr[i+1]=arr[r];
    arr[r]=temp;

    return i+1;

}

int* quick_sort(int *arr,int p,int r)
{
    int q;
    if(p<r)
    {
        q=partition(arr,p,r);
        quick_sort(arr,p,q-1);
        quick_sort(arr,q+1,r);
    }
    return arr;
}

int main()
{
    int n,i,*result;
    printf("Enter no. of elements: ");
    scanf("%d",&n);
    int arr[n];
    int p=0,r=n-1;
    printf("Enter elements of array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }   
    result=quick_sort(arr,p,r);
    for(i=0;i<n;i++)
    {
        // printf("Entered print ");
        printf("%d ",result[i]);
    }
    return 0;
}
