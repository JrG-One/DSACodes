#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
} 

struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}
struct Node *insertAtEnd(struct Node *head, int data) {
    struct Node *newNode, *p;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = newNode;
    return head;
}
struct Node* deleteNode(struct Node* head, int data) {
    struct Node* current = head;
    struct Node* previous = NULL;

    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with value %d not found in list\n", data);
        return head;  
    }

    // if (previous == NULL) {
    //     head = current->next;
    // }
    else {
        previous->next = current->next;
    }

    free(current);
    return head;
}

void printList(struct Node* node) {
    int x=0;
    while (node != NULL) {
        printf("%d is at index %d\n", node->data,x);
        x++;
        node = node->next;
    }
    printf("\n");
}

struct Node* updateNode(struct Node* head, int oldData, int newData) {
    struct Node* current = head;

    while (current != NULL && current->data != oldData) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with value %d not found in list\n", oldData);
        return head;
    }

    current->data = newData;
    return head;
}

int main() {
    struct Node* head = NULL;
    int choice, value, oldValue, newValue;

    while (1) {
        printf("\n1. Insert node at beginning\n 2. Insert at the End \n3. Delete node\n4. Update node\n5. Print list\n6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                break;
            case 3:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                head = deleteNode(head, value);
                break;

            case 4:
                printf("Enter the value to update: ");
                scanf("%d", &oldValue);
                printf("Enter the new value: ");
                scanf("%d", &newValue);
                head = updateNode(head, oldValue, newValue);
                break;

            case 5:
                printf("Linked list: ");
                printList(head);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}