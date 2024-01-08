#include <stdio.h>

int min(int x, int y)
{
    return (x <= y) ? x : y;
}

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
    printf("\n");
}

int fibonacci_search(int arr[], int x, int n)
{
    int fib_m2 = 0;                     // (m-2)'th Fibonacci Number
    int fib_m1 = 1;                     // (m-1)'th Fibonacci Number
    int fib_m = fib_m1 + fib_m2; // m'th Fibonacci Number

    while (fib_m < n)
    {
        fib_m2 = fib_m1;
        fib_m1 = fib_m;
        fib_m = fib_m1 + fib_m2;
    }

    int offset = -1; // The offset used to compare arr[index] with x
    while (fib_m > 1)
    {
        int i = min(offset + fib_m2, n - 1);

        if (arr[i] < x)
        {
            fib_m = fib_m1;
            fib_m1 = fib_m2;
            fib_m2 = fib_m - fib_m1;
            offset = i;
        }
        else if (arr[i] > x)
        {
            fib_m = fib_m2;
            fib_m1 = fib_m1 - fib_m2;
            fib_m2 = fib_m - fib_m1;
        }
        else
        {
            return i; // Found the element
        }
    }

    if (fib_m1 && arr[offset + 1] == x)
    {
        return offset + 1;
    }

    return -1; // Element not found
}

int main()
{
    int n, x;

    printf("Enter the number of elements you want: ");
    scanf("%d", &n);

    int arr[100];
    printf("Enter the sorted elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    insertion_sort(arr,n);

    printf("Enter the element you want to search: ");
    scanf("%d", &x);

    int result = fibonacci_search(arr, x, n);

    if (result != -1)
    {
        printf("Element %d is present at index %d.\n", x, result);
    }
    else
    {
        printf("Element %d is not present in the array.\n", x);
    }

    return 0;
}
