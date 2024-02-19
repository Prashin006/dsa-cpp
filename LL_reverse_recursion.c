// Program to reverse a linked list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head;
void Insert(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    struct Node *temp1 = head;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        while (temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
}
void Print()
{
    struct Node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
void Reverse(struct Node *p)
{
    if (p->next == NULL)
    {
        head = p;
        return;
    }
    Reverse(p->next);
    struct Node *q = p->next;
    q->next = p;
    p->next = NULL;
}
int main()
{
    int n, x, p;
    head = NULL;
    printf("How many elements you want?\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the number: ");
        scanf("%d", &x);
        Insert(x);
    }
    printf("The reversed linked list is\n");
    Reverse(head);
    Print();
    return 0;
}