#include <stdio.h>

void insertion_sort(int a[], int n)
{
    int key, i, j;
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
}

int binary_search(int a[], int x, int low, int high)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == x)
            return mid;
        else if (a[mid] < x)
            return binary_search(a, x, mid + 1, high);
        else
            return binary_search(a, x, low, mid - 1);
    }
    else
    {
        return -1; // Indicate that the value is not found
    }
}

int main()
{
    int n, i, x, low, high;

    printf("Enter the number of elements you want: ");
    scanf("%d", &n);

    int a[100];
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    insertion_sort(a, n);

    printf("Sorted elements: ");
    for (int k = 0; k < n; k++)
    {
        printf("%d ", a[k]);
    }

    printf("\nEnter the number you want to search: ");
    scanf("%d", &x);

    low = 0;
    high = n - 1;

    int result = binary_search(a, x, low, high);

    if (result != -1)
        printf("Element %d is found at index %d\n", x, result);
    else
        printf("Element %d is not found\n", x);

    return 0;
}
