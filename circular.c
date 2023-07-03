#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node*next;
};
struct Node* circularsingly(int data){
	struct Node*temp=malloc(sizeof(struct Node));
	temp->data=data;
	temp->next=temp;
	return temp;
}
void print(struct Node*tail){int x=1;
	if(tail==NULL)printf("List is Empty");
	else{
	
	struct Node*temp=tail->next;
	do
	{		
		printf("Node %d :%d \n",x,temp->data);
		temp=temp->next;
		x++;
	}	while(temp!=tail->next);
}
}
struct Node*addatbeg(struct Node* tail,int data){
   	struct Node*newP=malloc(sizeof(struct Node));
	if(tail==NULL){
	newP->data=data;
	newP->next=newP;
 	tail=newP;
 	return tail;
	}
	newP->data=data;
	newP->next=tail->next;
	tail->next=newP;
	return tail;
}
struct Node* addatend(struct Node*tail,int data){
	struct Node*newP=malloc(sizeof(struct Node));
	if(tail==NULL){
	newP->data=data;
	newP->next=newP;
 	tail=newP;
 	return tail;
	}
	newP->data=data;
	newP->next=NULL;
	newP->next=tail->next;
	tail->next=newP;
	tail=tail->next;
	return tail;
}
struct Node*addtoempty(int data){
	struct Node*temp=malloc(sizeof(struct Node));
	temp->data=data;
	temp->next=temp;
	return temp;
}

struct Node*deletefirst(struct Node*tail){
 if(tail==NULL)return tail;
 if(tail->next==tail){free (tail);
 tail=NULL;
 return tail;
 }
 struct Node*temp=tail->next;
 tail->next=temp->next;
 free(temp);
 temp=NULL;
 return tail;
}

struct Node*deletelast(struct Node*tail){
	if(tail==NULL)return tail;
	struct Node*temp=tail->next;
	if(tail->next==tail){
		free(tail);tail=NULL;
		return tail;
	}
	while(temp->next!=tail){
		temp=temp->next;
	}
	temp->next=tail->next;
	free(tail);
	tail=temp;
	return tail;
}
struct Node*deletepos(struct Node*tail,int pos){
	if(tail==NULL)return tail;
	struct Node*temp=tail->next;
	if(tail->next==tail){free(tail);tail=NULL;return tail;
	}
	if(pos==1){
		tail->next=temp->next;
		free(temp);
		temp=NULL;
		return tail;
	}
	while(pos>2){
		temp=temp->next;
		pos--;
	}
	struct Node*temp2=temp->next;
	temp->next=temp2->next;
	if(temp2==tail)
	tail=temp;
	free(temp2);
	temp2=NULL;
	return tail;
	
}

struct Node*addatpos(struct Node*tail,int data,int pos){
	struct Node*newP=malloc(sizeof(struct Node));
	if(tail==NULL){
	newP->data=data;
	newP->next=newP;
    tail=newP;
    return tail;
	}
	if(pos==1){
	newP->data=data;
	newP->next=tail->next;
	tail->next=newP;
	return tail;
	}
	struct Node*p=tail->next;
	newP->data=data;
	newP->next=NULL;
	while(pos>2){
		p=p->next;
		pos--;
	}
	newP->next=p->next;
	p->next=newP;
	
	if(p==tail){
	tail=tail->next;
	}
	return tail;
}

int main(){int c,k,l,y,i,choice,n;
	struct Node*tail=NULL;

	while(1){
	printf("\n");
	printf("1.insert at beginning\n2.insert at end\n3.insert at position:\n4.Deletion\n5.Traversal\n6.End\n");
	printf("Enter choice:");
	scanf("%d",&y);
	switch(y){
		case 1:
			printf("Enter data ");
			scanf("%d",&n);
			tail=addatbeg(tail,n);print(tail);
				printf("\n");
			break;
		case 2:
			printf("Enter data ");
			scanf("%d",&n);
			tail=addatend(tail,n);print(tail);
				printf("\n");
			break;
		case 3:
		printf("Enter position where you want to insert and data ");
		scanf("%d %d",&y,&n);
		tail=addatpos(tail,n,y);print(tail);
			printf("\n");
		break;
		
		case 4:
		printf("Enter position of the deleting element:");
		scanf("%d",&y);
		tail=deletepos(tail,y);
		printf("After deletion:\n ");
		print(tail);
		break;
		
		case 5:
		 print(tail);
		 break;	
		 
		case 6:
		exit(1);
		default:
			printf("Invalid choice");		
	 }
     printf("\n");
	}
}