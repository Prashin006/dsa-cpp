#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
struct Node
{
    int data;
    struct Node *next;
};
struct queue
{
    struct Node *front;
    struct Node *rear;
};
struct queue *q;
void create_queue(struct queue *);
struct queue *insert(struct queue *, int);
struct queue *delete_element(struct queue *);
int Peek(struct queue *);
struct queue *display(struct queue *);

int main()
{
    int val, option;
    create_queue(q);
    // clrscr();
    do
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter the no you want to insert\n");
            scanf("%d", &val);
            q = insert(q, val);
            break;
        case 2:
            q = delete_element(q);
            break;
        case 3:
            val = Peek(q);
            break;
        case 4:
            q = display(q);
            break;
        }
    } while (option != 5);

    return 0;
}
void create_queue(struct queue *q)
{
    (*q).front = (*q).rear = NULL;
}
struct queue *insert(struct queue *q, int n)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = n;
    temp->next = NULL;
    if (q->front == NULL)
    {
        q->front = q->rear = temp;
        q->front->next = q->rear->next = NULL;
    }
    else
    {
        q->rear->next = temp;
        q->rear = temp;
        q->rear->next = NULL;
    }
    return q;
}
struct queue *delete_element(struct queue *q)
{
    struct Node *temp = q->front;
    if (q->front == NULL)
    {
        printf("UNDERFLOW\n");
    }
    else
    {
        q->front = q->front->next;
        printf("The element deleted is %d\n", temp->data);
        free(temp);
    }
}
int Peek(struct queue *q)
{
    int num;
    if (q->front == NULL)
    {
        num = -1;
    }
    else
    {
        num = q->front->data;
    }
    return num;
}
struct queue *display(struct queue *q)
{
    struct Node *temp = q->front;
    if (q->front == NULL)
    {
        printf("The queue is empty\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }

    return q;
}