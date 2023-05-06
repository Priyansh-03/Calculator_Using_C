#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
}*front=NULL,*rear=NULL;

void display()
{
    struct node *temp;
    temp=front;
    int count=1;
    if(front==NULL)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        // printf("\nDisplaying Queue: ");
        while(temp!=NULL)
        {
            printf("\n%d=> %d",count++,temp->data);
            temp=temp->link;
        }
    }
    printf("\n\tPROGRAMMED BY:- Priyansh");
}

void push()
{
    int value;
    printf("Enter number to Push: ");
    scanf("%d",&value);

    struct node *new_node;
    new_node=(struct node *) malloc (sizeof(struct node));

    if(front==NULL)
    {
        new_node->data=value;
        new_node->link=NULL;

        front=new_node;
        rear=new_node;
    }
    else
    {
        new_node->data=value;
        new_node->link=NULL;
        rear->link=new_node;
        rear=rear->link;
    }
}

void pop()
{
    if((front==NULL)||(front>rear))
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nBEFORE: ");
        display();
        front=front->link;
        printf("\nAFTER: ");
        display();
    }
}

int main()
{
    int choice;
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
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
            break;
        default:
            printf("Please enter valid choice..");
            break;
        }
    }
}
