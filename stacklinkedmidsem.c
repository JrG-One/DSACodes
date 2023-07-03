#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node*next;
} *top=NULL;

struct Node* createstack(int data){
	struct Node*newnode=malloc(sizeof(struct Node));
	newnode->data=data;
	newnode->next=NULL;
	top=newnode;
	return top;
}

void push(int data){
	struct Node*newNode=malloc(sizeof(struct Node));
	if(newNode==NULL){
        printf("Stack overflow");
        exit(1);
	}
	newNode->data=data;
	//newNode->next=NULL;
	newNode->next=top;
	top=newNode; 
}

int isEmpty()
	{
	return top==NULL;
}
void pop(){
	struct Node*temp;
	temp=top;
	if(isEmpty()){
        printf("Stack underflow");
        exit(1);
	}
	int val=temp->data;
	top=top->next;
	free(temp);
	temp=NULL;
	printf("\n%d has been deleted\n",val);
}

int peek(){
	if(isEmpty()){
        printf("Stack underflow");
        exit(1);
	}
	return top->data;
}
void print(){
	struct Node*temp;
	temp=top;
	if(isEmpty()){printf("Stack underflow");exit(1);
	}
	printf("Stack elements are: ");
	while(temp){
		printf("%d ",temp->data);
		temp=temp->next;
	}
}

int main(){int data;
	int n,choice=0;
    struct Stack* s;
    while(1){
        printf("\n 1. push\n 2. pop\n 3. traverse\n 4.isempty\n 5.peek\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:{
                int data;
                printf("Enter the data you want to insert:\n");
                scanf("%d",&data);
                push(data);
                printf("%d pushed to stack\n",data);
                break;
            }
            case 2:{
               
               pop();
                break;
            }
            case 3: {
               print();
               break;
            }
            case 4: {
                if (isEmpty(s))
                printf("Stack is empty\n");
                else
                printf("Stack is not empty\n");
                break;
            }
            case 5:
            {
                int d=peek(s);
                printf("Element at Top is: %d\n",d);
                break;
            }
            default:
            {
                printf("Invalid Input");
            }
        }
    }
}