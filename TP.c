#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    bool visited;
} Node;

typedef struct QueueNode {
    Node* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
bool isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

void enqueue(Queue* queue, Node* treeNode) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->treeNode = treeNode;
    newNode->next = NULL;
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

Node* dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        return NULL;
    }
    QueueNode* temp = queue->front;
    Node* treeNode = temp->treeNode;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return treeNode;
}

void destroyQueue(Queue* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->visited = false;
    return newNode;
}

void LeafbyLeaf1(Queue* queue, Node* root) {
    if (root == NULL || root->visited) {
        return;
    }
    if ((root->left == NULL || root->left->visited) && (root->right == NULL || root->right->visited)) {
        enqueue(queue, root);
        root->visited = true;
    } else {
        if (root->left != NULL && !root->left->visited) {
            LeafbyLeaf1(queue, root->left);
        }
        if (root->right != NULL && !root->right->visited) {
            LeafbyLeaf1(queue, root->right);
        }
    }
}

int* Traversal2(Node* root) {
    if (root == NULL) {
        return NULL;
    }
    Queue* queue = createQueue();
    if (queue == NULL) {
        printf("Failed to create queue. Insufficient memory.\n");
        return NULL;
    }
    // declare an array of int to store the result
    int* result = (int*)calloc(100, sizeof(int));
    int i = 0;
    while (!root->visited) {
        LeafbyLeaf1(queue, root);
        while (!isEmpty(queue)) {
            Node* node = dequeue(queue);
            // add the node data to the result array
            result[i] = node->data;
            i++;
        }
    }
    destroyQueue(queue);
    return result;
}

void LeafbyLeaf2(Queue* queue, Node* root) {
    if (root == NULL || root->visited) {
        return;
    }
    if ((root->left == NULL || root->left->visited) && (root->right == NULL || root->right->visited)) {
        enqueue(queue, root);
        root->visited = true;
    } else {
        if (root->right != NULL && !root->right->visited) {
            LeafbyLeaf2(queue, root->right);
        }
        if (root->left != NULL && !root->left->visited) {
            LeafbyLeaf2(queue, root->left);
        }
    }
}

int* Traversal4(Node* root) {
    if (root == NULL) {
        return NULL;
    }
    Queue* queue = createQueue();
    if (queue == NULL) {
        printf("Failed to create queue. Insufficient memory.\n");
        return NULL;
    }
    // declare an array of int to store the result
    int* result = (int*)calloc(100, sizeof(int));
    int i = 0;
    while (!root->visited) {
        LeafbyLeaf2(queue, root);
        while (!isEmpty(queue)) {
            Node* node = dequeue(queue);
            // add the node data to the result array
            result[i] = node->data;
            i++;
        }
    }
    destroyQueue(queue);
    return result;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to print binary tree in 2D  
// It does reverse inorder traversal
void print2DUtil(Node *root, int space)  
{  
    // Base case  
    if (root == NULL)  
        return;  
  
    // Increase distance between levels  
    space += 10;  
  
    // Process right child first  
    print2DUtil(root->right, space);  
  
    // Print current node after space  
    // count  
    printf("\n");  
    for (int i = 10; i < space; i++)  
        printf(" ");  
    printf("%d\n", root->data);  
  
    // Process left child  
    print2DUtil(root->left, space);  
}  
  
// Wrapper over print2DUtil()  
void print2D(Node *root)  
{  
   // Pass initial space count as 0  
   print2DUtil(root, 0);  
}  

// function to print an array
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// a function that duplicates a tree
Node* duplicateTree(Node* root) {
    if (root == NULL) {
        return NULL;
    }
    Node* newRoot = createNode(root->data);
    newRoot->left = duplicateTree(root->left);
    newRoot->right = duplicateTree(root->right);
    return newRoot;
}

void ResetTree(Node* root) {
    if (root == NULL) {
        return;
    }
    root->visited = false;
    ResetTree(root->left);
    ResetTree(root->right);
}

int main() {
    Node* root = NULL;
    root = insertNode(root, 45);
    root = insertNode(root, 20);
    root = insertNode(root, 10);
    root = insertNode(root, 35);  
    root = insertNode(root, 65);
    root = insertNode(root, 55);
    root = insertNode(root, 50);
    root = insertNode(root, 58);
    root = insertNode(root, 56);
    root = insertNode(root, 60);
    root = insertNode(root, 57);
    root = insertNode(root, 62);
    root = insertNode(root, 85);
    root = insertNode(root, 75);
    root = insertNode(root, 95);
    root = insertNode(root, 90);
    root = insertNode(root, 98);
    root = insertNode(root, 88);
    int* result = Traversal2(root);
    printf("Traversal 2: ");
    printArray(result, 18);
    ResetTree(root);
    result = Traversal4(root);
    printf("Traversal 4: ");
    printArray(result, 18);
    free(result);
    printf("\n");
}


