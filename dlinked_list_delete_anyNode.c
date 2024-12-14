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
Node* insertOrederList(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    
    Node* temp = head;
    if(data < temp -> data){
        newNode -> next = head;
        head -> prev = newNode;
        head = newNode;
        return head;
    }
    Node* pre = NULL;
    while(temp -> next != NULL && data > temp -> data){
        pre = temp;
        temp = temp -> next;
    }
    newNode -> next = temp;
    temp -> prev = newNode;
    pre -> next = newNode;
    newNode -> prev = pre;
    
    return head;
}

Node* deleteNode(Node* head, int dataitem) {
    if (head == NULL) {
        printf("Linked list is empty...\n");
        return NULL;
    }

    struct Node* temp = head;
    struct Node* pre = NULL;

    // If the node to be deleted is the first node
    if (temp != NULL && temp->data == dataitem) {
        head = temp->next;  // Change head
        head -> prev = NULL;
        free(temp);  // Free the node
        printf("Node deleted succesfully\n");
        return head;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->data != dataitem) {
        pre = temp;
        temp = temp->next;
    }

    // If the node was not found
    if (temp == NULL) {
        printf("Node with value %d not found.\n", dataitem);
        return head;
    }

    if(temp -> next == NULL){
        pre -> next = NULL;
        free(temp);
        return head;
    }

    // Unlink the node from the list
    pre->next = temp->next;
    temp -> next -> prev = pre;
    free(temp);  // Free the memory of the deleted node
    printf("Node deleted succesfully\n");
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
    int dataitem;

    // Insert nodes into the doubly linked list
    head = insertOrederList(head, 40);
    head = insertOrederList(head, 30);
    head = insertOrederList(head, 35);
    head = insertOrederList(head, 10);
    head = insertOrederList(head, 50);
    head = insertOrederList(head, 45);

    printf("Original doubly linked list...");
    traverseList(head);
    reverseTraverseList(head);

    printf("Enter a data of Node which you want to delete: ");
    scanf("%d",&dataitem);

    head = deleteNode(head, dataitem);
    printf("After deleting a Node\n");
    
    traverseList(head);
    reverseTraverseList(head);

    return 0;
}
    