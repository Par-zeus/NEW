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

// Function to delete a key
void deleteKey(int key) {
    int index = key % SIZE;

    while (hashTable[index] != 0) {
        if (hashTable[index] == key) {
            hashTable[index] = 0;
            printf("Key %d deleted successfully.\n", key);
            return;
        }
        index = (index + 1) % SIZE;
    }

    printf("Key %d not found.\n", key);
}

// Function to display the hash table
void displayHashTable() {
    printf("Hash Table: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", hashTable[i]);
    }
    printf("\n");
}

int main() {
    int choice, key;

    do {
        printf("\nMenu:\n");
        printf("1. Insert (Linear Probing)\n");
        printf("2. Insert (Quadratic Probing)\n");
        printf("3. Delete\n");
        printf("4. Display Hash Table\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert (Linear Probing): ");
                for(int i=0;i<SIZE;i++){
                scanf("%d", &key);
                insertLinearProbing(key);}
                break;
            case 2:
                for(int i=0;i<SIZE;i++){
                printf("Enter key to insert (Quadratic Probing): ");
                scanf("%d", &key);
                insertQuadraticProbing(key);}
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteKey(key);
                break;
            case 4:
                displayHashTable();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
