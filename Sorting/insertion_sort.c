#include<stdio.h>
#include<stdlib.h>
int *insertion_sort(int *arr,int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp=arr[i];
        j=i-1;
		while((j>=0) && (arr[j]>temp))
        {
			arr[j+1]=arr[j];
            j--;
		}
		arr[j+1]=temp;
	}
	return arr;	
}

int main()
{
	int n,temp=0,i,*result;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	int* arr=(int*) malloc (n *sizeof(int));

	printf("Enter elements of array: ");
	for (i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}

	result=insertion_sort(arr,n);

	printf("\nSorted array is: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",result[i]);
    }
    return 0;
}