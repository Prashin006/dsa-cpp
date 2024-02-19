#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

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

// insert an integer at end of list
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

void Delete(int n) // delete node at position n
{
    struct Node *temp1 = head;
    if (n == 1)
    {
        head = temp1->next; // head now points to second node
        free(temp1);
        return;
    }
    struct Node *temp2;
    for (int i = 0; i < n - 2; i++)
    {
        temp1 = temp1->next; // temp1 points to (n-1)th node
    }
    temp2 = temp1->next;       // nth node
    temp1->next = temp2->next; // (n+1)th node
    free(temp2);               // delete temp2
}
int main()
{
    head = NULL;
    int i, n, p, x;
    printf("How many elements you want to insert?\n");
    scanf("%d", &p);
    for (i = 0; i < p; i++)
    {
        printf("Enter the element: ");
        scanf("%d", &x);
        Insert(x);
    }
    Print();
    printf("Enter the position at which you want to delete the node\n");
    scanf("%d", &n);
    Delete(n);
    Print();
    return 0;
}