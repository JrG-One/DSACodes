#include <stdio.h>
#include <stdlib.h>

struct queue {
    int rear, front, size;
    unsigned capacity;
    int* array;
};

struct queue* create(unsigned capacity) {
    struct queue* queue = malloc(sizeof(struct queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = malloc(sizeof(int) * queue->capacity);
    return queue;
}

int isFull(struct queue* q) {
    return (q->size == q->capacity);
}

int isEmpty(struct queue* q) {
    return (q->size == 0);
}

void enqueue(struct queue* q, int item) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue element.\n");
        return;
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->array[q->rear] = item;
    q->size++;
    printf("%d enqueued to queue.\n", item);
}

int dequeue(struct queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue element.\n");
        return -1;
    }
    int d = q->array[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return d;
}

int front(struct queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->array[q->front];
}

int rear(struct queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->array[q->rear];
}

int main() {
    int n;
    printf("Enter capacity of queue: ");
    scanf("%d", &n);
    struct queue* q = create(n);
    int choice = 0;
    while (choice != 8) {
        printf("1. Enqueue\n2. Dequeue\n3. Full\n4. Empty\n5. Front\n6. Rear\n7. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int x;
                printf("Enter the data you want to enqueue: ");
                scanf("%d", &x);
                enqueue(q, x);
                break;
            }
            case 2: {
                int d = dequeue(q);
                if (d != -1)
                    printf("Dequeued element is: %d\n", d);
                break;
            }
            case 3: {
                if (isFull(q))
                    printf("Queue is Full\n");
                else
                    printf("Queue is not full\n");
                break;
            }
            case 4: {
                if (isEmpty(q))
                    printf("Queue is empty\n");
                else
                    printf("Queue is not empty\n");
                break;
            }
            case 5: {
                int ele = front(q);
                if (ele != -1)
                    printf("Front element is: %d\n", ele);
                break;
            }
            case 6: {
                int elem = rear(q);
                if (elem != -1)
                    printf("Rear element is: %d\n", elem);
                break;
            }
            case 7: {
                printf("Exiting...\n");
                exit(0);
                break;
            }
            default: {
                printf("INVALID INPUT\n");
            }
        }
    }
    return 0;
}
