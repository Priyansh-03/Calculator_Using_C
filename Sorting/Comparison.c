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

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
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


void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}

int main()
{
    int choice;
    sorting_menu:
    printf ("\n\t\t\n***********\n");
    printf("\nEnter 0 to Exit Sorting\n");
    printf("Enter 1 for Merge sort\n");
    printf("Enter 2 for Quick sort\n");

    printf("\nEnter choice: ");
    scanf("%d",&choice);

    if(choice>2)
    {
        printf ("\n\t\tINVALID CHOICE\n***********\n");
	    goto sorting_menu;
    }

    switch(choice)
    {
        case 1:
        {
            int n,temp=0,i;
            printf("Enter number of elements: ");
            scanf("%d",&n);
            int arr[n],arr_size=n;
            printf("Enter elements of array: ");
            for (i=0;i<n;i++)
            {
                scanf("%d",&arr[i]);
            }
 
            printf("Given array is \n");
            printArray(arr, arr_size);
 
            mergeSort(arr, 0, arr_size - 1);
 
            printf("\nSorted array is \n");
            printArray(arr, arr_size);

            printf("\n\nName : Priyansh \nRoll No.:2101641530123 \nBranch: CS-AIML-2\n");
            goto sorting_menu;
        }

        case 2:
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
                printf("%d ",result[i]);
            }
            printf("\n\nName :Priyansh \nRoll No.:2101641530123 \nBranch: CS-AIML-2\n");
            goto sorting_menu;
        }
    }
}