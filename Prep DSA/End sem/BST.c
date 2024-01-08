#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("\nMemory Allocation Failed");
    }
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}
struct node *insert(struct node *root, int value)
{
    if (root == NULL)
        return createnode(value);
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
struct node *findMin(struct node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

struct node *delete(struct node *root, int value)
{
    if (root == NULL)
    {
        printf("Value not found for deletion.\n");
        return NULL;
    }

    if (value < root->data)
    {
        root->left = delete (root->left, value);
    }
    else if (value > root->data)
    {
        root->right = delete (root->right, value);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            struct node *Isucc = findMin(root->right);
            root->data = Isucc->data;
            root->right = delete (root->right, Isucc->data);
        }
    }
    return root;
}

struct node *search(struct node *root, int value)
{
    if (root == NULL || root->data == value)
        return root;

    if (value < root->data)
        return search(root->left, value);
    else if (value > root->data)
        return search(root->right, value);
}

int main()
{
    int choice, value;
    struct node *root = NULL;
    printf("\nMain Menu");
    printf("\n1.Insert");
    printf("\n2.Delete");
    printf("\n3.Search");
    printf("\n4.Inorder Traversal");
    printf("\n-1 to exit");
    while (choice != -1)
    {
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter value to be inserted:");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 2:
            printf("\nEnter value to be deleted:");
            scanf("%d", &value);
            root = delete (root, value);
            break;
        case 3:
            printf("\nEnter value to be search:");
            scanf("%d", &value);
            if (search(root, value) != NULL)
                printf("\nNode Found");
            else
                printf("\nNode not found");
            break;
        case 4:
            inorder(root);
            break;
        case -1:
            printf("\nExiting Program");
            exit(1);
        default:
            printf("\nInvalid Choice");
        }
    }
    return 0;
}