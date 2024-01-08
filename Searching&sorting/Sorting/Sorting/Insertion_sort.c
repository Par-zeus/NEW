#include <stdio.h>
#include <conio.h>
void insertion_sort(int a[], int n)
{
    int key = 0, i, j;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    printf("Sorted elements:");
    for (int k = 0; k < n; k++)
    {
        printf("%d ", a[k]);
    }
}

void main()
{
    int n, i, j, x;
    int a[100];
    printf("Enter the number of elements you want:");
    scanf("%d", &n);
    printf("Enter the elements:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    insertion_sort(a, n);
}