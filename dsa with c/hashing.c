//hashing : is a technique to store data elements in such a way that searching a element is very efficent
//time complexity : linear search o(n) : binary search o(log n) : hashing o(1)
//1.) ideal hashing : store integer keys at there corresponding indexes  a[0]=0, a[4]=4
//drawback : more empty spaces if one element is 500 than we have to create the array of length 500 

//2.) using hashing function : we will %10 its value then store in the respective indixes 
//drawback : colloision of elements like 22 ,122  

//resolving collision : there are 2 ways 1. open chaining 2. close chaining

//2.1) open hashing/ chaining : x%10 elemet having same indixes will store in same index in linked list 
//for serching we will first find the index of the element and then search the element there
#include <stdio.h>
#include <stdlib.h>

// Define the size of the hash table
#define SIZE 10

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a key into the hash table
void insert(int key, struct Node* hashTable[]) {
    int index = key % SIZE; // Calculate the hash index

    // Create a new node with the key
    struct Node* newNode = createNode(key);

    // If the slot is empty, insert the new node
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else { // If the slot is not empty, add to the linked list
        struct Node* current = hashTable[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to search for a key in the hash table
void search(int key, struct Node* hashTable[]) {
    int index = key % SIZE; // Calculate the hash index

    // Traverse the linked list at the calculated index
    struct Node* current = hashTable[index];
    while (current != NULL) {
        if (current->data == key) {
            printf("Key %d found in the hash table.\n", key);
            return;
        }
        current = current->next;
    }

    printf("Key %d not found in the hash table.\n", key);
}

// Function to display the hash table
void display(struct Node* hashTable[]) {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d: ", i);
        struct Node* current = hashTable[i];
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    // Initialize the hash table with NULL pointers
    struct Node* hashTable[SIZE] = {NULL};

    // Insert some keys into the hash table
    insert(5, hashTable);
    insert(15, hashTable);
    insert(25, hashTable);
    insert(6, hashTable);
    insert(16, hashTable);

    // Display the hash table
    display(hashTable);

    // Search for keys in the hash table
    search(5, hashTable);
    search(10, hashTable);

    return 0;
}

//2.2) close hashing/ linear : here in case of collision the element intermediate to the next position  (x+i)%10 where i is the starting position of index =0
//hashing function ideas

//3.)hashing function ideas :
//3.1) h(x) = (x%size)+1 where size should be prime  so the number of collision reduce 
//3.2) mid square funtion : h(x) = sq(middigit) ex = h(242) = 16 
//3.3) folding : partition keys and add values ex 23941 = 23 + 94 + 1 = 138 = 13+8 = 21
 