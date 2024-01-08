#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int st[MAX];
int topA = -1;
int topB=MAX;

void pushA(int st[], int value)
{
    if(topA==topB-1)
    {
        printf("\nStack overflow");
    }
    else{
        st[++topA]=value;
    }
}
void pushB(int st[], int value)
{
    if(topB-1==topA)
    {
        printf("\nStack overflow");
    }else{
        st[--topB]=value;
    }
}
void popA(int st[])
{
    if(topA==-1)
    {
        printf("\nStack underflow");
    }else{
        printf("Popped element :%d",st[topA]);
        topA--;
    }
}
void popB(int st[])
{
    if(topB==MAX)
    {
        printf("\nStack underflow");
    }else{
         printf("Popped element :%d",st[topB]);
         topB++;
    }
}
void displayA(int st[])
{
      if(topA==topB-1)
    {
        printf("\nStack empty");
    }
    else{
    for (int i=0;i<=topA;i++)
    {
        printf("%d ",st[i]);
    }
    }
}
void displayB(int st[])
{
    if(topB-1==topA)
    {
        printf("\nStack empty");
    }else{
    for(int i=MAX-1;i>topB;i--)
    {
        printf("%d ",st[i]);
    }
    }
}
int main()
{
    int choice, value;
    printf("\nMain Menu");
    printf("\n1.Push in stack A");
    printf("\n2.Push in stack B");
    printf("\n3.Pop in stack A");
    printf("\n4.Pop in stack B");
    printf("\n5.Display elements in stack A");
    printf("\n6.Display elements in stack  B");
    printf("\n-1 to exit");
    while (choice != -1)
    {
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the element to be pushed in stack A:");
            scanf("%d", &value);
            pushA(st, value);
            break;

        case 2:
            printf("\nEnter the element to be pushed in stack B:");
            scanf("%d", &value);
            pushB(st, value);
            break;

        case 3:
            popA(st);
            break;

        case 4:
            popB(st);
            break;

        case 5:
            displayA(st);
            break;
        case 6:
            displayB(st);
            break;
        case -1:
            exit(1);
        default:
            printf("Invalid choice");
        }
    }
    return 0;
}