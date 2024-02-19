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
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void Insert(int data, int n)
{
    struct Node *temp1 = (struct Node *)malloc(sizeof(struct Node));
    (*temp1).next = NULL;
    (*temp1).data = data;
    if (n == 1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }
    struct Node *temp2 = head;
    for (int i = 0; i < n - 2; i++)
    {
        temp2 = temp2->next; // for traversing the array upto list no n-1
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}
int main()
{
    int n, i, p, x;
    head = NULL;
    // Insert(2, 1); // 2
    // Insert(3, 2); // 2 3
    // Insert(4, 2); // 2 4 3
    // Insert(5, 1); // 5 2 4 3
    // printf("The given list is \n");
    // Print();
    printf("How many elements you want to add?\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the element and postion at which you want to add it\n");
        scanf("%d %d", &x, &p);
        Insert(x, p);
    }
    Print();
    return 0;
}
