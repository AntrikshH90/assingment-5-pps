// Demonstration of Linked List
// Short Question 1 - Self-referential Structure

#include <stdio.h>
#include <stdlib.h>

// Self-referential structure for a node in linked list
struct Node {
    int data;              // Data part
    struct Node* next;     // Pointer to next node (self-referential)
};

// Function prototypes
void insertAtBeginning(struct Node** head, int value);
void insertAtEnd(struct Node** head, int value);
void display(struct Node* head);
int countNodes(struct Node* head);
void deleteNode(struct Node** head, int value);

int main() {
    struct Node* head = NULL;  // Initialize empty list
    int choice, value;
    
    printf("========================================\n");
    printf("   LINKED LIST DEMONSTRATION\n");
    printf("========================================\n\n");
    
    while(1) {
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Display list\n");
        printf("4. Count nodes\n");
        printf("5. Delete a node\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                printf("Node inserted at beginning!\n");
                break;
                
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                printf("Node inserted at end!\n");
                break;
                
            case 3:
                display(head);
                break;
                
            case 4:
                printf("Total nodes: %d\n", countNodes(head));
                break;
                
            case 5:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
                
            case 6:
                printf("Exiting program...\n");
                return 0;
                
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}

// Insert node at the beginning
void insertAtBeginning(struct Node** head, int value) {
    // Allocate memory for new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // Assign data
    newNode->data = value;
    
    // Make next of new node point to current head
    newNode->next = *head;
    
    // Move head to point to new node
    *head = newNode;
}

// Insert node at the end
void insertAtEnd(struct Node** head, int value) {
    // Allocate memory for new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // Assign data
    newNode->data = value;
    newNode->next = NULL;
    
    // If list is empty, make new node as head
    if(*head == NULL) {
        *head = newNode;
        return;
    }
    
    // Traverse to the last node
    struct Node* temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    
    // Make last node point to new node
    temp->next = newNode;
}

// Display the linked list
void display(struct Node* head) {
    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("\nLinked List: ");
    struct Node* temp = head;
    
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Count number of nodes
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    return count;
}

// Delete a node with given value
void deleteNode(struct Node** head, int value) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    
    // If list is empty
    if(temp == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    // If head node contains the value
    if(temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        printf("Node with value %d deleted!\n", value);
        return;
    }
    
    // Search for the node to be deleted
    while(temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    
    // If value not found
    if(temp == NULL) {
        printf("Value %d not found in list!\n", value);
        return;
    }
    
    // Unlink the node and free memory
    prev->next = temp->next;
    free(temp);
    printf("Node with value %d deleted!\n", value);
}

/*
OUTPUT SAMPLE:

========================================
   LINKED LIST DEMONSTRATION
========================================

1. Insert at beginning
2. Insert at end
3. Display list
4. Count nodes
5. Delete a node
6. Exit

Enter your choice: 1
Enter value to insert: 10
Node inserted at beginning!

Enter your choice: 2
Enter value to insert: 20
Node inserted at end!

Enter your choice: 1
Enter value to insert: 5
Node inserted at beginning!

Enter your choice: 3

Linked List: 5 -> 10 -> 20 -> NULL

Enter your choice: 4
Total nodes: 3

EXPLANATION:

1. SELF-REFERENTIAL STRUCTURE:
   struct Node {
       int data;
       struct Node* next;  // Points to same type
   };

2. WHY LINKED LIST?
   - Dynamic size
   - Easy insertion/deletion
   - No memory wastage
   - Flexible data structure

3. COMPONENTS:
   - Data: Stores the value
   - Next: Pointer to next node
   - Head: Pointer to first node

4. OPERATIONS:
   - Insert at beginning: O(1)
   - Insert at end: O(n)
   - Delete: O(n)
   - Search: O(n)
   - Display: O(n)

5. TYPES OF LINKED LISTS:
   - Singly Linked List
   - Doubly Linked List
   - Circular Linked List
*/
