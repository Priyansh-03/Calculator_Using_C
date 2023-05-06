#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void insertionSort(int *arr, int size){
int key , i,j ;
for (i = 1; i <= size - 1; i++){
key = arr[i];
j = i - 1;
while(j>=0&&arr[j]>key){
arr[j+1]=arr[j];
j--;
}
arr[j+1]= key;
}
}
int binarySearch(int arr[], int beg, int end, int val)
{
int mid,i;
if(end >= beg)
{ mid = (beg + end)/2;
if(arr[mid] == val)
{
return mid+1;
}
else if(arr[mid] < val)
{
return binarySearch(arr, mid+1, end, val);
}
else
{
return binarySearch(arr, beg, mid-1, val);
}
}
return -1;
}
int linearSearch(int arr[], int n, int val)
{
int i;
for ( i = 0; i < n; i++)
{
if (arr[i] == val)
return i+1;
}
return -1;
}
void printarr(int *arr,int n){
int i;
printf("After sorting the array\n");
for ( i=0;i<n;i++){
    printf("%d ",arr[i]);
}
}
//Menu Driven
int main()
{
int n,i;
printf("Enter the size of array\n");
scanf("%d",&n);
int arr[n];
printf("Enter the array element\n");
for( i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
printf("Enter the element you want to search\n");
int val;
scanf("%d",&val);
printf("Enter 1 for Linear Search\n");
printf("Enter 2 for Binary Search\n");
int s;
scanf("%d",&s);
switch (s)
{
case 1:
printf("Running Linear Search...\n");
int res = linearSearch(arr,n,val);
if(res==-1)
printf("\nElement is not present in the array");
else
printf("\nElement is present at %d position of array", res);
break;
case 2:
printf("Running Binary Search...\n");
insertionSort(arr, n);
printarr(arr,n);
int r = binarySearch(arr,0,n-1,val);
if(r==-1)
printf("\nElement is not present in the array");
else
printf("\nElement is present at %d position of array", r);
break;
default:
printf("Enter valid Choice\n");
break;
}
}