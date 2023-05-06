#include<stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int getMax(int a[], int n) 
{  
   int max = a[0],i;  
   for(i = 1; i<n; i++)
    {  
      if(a[i] > max)  
         max = a[i];  
   }  
   return max; //maximum element from the array  
}

void printArr(int a[], int n) /* function to print the array */  
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
}  


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

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int choice;
    sorting_menu:
    printf ("\n\t\t\n***********\n");
    printf("\nEnter 0 to Exit Sorting\n");
    printf("Enter 1 for Insertion sort\n");
    printf("Enter 2 for Bubble sort\n");
    printf("Enter 3 for Selection sort\n");
    printf("Enter 4 for Counting sort\n");

    printf("\nEnter choice: ");
    scanf("%d",&choice);

    if(choice>4)
    {
        printf ("\n\t\tINVALID CHOICE\n***********\n");
	    goto sorting_menu;
    }

    switch(choice)
    {
        case 1:
        {
            int n,temp=0,i,*result;
            printf("Enter number of elements: ");
            scanf("%d",&n);
            // int* arr=(int*) malloc (n *sizeof(int));
            int arr[n];
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
            printf("\n\nName : Priyansh \nRoll No. : 2101641530118 \nBranch : CS-AIML-2\n");
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

            printf("\n\nName : Priyansh \nRoll No. : 2101641530118 \nBranch : CS-AIML-2\n");
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

            printf("\n\nName : Priyansh \nRoll No. : 2101641530118 \nBranch : CS-AIML-2\n");
            goto sorting_menu;
        }

        case 4:
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

            printf("\n\nName : Priyansh \nRoll No. : 2101641530118 \nBranch : CS-AIML-2\n");
            goto sorting_menu;
        }
    }
}