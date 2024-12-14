#include <stdio.h>
#include <stdlib.h>

// Define a structure for the doubly linked list node
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
Node* insertStart(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }

    newNode -> next = head;
    head -> prev = newNode;
    head = newNode;
    return head;
}

// Function to traverse the doubly linked list
void traverseList(Node* head) {
    Node* temp = head;
    printf("Doubly Linked List in Forward Direction: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to traverse the doubly linked list in reverse
void reverseTraverseList(Node* head) {
    if (head == NULL) {
        return;
    }

    // Move to the last node
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Traverse backward
    printf("Doubly Linked List in Reverse Direction: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Main function
int main() {
    Node* head = NULL;

    // Insert nodes into the doubly linked list
    head = insertStart(head, 40);
    head = insertStart(head, 30);
    head = insertStart(head, 20);
    head = insertStart(head, 10);

    // Traverse the list in forward direction
    traverseList(head);

    // Traverse the list in reverse direction
    reverseTraverseList(head);

    return 0;
}
    