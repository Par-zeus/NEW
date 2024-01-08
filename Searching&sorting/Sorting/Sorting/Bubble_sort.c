#include <stdio.h>
#include <conio.h>
void bubble_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
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
    bubble_sort(a, n);
}