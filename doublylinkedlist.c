#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    (*head)->prev = newNode;
    newNode->next = *head;
    *head = newNode;
}
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteNodebyindex(struct Node** head, int index) {
    struct Node* temp = *head;
    int i =0;
    if (temp == NULL) {
        return;
    }
    while (temp != NULL && i<index) {
        temp = temp->next;
        i++;
    }
    // if (temp == NULL) {
    //     return;
    // }
    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

void deleteNode(struct Node** head, int data) {
    struct Node* temp = *head;
    if (temp == NULL) {
        return;
    }
    if (temp->data == data) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}
void traverse(struct Node* head) {
    struct Node* temp = head;
    int x=0;
    while (temp != NULL) {
        printf("%d is at %d \n", temp->data,x);
        temp = temp->next;
        x++;
    }
    printf("\n");
}
void updateNode(struct Node** head, int oldData, int newData) {
    struct Node* temp = *head;
    while (temp != NULL && temp->data != oldData) {
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    temp->data = newData;
}

void insertAtindex(struct Node** head, int data, int index) {
    struct Node* newNode = createNode(data);
    int i = 0;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL && i < index - 1) {
        temp = temp->next;
        i++;
    }
    if (i != index - 1) {
        printf("Invalid index\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

int main() {
    struct Node* head = NULL;
    int choice, data,olddata,count =-1;
    while (1) {
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete\n");
        printf("4. Traverse\n");
        printf("5. insert by index\n");
        printf("6. Exit\n");
        printf("7. Delete by index\n");
        printf("8.Delete at end\n");
        printf("9.Delete beginning\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                count+=1;
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                count+=1;
                break;
            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                
                printf("after deletion linked list will be :\n");
                traverse(head);
                count-=1;
                break;
            case 4:
                traverse(head);
                break;
            case 5:
                printf("Enter the data to be added:\n");
                scanf("%d",&olddata);
                printf("Enter the index at which data is to be deleted:\n");
                scanf("%d",&data);
                insertAtindex(&head, olddata,data);
                printf("Enter Updating linked list will be :\n");
                traverse(head);
                break;
            case 6:
                exit(0);
            case 7:
                printf("Enter index to delete: ");
                scanf("%d", &data);
                deleteNodebyindex(&head, data);
                printf("after deletion linked list will be :\n");
                traverse(head);
                count-=1;
                break;
            case 8:
                deleteNodebyindex(&head, count);
                printf("after deletion linked list will be :\n");
                traverse(head);
                count-=1;
                break;
                
            case 9:
                    deleteNode(&head, head->data);
                    printf("after deletion linked list will be :\n");
                    traverse(head);
                    count--;
                    break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}