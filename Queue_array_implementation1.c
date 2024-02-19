// Code using linear array from Reema Thareja
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
int A[MAX];
int front = -1, rear = -1;
void Enqueue(int x);
int Dequeue();
int Peek();
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
        printf("4. Display the queue\n");
        printf("5. Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter the number to be inserted\n");
            scanf("%d", &val);
            Enqueue(val);
            break;
        case 2:
            val = Dequeue();
            printf("The element deleted is %d\n", val);
            break;
        case 3:
            val = Peek();
            printf("The element at front is %d\n", val);
            break;
        case 4:
            Display();
            break;
        }
    } while (option != 5);

    return 0;
}

void Enqueue(int x)
{
    if (rear == MAX - 1)
    {
        printf("OVERFLOW\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }
    A[rear] = x;
}
int Dequeue()
{
    int num;
    if (front == -1 || front > rear)
    {
        printf("UNDERFLOW\n");
        return -1;
    }
    else
    {
        num = A[front];
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
        return num;
    }
}
int Peek()
{
    if (front == -1 || front > rear)
    {
        return -1;
    }
    else
    {
        return A[front];
    }
}
void Display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("\t%d", A[i]);
        }
    }
}