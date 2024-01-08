#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *n;
    n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

/**
 * The insert function recursively inserts a new Node with the given value into a binary search tree.
 *
 * @param root The root parameter is a pointer to the root Node of a binary search tree.
 * @param value The value to be inserted into the binary search tree.
 *
 * @return the updated root Node of the binary search tree after inserting the new value.
 */
struct Node *insert(struct Node *root, int value)
{
    if (root == NULL)
        return createNode(value);

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

void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);

        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);

        printf("%d ", root->data);
    }
}

struct Node *findSmallestElement(struct Node *root)
{
    if (root == NULL || root->left == NULL)
    {
        return root;
    }
    else
    {
        return findSmallestElement(root->left);
    }
}

struct Node *findLargestElement(struct Node *root)
{
    if (root == NULL || root->right == NULL)
    {
        return root;
    }
    else
    {
        return findLargestElement(root->right);
    }
}

struct Node *inOrderPredecessor(struct Node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct Node *deleteNode(struct Node *root, int value)
{
    struct Node *iPre;
    if (root == NULL)
        return NULL;

    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else
    {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}

int TotalNodes(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return (TotalNodes(root->left) + TotalNodes(root->right) + 1);
    }
}

int TotalExternalNodes(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    else
    {
        return (TotalExternalNodes(root->left) + TotalExternalNodes(root->right));
    }
}

int TotalInternalNodes(struct Node *root)
{
    if (root == NULL || root->left == NULL || root->right == NULL)
    {
        return 0;
    }
    else
    {
        return (TotalInternalNodes(root->left) + TotalInternalNodes(root->right) + 1);
    }
}

int Height(struct Node *root)
{
    int leftHeight, rightHeight;
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        leftHeight = Height(root->left);
        rightHeight = Height(root->right);
        if (leftHeight > rightHeight)
            return (leftHeight + 1);
        else
            return (rightHeight + 1);
    }
}

// void mirrorImage(struct Node* root)
// {
//     struct Node* ptr;
//     if(root!=NULL)
//     {
//         mirrorImage(root->left);
//         mirrorImage(root->right);
//         ptr=root->left;
//         ptr->left=ptr->right;
//         root->right=ptr;
//     }
// }

void mirrorify(struct Node *root, struct Node **mirror)
{
    if (root == NULL)
    {
        mirror = NULL;
        return;
    }

    *mirror = createNode(root->data);
    mirrorify(root->left, &((*mirror)->right));
    mirrorify(root->right, &((*mirror)->left));
}

int main()
{
    struct Node *root = createNode(9);

    root->left = createNode(4);
    root->right = createNode(11);

    root->left->left = createNode(2);
    root->left->right = createNode(7);
    root->left->right->left = createNode(5);
    root->left->right->right = createNode(8);
    root->right->right = createNode(15);
    root->right->right->left = createNode(14);

    int option, value;
    struct Node *ptr;
    do
    {
        printf("\n ******MAIN MENU******* \n");
        printf("\n 1. Insert Element");
        printf("\n 2. Preorder ");
        printf("\n 3. Inorder ");
        printf("\n 4. Postorder ");
        printf("\n 5. Find the smallest element");
        printf("\n 6. Find the largest element");
        printf("\n 7. Delete an element");
        printf("\n 8. Count the total number of nodes");
        printf("\n 9. Count the total number of external nodes");
        printf("\n 10. Count the total number of internal nodes");
        printf("\n 11. Determine the height of the root");
        printf("\n 12. Find the mirror image of the root");
        printf("\n 13. Exit");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("\n Enter the value of the new Node : ");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 2:
            printf("\n The elements of the root are : \n");
            preorder(root);
            break;
        case 3:
            printf("\n The elements of the root are : \n");
            inorder(root);
            break;
        case 4:
            printf("\n The elements of the root are : \n");
            postorder(root);
            break;
        case 5:
            ptr = findSmallestElement(root);
            printf("\n Smallest element is :%d", ptr->data);
            break;
        case 6:
            ptr = findLargestElement(root);
            printf("\n Largest element is : %d", ptr->data);
            break;
        case 7:
            printf("\n Enter the element to be deleted : ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            break;
        case 8:
            printf("\n Total no. of nodes = %d", TotalNodes(root));
            break;
        case 9:
            printf("\n Total no. of external nodes = %d",
                   TotalExternalNodes(root));
            break;
        case 10:
            printf("\n Total no. of internal nodes = %d",
                   TotalInternalNodes(root));
            break;
        case 11:
            printf("\n The height of the root = %d", Height(root));
            break;
        case 12:
            printf("Inorder  of constructed root is \n");
            inorder(root);
            struct Node *mirror = NULL;
            mirrorify(root, &mirror);
            printf("\nMirror Image is \n");
            inorder(mirror);
            break;
        }
    } while (option != 13);
    return 0;
}

// struct Node* small = findSmallestElement(root);
// printf("Smallest element is: %d",small->data);

// struct Node* large = findLargestElement(root);
// printf("LArgest Element is: %d",large->data);

// int p = TotalNodes(root);
// printf("Total Number Of NOdes are: %d",p);

// int p = TotalExternalNodes(root);
// printf("Total Number Of External Nodes are: %d",p);

// int p = TotalInternalNodes(root);
// printf("Total Number Of Internal Nodes are: %d",p);

// int height = Height(root);
// printf("Height Of the Tree is: %d",height);

// printf("Inorder  of constructed root is \n");
// inorder(root);
// struct Node* mirror = NULL;
// mirrorify(root,&mirror);
// printf("\nMirror Image is \n");
// inorder(mirror);
