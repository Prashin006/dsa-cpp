#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    char data;
    struct Node *left, *right;
};
struct Node *root = NULL;
struct Node *GetNewNode(char c)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = c;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
struct Node *Insert(struct Node *root, char c)
{
    if (root == NULL)
    {
        root = GetNewNode(c);
    }
}
int main()
{

    return 0;
}