#include<stdio.h>
#include<stdlib.h>

struct poly
{
    int coeff;
    int expo;
    struct poly *link;
}*head1,*head2,*prev_node1,*prev_node2;

void input()
{  
    int n,m,i,c=0,e=0;
    reinput1:
    printf("Enter number of terms for 1st Equation: ");
    scanf("%d",&n);

    //Equation 1... 
    printf("\n");
    printf("Enter 1st coefficient: ");
    scanf("%d",&c);

    printf("Enter Exponent of coeficient %d x: ",c);
    scanf("%d",&e);

    int exp=e;
    
    head1->coeff=c;
    head1->expo=e;
    head1->link=NULL;
    prev_node1=head1;

    for(i=2;i<=n;i++)
    {
        struct poly *new_node1;
        new_node1=(struct poly*)malloc(sizeof(struct poly));

        printf("\n\n");
        printf("Enter coefficient %d: ",i);
        scanf("%d",&c);

        printf("Enter Exponent of coeficient %d x: ",c);
        scanf("%d",&e);

        if(e>exp)
        {
            printf("\n\t****ERROR: Enter in descending exponent!******\n\v");
            goto reinput1;
        }
        else
        {
            exp=e;
        }

        new_node1->coeff=c;
        new_node1->expo=e;
        new_node1->link=NULL;
        prev_node1->link=new_node1;
        prev_node1=new_node1;
        
    }

    //Equation 2...
    reinput2:
    
    printf("\v......\v\n");
    
    printf("Enter number of terms for 2nd Equation: ");
    scanf("%d",&m);

    printf("\n");

    printf("Enter 1st coefficient: ");
    scanf("%d",&c);

    printf("Enter Exponent of coeficient %d x: ",c);
    scanf("%d",&e);
    exp=e;
    
    head2->coeff=c;
    head2->expo=e;
    head2->link=NULL;
    prev_node2=head2;

    for(i=2;i<=m;i++)
    {
        struct poly *new_node2;
        new_node2=(struct poly*)malloc(sizeof(struct poly));
        printf("\n\n");
        printf("Enter coefficient %d: ",i);
        scanf("%d",&c);

        printf("Enter Exponent of coeficient %d x: ",c);
        scanf("%d",&e);

        if(e>exp)
        {
            printf("\n\t****ERROR: Enter in descending exponent!******\n\v");
            goto reinput2;
        }
        else
        {
            exp=e;
        }

        new_node2->coeff=c;
        new_node2->expo=e;
        new_node2->link=NULL;
        prev_node2->link=new_node2;
        prev_node2=new_node2;
    }
}

void print()
{
    struct poly *ptr1=head1;

    struct poly *ptr2=head2;

    printf("\vEquation 1:\n");
    
    while(ptr1!=NULL)
    {
        printf("%d x^%d\t",ptr1->coeff,ptr1->expo);
        if(ptr1->link!=NULL)
        {
            printf("+\t");
        }
        ptr1=ptr1->link;
        // printf("STUCK\n");
    }

    printf("\vEquation 2:\n");
    while(ptr2!=NULL)
    {
        printf("%d x^%d\t",ptr2->coeff,ptr2->expo);
        if(ptr2->link!=NULL)
        {
            printf("+\t");
        }
        ptr2=ptr2->link;
    }
}

void add()
{
    struct poly *temp1,*temp2,*sum;
    sum=(struct poly *)malloc(sizeof(struct poly));
    temp1=head1;
    temp2=head2;
    
    while(temp1!=NULL)
    {
        if(temp1->expo==temp2->expo)
        {
            sum->coeff= (temp1->coeff)+(temp2->coeff);
            sum->expo=temp1->expo;
            
        }            
 
    }
}


int main()
{
    head1=(struct poly*)malloc(sizeof(struct poly));
    head2=(struct poly*)malloc(sizeof(struct poly));
    input();
    // sort();
    print();
}