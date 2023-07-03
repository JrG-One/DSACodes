#include <stdio.h>
#define SIZE 5
int front = -1, rear = -1;
int queue[SIZE];

int isFull()
{
    if ((front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1)))
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if (front == -1)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
        return 1;
    else
        return 0;
}

void enqueue(int item)
{
    if (isFull())
    {
        printf("Queue is full. Cannot enqueue element.\n");
    }
    else
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        queue[rear] = item;
        printf("%d enqueued to the queue.\n", item);
    }
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty. Cannot dequeue element.\n");
    }
    else
    {
        printf("%d dequeued from the queue.\n", queue[front]);
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is empty.\n");
    }
    else
    {
        int i = front;
        printf("Elements in the queue are: ");
        while (i != rear)
        {
            printf("%d ", queue[i]);
            i = (i + 1) % SIZE;
        }
        printf("%d\n", queue[rear]);
    }
}

int main()
{
    int choice, item;

    while (1)
    {
        printf("\nCircular Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to enqueue: ");
            scanf("%d", &item);
            enqueue(item);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
