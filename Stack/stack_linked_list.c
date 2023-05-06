/*
======================= START OF LICENSE NOTICE =======================
  Copyright (C) 2022 Priyansh. All Rights Reserved

  NO WARRANTY. THE PRODUCT IS PROVIDED BY DEVELOPER "AS IS" AND ANY
  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL DEVELOPER BE LIABLE FOR
  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
  GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
  IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THE PRODUCT, EVEN
  IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
======================== END OF LICENSE NOTICE ========================
  Primary Author: priyansh

*/
#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int data;
    struct stack * link;
}*top=NULL;

void push()
{
    int num;
    printf("Enter number to Push: ");
    scanf("%d",&num);

    if(top==NULL)
    {
        top=(struct stack *)malloc(sizeof(struct stack));

        top->data=num;
        top->link=NULL;
    }

    else
    {
        struct stack *temp;
        temp=(struct stack *)malloc(sizeof(struct stack));

        temp->data=num;
        temp->link=top;
        top=temp;
    }
}

void pop()
{
    if(top==NULL)
    {
        printf("\n**********ERROR: STACK is empty.**********\n");
    }
    
    else
    {
        top=top->link;
    }
}

void display()
{
    struct stack *temp;
    temp=top;

    if(top==NULL)
    {
        printf("\n**********ERROR: STACK is empty.**********");
    }
    else
    {
        printf("\nDISPLAYING STACK...\n\n");
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->link;
        }
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
            exit(0);
            break;
        default:
            printf("Please enter valid choice..");
            break;
        }
    }
}