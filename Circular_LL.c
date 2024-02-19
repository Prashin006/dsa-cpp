#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head;
void InsertAtTail(int x)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    new->data = x;
    if (head == NULL)
    {
        head = new;
        new->next = head;
        return;
    }
    do
    {
        temp = temp->next;
    } while (temp->next != head);
    temp->next = new;
    new->next = head;
}
void InsertAtHead(int x)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    new->data = x;
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
    new->next = head;
    head = new;
    temp->next = head;
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
    struct Node *temp;
    temp = head;
    while (temp->next != head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
    printf("\n");
}
int main()
{
    int n, x, choice, p;
    head = NULL;
    printf("How many elements you want to insert?\n");
    scanf("%d", &n);
    printf("Enter 1 to insert elements at head and 2 to insert elements at tail\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        for (int i = 0; i < n; i++)
        {
            printf("Enter the number: ");
            scanf("%d", &x);
            InsertAtHead(x);
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            printf("Enter the number: ");
            scanf("%d", &x);
            InsertAtTail(x);
        }
    }
    printf("The linked list is\n");
    Print();
    printf("Enter the element you want to search: ");
    scanf("%d", &p);
    Search(p);
    return 0;
}