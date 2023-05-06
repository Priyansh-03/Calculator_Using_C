#include<stdio.h>
int binarysearch(int *arr,int n,int key)
{
    int mid=0,r=n-1,l=0;
    
    while(l<=r)
   {    
        mid=(r+l)/2; 
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]<key)
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
   } 
    return -1;
}
int main()
{
    int n,i,result,key;
    printf("Enter no. of elements:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements of array:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }   
    printf("Enter key: ");
    scanf("%d",&key);
    result=binarysearch(arr,n,key);
    printf("Key found at %d",result);
}