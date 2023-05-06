#include <stdio.h>
#include <stdlib.h>
int *stack;
int top = -1;
int size;

void push(int n)
{
    if (top == size - 1)
    {
        printf("Stack is full");
    }
    else
    {
        top++;
        stack[top] = n;
    }
}
void pop()
{
    if (top == -1)
    {
    	printf("PROCESSING POP:\n");
        printf("Stack is empty");
    }
    else
    {
    	printf("POPPED OUT:\n");
        printf("%d ", stack[top]);
        top--;
    }
}
void display()
{
    int i;
    if (top == -1)
    {
    	printf("DISPLAYING STACK:\n");
        printf("Stack is empty");
    }
    else
    {
        printf("DISPLAYING STACK:\n");
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}
int main()
{
    printf("Enter the size of array: ");
    scanf("%d", &size);
    stack = (int *)malloc(sizeof(int) * size);

    int choice = 0;
    while (choice != 4)
    {
        printf("\n\n********Main Menu********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Push"
               "\n2.Pop"
               "\n3.Display"
               "\n4.Exit\n");
        printf("\nEnter your choice: \n");
        int n;
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number: ");
            scanf("%d", &n);
            push(n);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Please enter valid choice..");
            break;
        }
    }
}