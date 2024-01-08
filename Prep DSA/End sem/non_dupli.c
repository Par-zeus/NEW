#include <stdio.h>
#define MAX 100

int hash_dupli(int a[], int n, int result[]) {
    int hash[MAX] = {0};
    int count = 0;  // Counter for non-repeating numbers

    for (int i = 0; i < n; i++) {
        hash[a[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (hash[a[i]] == 1) {
            result[count++] = a[i];  // Store the non-repeating number
        }
    }

    return count;  // Return the number of non-repeating numbers found
}

int main() {
    int arr[] = {4,6, 1, 2, 1, 2, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result[n];  // Assuming worst-case that all numbers are non-repeating

    int count = hash_dupli(arr, n, result);

    if (count > 0) {
        printf("The non-repeating numbers are: ");
        for (int i = 0; i < count; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    } else {
        printf("No non-repeating numbers found\n");
    }

    return 0;
}
