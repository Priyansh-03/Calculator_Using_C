#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
}*head;

void print(struct node *head)
{
    struct node *ptr= head;
    int count=0;
    while(ptr!=NULL)
    {
        printf("node %d: %d\n",++count,ptr->data);
        ptr=ptr->link;
    }
}

void add_begin(struct node **head,int value)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));

    temp->data=value;
    temp->link=*head;

    *head=temp;
}

void add_last(struct node **head, int value)
{
    struct node *temp;
    temp=*head;
    while(1)
    {
        if(temp->link==NULL)
        {
            struct node *last_node;
            last_node=(struct node *)malloc(sizeof(struct node));
            last_node->data=value;
            last_node->link=NULL;
            temp->link=last_node;
            break;
        }
        else
        {
            temp=temp->link;
        }
    }
}

void add_at(struct node *head,int value)
{
    int pos,count;
    printf("Enter position to enter new node: ");
    scanf("%d",&pos);
    struct node *temp;
    temp=head;

    struct node * new_node;
    new_node= (struct node *)malloc(sizeof(struct node));
    new_node->data=value;
    new_node->link=NULL;

    count=0;
    while(temp!=NULL)
    {
        if(pos==count)
        {
            new_node->link=temp->link;
            temp->link=new_node;
            break;
        }
        temp=temp->link;
        count++;
    }
    if((temp->link==NULL) && (pos==count))
    {
        new_node->data=value;
        new_node->link=NULL;
    }
}

void delete_node(struct node **head)
{
    struct node *temp;
    struct node *prev;
    temp= *head;
    prev= *head;
    int find;
    printf("Enter data to be deleted: ");
    scanf("%d",&find);

    while(temp->link!=NULL)
    {
        if((find==(*head)->data)&&(prev==temp))
        {
            *(head)=(*head)->link;
            free(temp);
            break;
        }
        else
        {
            if(find==temp->data)
            {
                prev->link=temp->link;
                free(temp);
                break;
            }
            else
            {
                prev=temp;
                temp=temp->link;
            }
        }
    }
}


int main()
{
    int choice;
    int value;
    int choice2;
    struct node *head;
    struct node *second;
    struct node *third;

    //Allocate memory for linked list in heap memory
    head=(struct node*) malloc (sizeof(struct node));
    second=(struct node*) malloc (sizeof(struct node));
    third=(struct node*) malloc (sizeof(struct node));
    
    int head_data;
    printf("Enter data for Node 1: ");
    scanf("%d",&head_data);
    // Link node 1 and 2
    head->data=head_data;
    head->link=NULL;

    // Link node 2 and 3
    // second->data=20;
    // second->link=third;

    // // Link node 3 and 1
    // third->data=30;
    // third->link=NULL;

    linked_list_menu:
    printf("\n********************\n\n");
    printf("0. Exit");
    printf("\n1. Add node at start");
    printf("\n2. Add node at last");
    printf("\n3. Add node at any position");
    printf("\n4. Delete node at any position");

    printf("\n\nEnter Choice: ");
    scanf("%d",&choice);

    if(choice==0)
    {
        return 0;
    }

    if(choice>4)
    {
        printf("\n\n**********WRONG CHOICE*******\n\n");
        goto linked_list_menu;
    }

    switch(choice)
    {
        case 1:
        {
            printf("Enter new data: ");
            scanf("%d",&value);

            // call functions
            add_begin(&head,value);
            print(head);
            goto linked_list_menu;
        }

        case 2:
        {
            printf("Enter new data: ");
            scanf("%d",&value);

            add_last(&head,value);
            print(head);
            goto linked_list_menu;
        }

        case 3:
        {
            printf("Enter new data: ");
            scanf("%d",&value);

            add_at(head,value);
            print(head);
            goto linked_list_menu;
        }

        case 4:
        {
            delete_node(&head);
            print(head);
            goto linked_list_menu;

        }
    }


    // input new data for new node
    
}
