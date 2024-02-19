// In this program we declare head as a local variable instead of global variable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *Insert(struct Node *head, int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
        head = temp;
    else
    {
        struct Node *temp1 = head;
        while (temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
    return head;
}
void Print(struct Node *p)
{
    if (p == NULL)
    {
        return; // exit condition
    }
    printf("%d ", p->data); // First print the value in the node
    Print(p->next);         // recursive call
}
void reversePrint(struct Node *p)
{
    if (p == NULL)
    {
        return; // exit condition
    }
    reversePrint(p->next);  // recursive call
    printf("%d ", p->data); // print the value in the node
}
int main()
{
    int i, n, x;
    struct Node *head = NULL; // local variable
    // head = Insert(head, 2);
    // head = Insert(head, 4);
    // head = Insert(head, 6);
    // head = Insert(head, 5);
    printf("How many nos you want to insert?\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the no: ");
        scanf("%d", &x);
        head = Insert(head, x);
    }

    Print(head);
    printf("\n");
    reversePrint(head);
    return 0;
}