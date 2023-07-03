#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("%d enqueued to the queue.\n", data);
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    struct Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    free(temp);
    return data;
}

int front(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue->front->data;
}

int rear(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue->rear->data;
}

int main() {
    struct Queue* queue = createQueue();
     int n,choice=0;
     while(1){
        printf("\n 1. enqueue\n 2. dequeue\n 3. isempty\n 4.front\n 5.rear\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:{
                int data;
                printf("Enter the data you want to insert:\n");
                scanf("%d",&data);
                enqueue(queue,data);
                //printf("%d enqueue to queue\n",data);
                break;
            }
            case 2:{
                int x;
               x=dequeue(queue);
               printf("%d data is dequeued",x);
                break;
            }
            case 3: {
                int d;
               d=isEmpty(queue);
               if(d==0) printf("Queue is empty");
               else printf("Not Empty");
               break;
            }
            case 4: {
                int data;
                data=front(queue);
                printf("%d is at front of queue",data);
                break;
            }
            case 5:
            {
                int d=rear(queue);
                printf("%d is at rear of queue",d);
                break;
            }
            default:
            {
                printf("Invalid Input");
            }
        }
    }
}
