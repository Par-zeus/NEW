#include <stdio.h>
#include <string.h>

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a, i, j);
        }
    }
    swap(a, i + 1, high);
    return i + 1;
}

void quicksort(int a[], int low, int high)
{
    if (low < high)
    {
        int p = partition(a, low, high);

        quicksort(a, low, p - 1);
        quicksort(a, p + 1, high);
    }
}

void print(int a[], int n)
{
    printf("\nSorted array:");
    for (int k = 0; k < n; k++)
    {
        printf("%d ", a[k]);
    }
}

void merger(int a[], int low, int mid, int high, int n)
{
    int i, j, k;
    i = low;
    j = mid + 1;
    k = high;
    int b[100];

    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    if (i > mid)
    {
        while (j <= high)
        {
            b[k] = a[j];
            j++;
        }
    }
    else
    {
        while (i <= mid)
        {
            b[k] = a[i];
            i++;
        }
        k++;
    }
    printf("\nSorted array:");
    for (int h = 0; h < n; h++)
    {
        a[h] = b[h];
    }
}

void mergesort(int a[], int low, int high, int n)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(a, low, mid, n);
        mergesort(a, mid + 1, high, n);

        merger(a, low, mid, high, n);
    }
}

void selectionsort(int a[], int n)
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
    printf("\nSorted array:");
    for (int k = 0; k < n; k++)
    {
        printf("%d ", a[k]);
    }
}

void insertionsort(int a[], int n)
{
    int j;
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }

    printf("\nSorted array:");
    for (int k = 0; k < n; k++)
    {
        printf("%d ", a[k]);
    }
}
int bin_search(int a[], int x, int low, int high)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] > x)
            return bin_search(a, x, low, mid - 1);
        else if (a[mid] < x)
            return bin_search(a, x, mid + 1, high);
        else
            return mid;
    }
    else
    {
        return -1;
    }
}
int min(int x, int y)
{
    if (x < y)
        return x;
    else
        return y;
}
int fibsearch(int arr[], int x, int n)
{
    int a = 0, b = 1, c, i, offset = -1;
    c = a + b;
    while (c < n)
    {
        a = b;
        b = c;
        c = a + b;
    }
    while (c > 1)
    {
        i = min(offset + a, n - 1);
        if (arr[i] < x)
        {
            c = b;
            b = a;
            a = c - b;
            offset = i; // shift by 1
        }
        else if (arr[i] > x)
        {
            c = a;
            b = b - a;
            a = c - a; // shift by 2
        }
        else
            return i;
    }

    if (a && arr[offset + 1] == x)
        return offset + 1;

    return -1;
}

int main()
{
    int a[100], size, value;
    printf("\nEnter the size of array:");
    scanf("%d", &size);
    printf("Enter the elements:");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\nOriginal array:");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }

    selectionsort(a, size);

    // insertionsort(a,size);

    // quicksort(a,0,size-1);
    // print(a,size);

    // mergesort(a,0,size-1,size);
    // print(a,size);

    printf("\nEnter the value to be searched:");
    scanf("%d", &value);
    int result = bin_search(a, value, 0, size - 1);

    if (result == -1)
    {
        printf("\n Element %d is not found", value);
    }
    else
    {
        printf("\nElement %d found at index %d", value, result);
    }

    int index = fibsearch(a, value, size);
    if (index >= 0)
    {
        printf("\nelement %d is present in the array at index %d", value, index);
    }
    else
        printf("\nelement not found");
    return 0;
}