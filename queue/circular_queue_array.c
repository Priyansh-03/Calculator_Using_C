-#include<stdio.h>
#include <stdlib.h>
int *circular_queue;
int front=-1;
int rear=-1;


void push(int size)
{
    int n;
    if(front=-1)
    {
        printf("Enter number: ");
        scanf("%d",&n);

        front++;//front=0
        rear++;//rear=0

        circular_queue[rear]=n;//array[0]=n
    }

    else
    {
        if((rear==front)||(rear==size))
        {
            printf("\n\t*******Queue is full*******");
        }
        else
        {
            printf("\nEnter number: ");
            scanf("%d",&n);
            circular_queue[rear]=n;
            rear=(rear+1)%size;
        }
    }
}

void pop(int size)
{
    if(front==-1)
    {
        printf("\n\t*****Queue is empty*****");
    }
    else if(front>rear)
    {
        printf("\n\t*****Queue is empty*****");
        front=-1;
        rear=-1;
    }
    else
    {
        front=(front+1)%size;
        printf("\nDELETED: %d",circular_queue[front]);
    }
}

void display(int size)
{
    int i,count=1;
    if ((front == -1)||(front>rear))
    {
        printf("\n*****Queue is empty*****");
    }
    else
    {
        printf("\nDISPLAYING queue:\n");
       i=rear;
        while(i!=front)
        {
            printf("%d => %d\n",count++, circular_queue[i]);
            i=(i+1)%size;
        }
        if(i==front)
        {
            printf("%d => %d\n",count++, circular_queue[i]);
        }
    }
}

int main()
{
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    circular_queue = (int *)malloc(sizeof(int) * size);

    int choice = 0;
    while (1)
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
            push(size);
            break;
        case 2:
            pop(size);
            break;
        case 3:
            display(size);
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