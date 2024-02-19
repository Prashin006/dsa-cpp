// Program to check baalancing of parentheses
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node
{
    char data;
    struct Node *next;
};
struct Node *top = NULL;

void Push(char x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}
void Pop()
{
    struct Node *temp = top;
    top = temp->next;
    free(temp);
}

bool isEmpty()
{
    if (top == NULL)
    {
        return true;
    }
    else
        return false;
}
void Print()
{
    struct Node *temp = top;
    while (temp != NULL)
    {
        printf("%c ", temp->data);
        temp = temp->next;
    }
}
void checkBalance(char arr[], int n)
{
    char x;
    int i = 0;
    // char arr[500];
    // printf("Enter the string in which you want to check balancing of parentheses\n");
    // gets(arr);
    // puts(arr);
    // n = strlen(arr);
    // printf("%d\n", n);
    while (arr[i] != '\0')
    {
        if (arr[i] == '(' || arr[i] == '{' || arr[i] == '[')
        {
            Push(arr[i]);
        }
        else if (arr[i] == ')' || arr[i] == '}' || arr[i] == ']')
        {
            char y = arr[i];
            if (top->data == y)
            {
                printf("Values not matching\n");
            }
            else
            {
                Pop();
            }
        }
        i++;
    }
    bool a = isEmpty() ? true : false;
    if (a == true)
    {
        printf("Values are matching\n");
    }
    // return isEmpty() ? true : false;
}
int main()
{
    int n;
    char x;
    char arr[500];
    printf("Enter the string you want to check for balancing of parenthese: \n");
    gets(arr);
    n = strlen(arr);
    for (int i = 0; i < n; i++)
    {
        printf("%c", arr[i]);
    }
    printf("\n");
    // printf("Enter the length of the string you want to check\n");
    // scanf("%d", &n);

    checkBalance(arr, n);
    // Print();
    return 0;
}