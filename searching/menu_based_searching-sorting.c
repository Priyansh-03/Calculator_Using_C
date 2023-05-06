#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

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

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
 
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}
 
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element with the first element
           if(min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
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
 
/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int getMax(int a[], int n) {  
   int max = a[0],i;  
   for(i = 1; i<n; i++)
    {  
      if(a[i] > max)  
         max = a[i];  
   }  
   return max; //maximum element from the array  
}  
  
void countSort(int a[], int n) // function to perform counting sort  
{  
    int i;
   int output[n+1];  
   int max = getMax(a, n);  
   int count[max+1]; //create count array with size [max+1]  
  
  
  for (i = 0; i <= max; ++i)   
  {  
    count[i] = 0; // Initialize count array with all zeros  
  }  
    
  for (i = 0; i < n; i++) // Store the count of each element  
  {  
    count[a[i]]++;  
  }  
  
   for(i = 1; i<=max; i++)   
      count[i] += count[i-1]; //find cumulative frequency  
  
  /* This loop will find the index of each element of the original array in count array, and 
   place the elements in output array*/  
  for (i = n - 1; i >= 0; i--) {  
    output[count[a[i]] - 1] = a[i];  
    count[a[i]]--; // decrease count for same numbers  
}  
  
   for( i = 0; i<n; i++) {  
      a[i] = output[i]; //store the sorted elements into main array  
   }  
}  
  
void printArr(int a[], int n) /* function to print the array */  
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
}  

int search(int arr[], int N, int x)
{
    int i;
    for (i = 0; i < N; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int main()
{
    int choice,choice1,choice2;
    printf("\t\t\t\t\tWELCOME TO DEVIL's CALCULATOR:D\n");
    start:
    printf ("\n\t\t\n***********\n");
    printf("\nEnter 1 for searching\n");
    printf("Enter 2 for sorting\n");

    printf("\nEnter choice: ");
    scanf("%d",&choice);

    if(choice>2)
    {
        printf ("\n\t\tINVALID CHOICE\n***********\n");
	    goto start;
    }
    else
    {
        switch(choice)
        {
            case 1:
            {
                searching_menu:
                printf ("\n\t\t\n***********\n");
                printf("\nEnter 0 to Exit Searching\n");
                printf("Enter 1 for Linear search\n");
                printf("Enter 2 for Binary search\n");

                printf("\nEnter choice: ");
                scanf("%d",&choice1);

                if(choice>2)
                {
                    printf ("\n\t\tINVALID CHOICE\n***********\n");
                    goto searching_menu;
                }

                if(choice1==0)
                {
                    goto start;
                }

                else
                {
                    switch(choice1)
                    {
                        case 1:
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
                            result=search(arr,n,key);
                            if(result==-1)
                            {
                                printf("Key not found");
                            }
                            else
                            {
                                printf("Key found at %d",result);
                            }

                            printf("\n\nName: \nRoll No.: \nBranch: CS-\n");
                            goto searching_menu;
                        }

                        case 2:
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
                            result=search(arr,n,key);
                            if(result == -1)
                            {
                                printf("Key not found");
                            }
                            else
                            {
                                printf("Key found at %d",result);
                            }

                            printf("\n\nName: \nRoll No.: \nBranch: CS-\n");
                            goto searching_menu;
                        }
                    }
                }
            }

            case 2:
            {
                sorting_menu:
                printf ("\n\t\t\n***********\n");
                printf("\nEnter 0 to Exit Sorting\n");
                // printf("Enter 1 for Linear sort\n");
                printf("Enter 1 for Insertion sort\n");
                printf("Enter 2 for Bubble sort\n");
                printf("Enter 3 for Selection sort\n");
                printf("Enter 4 for Merge sort\n");
                printf("Enter 5 for Quick sort\n");
                printf("Enter 6 for Counting sort\n");
                

                printf("\nEnter choice: ");
                scanf("%d",&choice2);

                if(choice2>6)
                {
                    printf ("\n\t\tINVALID CHOICE\n***********\n");
	                goto sorting_menu;
                }
                
                if(choice2==0)
                {
                    goto start;
                }
                else
                {
                    switch(choice2)
                    {
                        // case 1:
                        // {
                        //     printf("\n*******************************\n");
                        //     goto sorting_menu;
                        // }

                        case 1:
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
                            printf("\n\nName: \nRoll No.: \nBranch: CS-\n");
                            goto sorting_menu;
                        }

                        case 2:
                        {
                            int n,temp=0,i;
                            printf("Enter number of elements: ");
                            scanf("%d",&n);
                            int arr[n];
                            printf("Enter elements of array: ");
                            for (i=0;i<n;i++)
                            {
                                scanf("%d",&arr[i]);
                            }
                            
                            bubbleSort(arr, n);
                            printf("Sorted array: \n");
                            printArray(arr, n);

                            printf("\n\nName: \nRoll No.: \nBranch: CS-\n");
                            goto sorting_menu;
                        }

                        case 3:
                        {
                            int n,temp=0,i;
                            printf("Enter number of elements: ");
                            scanf("%d",&n);
                            int arr[n];
                            printf("Enter elements of array: ");
                            for (i=0;i<n;i++)
                            {
                                scanf("%d",&arr[i]);
                            }
                            selectionSort(arr, n);
                            printf("Sorted array: \n");
                            printArray(arr, n);                                

                            printf("\n\nName: \nRoll No.: \nBranch: CS-\n");
                            goto sorting_menu;
                        }

                        case 4:
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

                            printf("\n\nName: \nRoll No.: \nBranch: CS-\n");
                            goto sorting_menu;
                        }

                        case 5:
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
                            printf("\n\nName: \nRoll No.: \nBranch: CS-\n");
                            goto sorting_menu;
                        }

                        case 6:
                        {

                            int n,temp=0,i;
                            printf("Enter number of elements: ");
                            scanf("%d",&n);
                            int arr[n];
                            printf("Enter elements of array: ");
                            for (i=0;i<n;i++)
                            {
                                scanf("%d",&arr[i]);
                            }
                            
                            printf("Before sorting array elements are - \n");  
                            printArr(arr, n);  
                            countSort(arr, n);  
                            printf("\nAfter sorting array elements are - \n");    
                            printArr(arr, n);  

                            printf("\n\nName: \nRoll No.: \nBranch: CS-\n");
                            goto sorting_menu;
                        }
                    }
                }
            }
        }
    }
    return 0;
}