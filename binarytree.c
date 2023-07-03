#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);

    return root;
}

void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int getHeight(struct Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int getMaxPathLength(struct Node* root) {
    if (root == NULL)
        return 0;

    int leftPath = getMaxPathLength(root->left);
    int rightPath = getMaxPathLength(root->right);

    int currentPath = leftPath + rightPath + 1;

    return (leftPath > rightPath ? leftPath : rightPath) + 1;
}

void printLeafNodes(struct Node* root) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
        printf("%d ", root->data);

    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

int main() {
    struct Node* root = NULL;
    int num;

    printf("Enter the elements of the binary tree (-1 to stop):\n");

    while (1) {
        scanf("%d", &num);
        if (num == -1)
            break;
        root = insertNode(root, num);
    }

    printf("\nInorder traversal: ");
    inorder(root);

    printf("\nPreorder traversal: ");
    preorder(root);

    printf("\nPostorder traversal: ");
    postorder(root);

    int height=getHeight(root);
    printf("\nHeight of the tree:%d",height);

    int path=getMaxPathLength(root);
    printf("\nMaximum Path length:%d",path);

    printf("\nValues at leaf Nodes are: ");
    printLeafNodes(root);

    return 0;
}
