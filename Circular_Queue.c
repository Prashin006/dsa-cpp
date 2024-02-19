// Here we use circular array instead of linear array to avoid wastage of space
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 10
int A[MAX];
int front = -1, rear = -1;
void Enqueue(int);
int Dequeue();
int Peek();
bool IsEmpty();
bool IsFull();
void Display();
int main()
{
    int val, option;
    do
    {
        printf("\n*****MAIN MENU*****\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Peek\n");
        printf("4. To check whether queue IsEmpty\n");
        printf("5. To check whether queue IsFull\n");
        printf("6. Display the queue\n");
        printf("7. Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter a number you want to insert\n");
            scanf("%d", &val);
            Enqueue(val);
            break;
        case 2:
            val = Dequeue();
            if (val == -1)
            {
                printf("Queue is empty\n");
            }
            else
                printf("The last element deleted is %d\n", val);
            break;
        case 3:
            val = Peek();
            printf("The element in the front is %d\n", val);
            break;
        case 4:
            val = IsEmpty();
            printf("%d\n", val);
            break;
        case 5:
            val = IsFull();
            printf("%d\n", val);
            break;
        case 6:
            Display();
            break;
        }
    } while (option != 7);
    return 0;
}

void Enqueue(int x)
{
    if ((rear + 1) % MAX == front)
    {
        printf("OVERFLOW\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        A[rear] = x;
    }
    else
    {
        rear = (rear + 1) % MAX;
        A[rear] = x;
    }
}
int Dequeue()
{
    int num;
    if (IsEmpty())
    {
        return -1;
    }
    else
    {
        num = A[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
        return num;
    }
}
int Peek()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        return A[front];
    }
}
bool IsEmpty()
{
    if (front == -1 && rear == -1)
    {
        return true;
    }
    else
        return false;
}
bool IsFull()
{
    if ((rear + 1) % MAX == front)
    {
        return true;
    }
    else
        return false;
}
void Display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("The queue is empty\n");
    }
    else
    {
        int num = front;
        if (front > rear)
        {
            for (int i = num; i < MAX - 1; i++)
            {
                printf("\t%d", A[i]);
            }
            for (int i = rear; i < front - 1; i++)
            {
                printf("\t%d", A[i]);
            }
        }
        else if (front == rear)
        {
            printf("%d", A[rear]);
        }
        else
        {
            for (int i = front; i <= rear; i++)
            {
                printf("\t%d", A[i]);
            }
        }
    }
}