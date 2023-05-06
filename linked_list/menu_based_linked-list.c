#include<stdio.h>
#include<stdlib.h>

 
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
        }