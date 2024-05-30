#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
void LeafbyLeaf(Queue* queue, Node* root) {
    if (root == NULL || root->visited) {
        return;
    }
    if ((root->left == NULL || root->left->visited) && (root->right == NULL || root->right->visited)) {
        enqueue(queue, root);
        root->visited = true;
    }
    else {
        LeafbyLeaf(queue, root->left);
        LeafbyLeaf(queue, root->right);
    }
}

void Traversal2(Node* root) {
    if (root == NULL) {
        return;
    }
    Queue* queue = createQueue();
    if (queue == NULL) {
        printf("Failed to create queue. Insufficient memory.\n");
        return;
    }
    while (!root->visited) {
        LeafbyLeaf(queue, root);
        while (!isEmpty(queue)) {
            Node* node = dequeue(queue);
            printf("%d ", node->data);
        }
    }
    destroyQueue(queue);
}