//implimentation of singly linked list TimeCo,plexity : o(1) linear search 
//work: next/back button , music player, webbrowser, image viewers
#include <stdio.h>
#include <stdlib.h>
typedef struct structure{
    int info;
    struct structure *next;
}sn;

sn* insertAtBegning(sn* head);
sn* deleteFromLast(sn* head);
void display(sn* head);
sn* reverse(sn* head);

int main()
{
    sn* head =NULL;
    int  ch=1;
    do{
        printf("Enter the choice \n1.) insertAtBegning \n2.) deleteFromLast \n3.) display \n0.) to exit loop\n:");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("inserting");
                head = insertAtBegning(head);
                break;
            case 2:
                head = deleteFromLast(head);
                break;
            case 3:
                display(head);
                break;
            case 0:
                ch  = 0;
        }
    }while(ch != 0);
    return 0;
}

sn* insertAtBegning(sn* head){
    sn* temp;
    temp = (sn*)malloc(sizeof(sn));
    if(temp == NULL)    printf("No memory");
    else if(head == NULL){
        printf("Enter info");
        scanf("%d",&temp->info);
        head = temp;
        temp->next = NULL;
    }else{
         printf("Enter info");
         scanf("%d",&temp->info);
         temp->next = head;
         head = temp;
         return head;
    }
    }

sn* deleteFromLast(sn* head){
    // sn* temp;
    // temp = (sn*)malloc(sizeof(sn));
    // if(temp == NULL)    printf("No memory");
    if(head == NULL){
        printf("list is empty");
    }
        
    else{
        sn* p1 = head;
        sn* p2 = NULL;
        
        while(p1->next != NULL){
            p1 = p1->next;
            p2 = p1;
        }
        p2->next = NULL;
        free(p1);
        return head;
    }
}

sn* reverse(sn* head){
    sn* prev = NULL;
    sn* nextnode = NULL;
    sn* current = head;
    while(current != NULL){
            nextnode = current->next;
            current->next = prev;
            prev = current;
            current = nextnode
    }return prev;
}

void removeDuplicates(sn* head) {
    if (head == NULL) {
        return;
    }

    sn* current = head;

    while (current != NULL) {
        // Check for duplicate elements
        sn* runner = current;
        while (runner->next != NULL) {
            if (runner->next->data == current->data) {
                sn* duplicate = runner->next;
                runner->next = runner->next->next;
                free(duplicate);
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

void bubbleSort(sn* head) {
    if (head == NULL || head->next == NULL) {
        return;  // Empty or single-node list is already sorted
    }

    int swapped;
    sn* temp;
    sn* last = NULL;

    do {
        swapped = 0;
        sn* current = head;

        while (current->next != last) {
            if (current->info > current->next->info) {
                // Swap data if the current node is greater than the next node
                int tempData = current->info;
                current->info = current->next->info;
                current->next->info = tempData;
                swapped = 1;
            }
            current = current->next;
        }

        last = current;

    } while (swapped);
}

struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    struct Node* mergedList = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            mergedList = insertAtEnd(mergedList, list1);
            list1 = list1->next;
        } else {
            mergedList = insertAtEnd(mergedList, list2);
            list2 = list2->next;
        }
    }

    // If one of the lists is not empty, append the remaining elements
    while (list1 != NULL) {
        mergedList = insertAtEnd(mergedList, list1->data);
        list1 = list1->next;
    }

    while (list2 != NULL) {
        mergedList = insertAtEnd(mergedList, list2->data);
        list2 = list2->next;
    }

    return mergedList;
}
/*// Function to find the length of the linked list
int getLength(struct Node* head) {
    int length = 0;
    struct Node* current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

// Function to rotate the linked list to the right by n positions
struct Node* rotateRight(struct Node* head, int n) {
    if (head == NULL || n == 0) {
        return head; // No rotation needed
    }

    int length = getLength(head);

    // Calculate the effective rotation index
    n = n % length;

    if (n == 0) {
        return head; // No rotation needed
    }

    // Find the new head position
    int newHeadIndex = length - n;
    struct Node* current = head;
    struct Node* newHead = NULL;
    struct Node* newTail = NULL;

    for (int i = 0; i < length; i++) {
        if (i == newHeadIndex - 1) {
            newTail = current;
        }

        if (i == newHeadIndex) {
            newHead = current->next;
            current->next = NULL;
            break;
        }

        current = current->next;
    }

    // Connect the new head and tail
    if (newHead != NULL && newTail != NULL) {
        newTail->next = head;
        return newHead;
    } else {
        return head; // Invalid state, return original list
    }
}*/
void display(sn* head) {
    sn* current = head;
    while (current != NULL) {
        printf("%d -> ", current->info);
        current = current->next;
    }
    printf("NULL\n");
}
