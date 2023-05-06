#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
}*head;

void print()
{
    int count=0;
    struct node *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("node %d: %d\n",++count,ptr->data);
        ptr=ptr->link;
    }
}

int main()
{
    // struct node *head;
    struct node *second;
    struct node *third;

    //Allocate memory for linked list in heap memory
    head=(struct node*) malloc (sizeof(struct node));
    second=(struct node*) malloc (sizeof(struct node));
    third=(struct node*) malloc (sizeof(struct node));

    // Link node 1 and 2
    head->data=10;
    head->link=second;

    // Link node 2 and 3
    second->data=20;
    second->link=third;

    // Link node 3 and 1
    third->data=30;
    third->link=NULL;

    print();
}
