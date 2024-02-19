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
    if (head == NULL)
    {
        temp->next = head;
        head = temp;
        temp->data = data;
        return;
    }
    struct Node *temp1 = head;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp;
    temp->data = data;
    temp->next = NULL;
}
void Reverse()
{
    struct Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
void Print()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    int n, i, x;
    head = NULL;
    printf("Enter how many elements you want in the linked list?\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the no: ");
        scanf("%d", &x);
        Insert(x);
    }
    printf("The linked list is\n");
    Print();
    Reverse();
    printf("The linked list after reversal is\n");
    Print();
    return 0;
}