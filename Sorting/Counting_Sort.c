#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

int maximum(int arr[],int n)
{
    int i;
    int max=INT_MIN;
    
    for(i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    return max;
}
void countSort(int *arr,int n)
{
    int i,j;
    int max=maximum(arr,n);
    int *countArray=(int *)malloc((max+1)*sizeof(int));

    for(i=0;i<n;i++)
    {
        countArray[i]=0;
    }

    for(i=0;i<n;i++)
    {
        countArray[arr[i]]=countArray[arr[i]]+1;
    }
    i=0;
    j=0;

    while(i<=max)
    {
        if(countArray[i]>0)
        {
        arr[j]=i;
        countArray[i]=countArray[i]-1;
        j++;
        }
        else{
            i++;
        }
    }
    
}
int main()
{
    int i,n;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int *arr=(int *)malloc((n)*sizeof(int));
    printf("Enter array:\n");

    for(i=0;i<n;i++)
    {
        printf("%d: ",i+1);
        scanf("%d",&arr[i]);
    }
    countSort(arr,n);
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}