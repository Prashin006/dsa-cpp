#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    char data;
    struct Node *next;
};
struct Node *head = NULL;
void push(char x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
}
void pop()
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        struct Node *temp = head;
        head = temp->next;
        free(temp);
    }
}
int isEmpty()
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
int main()
{
    int x;
    int i = 0;
    char arr[500];
    printf("Enter an expression: ");
    gets(arr);
    for (i = 0; i < strlen(arr); i++)
    {
        if (*(arr + i) == "(" || *(arr + i) == "[" || *(arr + i) == "{")
        {
            push(arr[i]);
        }
        else if (*(arr + i) == ")" || *(arr + i) == "]" || *(arr + i) == "}")
        {
            if (arr[i] == head->data)
            {
                pop();
            }
            else
            {
                printf("Not balanced\n");
            }
        }
    }
    x = isEmpty();
    if (x == 0)
    {
        printf("Balanced\n");
    }
    else if (x == -1)
    {
        printf("Not balanced\n");
    }
    return 0;
}