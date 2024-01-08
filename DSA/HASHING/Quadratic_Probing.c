#include <stdio.h>
#define SIZE 10

int hashTable[SIZE] = {0};

// Function to insert a key using quadratic probing
void insertQuadraticProbing(int key) {
    int index = key % SIZE;
    int i = 1;

    while (hashTable[index] != 0) {
        index = (index + i * i) % SIZE;
        i++;
    }

    hashTable[index] = key;
}

// Function to display the hash table
void displayHashTable() {
    printf("Hash Table (Quadratic Probing): ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", hashTable[i]);
    }
    printf("\n");
}

int main() {
    int key;

    printf("Enter keys to insert (Quadratic Probing):\n");
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &key);
        insertQuadraticProbing(key);
    }

    displayHashTable();

    return 0;
}
