#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head;
struct Node *GetNewNode(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void InsertAtHead(int x)
{
    struct Node *newNode = GetNewNode(x);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}
void InsertAtTail(int x)
{
    struct Node *newNode = GetNewNode(x);
    struct Node *temp = head;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}
void Print()
{
    struct Node *temp = head;
    if (head == NULL)
    {
        printf(" ");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}
void ReversePrint()
{
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
}
int main()
{
    int n, x, p;
    printf("How many elements you want?\n");
    scanf("%d", &n);
    printf("Enter 1 to insert elements at head and 2 to insert at tail\n");
    scanf("%d", &p);
    if (p == 1)
    {
        for (int i = 0; i < n; i++)
        {
            printf("Enter the number: ");
            scanf("%d", &x);
            InsertAtHead(x);
        }
    }
    else if (p == 2)
    {
        for (int i = 0; i < n; i++)
        {
            printf("Enter the number: ");
            scanf("%d", &x);
            InsertAtTail(x);
        }
    }
    Print();
    printf("\n");
    ReversePrint();
    return 0;
}