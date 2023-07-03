#include<stdio.h>
#include<string.h>

struct student {
	int roll, marks;
	char name[50], place[30];
};

void Display(struct student *ptr);

void Display(struct student *ptr) {
	printf("\nRoll no: %d", ptr->roll);
	printf("\nName: %s", ptr->name);
	printf("\nPlace: %s", ptr->place);
	printf("\nMarks: %d", ptr->marks);
}

int main() {
	struct student s;
	struct student *ptr;
	ptr = &s;

	printf("Enter Roll No: ");
	scanf("%d", &ptr->roll);

	printf("Enter Place: ");
	getchar();
	gets(ptr->place);

	printf("Enter Marks: ");
	scanf("%d", &ptr->marks);

	printf("Enter Name: ");
	getchar();
	gets(ptr->name);

	Display(ptr);
	
	return 0;
}
