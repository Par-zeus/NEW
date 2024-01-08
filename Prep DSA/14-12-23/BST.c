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
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
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
struct node *isucc(struct node *root)
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
        return root;
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
     if(root->left==NULL)
        {
            struct node *temp=root->left;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            struct node *temp=root->right;
            free(root);
            return temp;
        }

        struct node *isucce = isucc(root->right);
        root->data = isucce->data;
        root->right = delete (root->right, isucce->data);
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
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
struct node *search(struct node *root, int value)
{
    if (root->data == value)
    {
        return root;
    }
    if (value < root->data)
    {
        return search(root->left, value);
    }
    return search(root->right, value);
}
int main()
{
    int choice, value;
    struct node *root = createnode(10);
    root->left = createnode(9);
    root->right = createnode(11);

    printf("\nMain Menu");
    printf("\n1.Insert");
    printf("\n2.Delete");
    printf("\n3.Search");
    printf("\n4.Preorder Traversal");
    printf("\n5.Inorder Traversal");
    printf("\n6.Postorder Traversal");
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
            printf("\nEnter value you want to search:");
            scanf("%d", &value);
            if (search(root, value) != NULL)
            {
                printf("Node found!\n");
            }
            else
            {
                printf("Node not found.\n");
            }
            break;
        case 4:
            preorder(root);
            break;
        case 5:
            inorder(root);
            break;
        case 6:
            postorder(root);
            break;
        case -1:
            exit(1);
        default:
            printf("\nInvalid choice");
        }
    }

    return 0;
}