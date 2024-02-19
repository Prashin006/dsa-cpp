#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct BstNode
{
    int data;
    struct BstNode *left;
    struct BstNode *right;
} BstNode;

BstNode *root = NULL;

BstNode *GetNewNode(int data)
{
    BstNode *newNode = (BstNode *)malloc(sizeof(BstNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BstNode *Insert(BstNode *root, int data)
{
    if (root == NULL)
    {
        root = GetNewNode(data);
    }
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = Insert(root->right, data);
    }
    return root;
}
bool Search(BstNode *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data == data)
    {
        return true;
    }
    else if (data <= root->data)
    {
        return Search(root->left, data);
    }
    else
        return Search(root->right, data);
}

int FindMin(BstNode *root)
{ // Using recursion
    if (root == NULL)
    {
        printf("Error: Tree is empty\n");
        return -1;
    }
    else if (root->left == NULL)
    {
        return root->data;
    }
    return FindMin(root->left);
}

int FindMax(BstNode *root)
{ // Using iteration
    if (root == NULL)
    {
        printf("Error: Tree is empty\n");
        return -1;
    }
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}

int maximum(int a, int b)
{
    if (a >= b)
    {
        return a;
    }
    else
        return b;
}

int FindHeight(BstNode *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int leftHeight = FindHeight(root->left);
    int rightHeight = FindHeight(root->right);
    return maximum(leftHeight, rightHeight) + 1;
}
int main()
{
    int nm;
    bool a;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 45);
    root = Insert(root, 19);
    root = Insert(root, 22);
    root = Insert(root, 31);
    root = Insert(root, 56);
    printf("Enter the number you want to be searched: ");
    scanf("%d", &nm);
    a = Search(root, nm);
    if (a == true)
    {
        printf("Found\n");
    }
    else if (a == false)
    {
        printf("Not found\n");
    }
    printf("The minimum element in the tree is %d\n", FindMin(root));
    printf("The maximum element in the tree is %d\n", FindMax(root));
    printf("The height of the given BST is %d\n", FindHeight(root));
    // printf("%d %d %d", root->left->data, root->data, root->right->data);

    return 0;
}