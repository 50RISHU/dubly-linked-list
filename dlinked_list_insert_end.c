#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int newData){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = newData;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    return newNode;
}

Node* insertEnd(Node* head, int newData){
    Node* newNode = createNode(newData);

    if(head == NULL){
        return newNode;
    }

    Node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }

    temp -> next = newNode;
    newNode -> prev = temp;
    return head;
}

void forwordTraverse(Node* head){
    Node* temp = head;

    printf("Doubly linked list in forword direction: ");
    while(temp != NULL){
        printf("%d -> ",temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

void backwordTravers(Node* head){
    Node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }

    printf("Doubly linked list in Backword direction: ");
    while(temp != NULL){
        printf("%d -> ",temp -> data);
        temp = temp -> prev;
    }
    printf("NULL");
}

int main(){

    Node* head = NULL;

    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);

    forwordTraverse(head);
    backwordTravers(head);
    
    return 0;
}