#include <stdio.h>

int main() {
    int arr[100], size, choice, i, pos, value;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    while (1) {
        printf("\nArray Operations:\n");
        printf("1. Insert\n2. Delete\n3. Update\n4. Search\n5. Traverse\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the position where you want to insert the element: ");
                scanf("%d", &pos);
                if (pos < 1 || pos > size + 1) {
                    printf("Invalid position!\n");
                } else {
                    printf("Enter the element to be inserted: ");
                    scanf("%d", &value);
                    for (i = size - 1; i >= pos - 1; i--) {
                        arr[i + 1] = arr[i];
                    }
                    arr[pos - 1] = value;
                    size++;
                    printf("Element inserted successfully!\n");
                }
                break;
            case 2:
                printf("Enter the position where you want to delete the element: ");
                scanf("%d", &pos);
                if (pos < 1 || pos > size) {
                    printf("Invalid position!\n");
                } else {
                    for (i = pos; i < size; i++) {
                        arr[i - 1] = arr[i];
                    }
                    size--;
                    printf("Element deleted successfully!\n");
                }
                break;
            case 3:
                printf("Enter the position where you want to update the element: ");
                scanf("%d", &pos);
                if (pos < 1 || pos > size) {
                    printf("Invalid position!\n");
                } else {
                    printf("Enter the new value: ");
                    scanf("%d", &value);
                    arr[pos - 1] = value;
                    printf("Element updated successfully!\n");
                }
                break;
            case 4:
                printf("Enter the element to be searched: ");
                scanf("%d", &value);
                for (i = 0; i < size; i++) {
                    if (arr[i] == value) {
                        printf("Element found at position %d!\n", i + 1);
                        break;
                    }
                }
                if (i == size) {
                    printf("Element not found!\n");
                }
                break;
            case 5:
                printf("Array elements are: ");
                for (i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 6:
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}