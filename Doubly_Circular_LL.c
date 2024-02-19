#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *head;
void InsertAtHead(int x)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    new->data = x;
    new->prev = NULL;
    if (head == NULL)
    {
        head = new;
        new->next = head;
        return;
    }
    head->prev = new;
    new->next = head;
    head->next = new;
    head = new;
}
void InsertAtTail(int x)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    new->data = x;
    new->prev = NULL;
    if (head == NULL)
    {
        head = new;
        new->next = head;
        return;
    }
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = new;
    new->prev = temp;
    new->next = head;
}
void Search(int x)
{
    struct Node *temp = head;
    int i = 1;
    while (temp->next != head)
    {
        if (temp->data == x)
        {
            break;
        }
        temp = temp->next;
        i++;
    }
    if (temp->next == head && temp->data != x)
    {
        i = 0;
        printf("The element you entered is not present in the list\n");
        return;
    }
    printf("The element is located at position number %d\n", i);
}
void Print()
{
    struct Node *temp = head;
    while (temp->next != head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}
int main()
{
    int i, x, n, p;
    head = NULL;
    printf("How many elements you want to insert? ");
    scanf("%d", &n);
    printf("Enter 1 for inserting elements at head and 2 for inserting elements at tail ");
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
    printf("Enter the element you want to search for ");
    scanf("%d", &x);
    Search(x);
    return 0;
}