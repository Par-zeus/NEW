#include <stdio.h>
#include <conio.h>
void selection_sort(int a[], int n)
{
    int min, temp;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[min] > a[j])
                min = j;
        }
        temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
    printf("Sorted elements are: ");
     for(int k = 0; k < n; k++)
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
    selection_sort(a, n);
}