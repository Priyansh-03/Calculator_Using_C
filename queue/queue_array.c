/*
======================= START OF LICENSE NOTICE =======================
  Copyright (C) 2022 priyansh. All Rights Reserved

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
#include <stdio.h>
#include <stdlib.h>
int *queue;
int front = -1;
int rear = -1;


void push(int size)
{
    int n;
    if (front == -1)
    {
        front++;
        rear++;
        printf("Enter the number: ");
        scanf("%d", &n);
        queue[rear]=n;
    }
    else
    {
        if(rear==size-1)
        {
            printf("Queue is full");
            return;
        }
        printf("Enter the number: ");
        scanf("%d", &n);
        rear++;
        queue[rear] = n;
    }
}
void pop()
{
    if ((front == -1)||(front>rear))
    {
        printf("queue is empty");
    }
    else
    {
    	printf("POPPED OUT:\n");
        printf("%d ", queue[front]);
        front++;
    }
}
void display()
{
    int i,count=1;
    if ((front == -1)||(front>rear))
    {
        printf("\nqueue is empty");
    }
    else
    {
        printf("\nDISPLAYING queue:\n");
        for (i = front; i <=rear; i++)
        {
            printf("%d => %d\n",count++, queue[i]);
        }
    }
}
int main()
{
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    queue = (int *)malloc(sizeof(int) * size);

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