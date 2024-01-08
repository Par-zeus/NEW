#include <stdio.h>
#define SIZE 10

int hashTable[SIZE] = {0};

// Function to insert a key using linear probing
void insertLinearProbing(int key) {
    int index = key % SIZE;

    while (hashTable[index] != 0) {
        index = (index + 1) % SIZE;
    }

    hashTable[index] = key;
}

// Function to display the hash table
void displayHashTable() {
    printf("Hash Table (Linear Probing): ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", hashTable[i]);
    }
    printf("\n");
}

int main() {
    int key;

    printf("\nEnter keys to insert (Linear Probing):\n");
    printf("\nEnter -1 to stop inserting");
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &key);
        if(key==-1) break;
        insertLinearProbing(key);
    }

    displayHashTable();

    return 0;
}
