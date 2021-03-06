#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* left;
    int data;
    struct node* right;
};

struct node* create_node(int val) {
    struct node* curr = (struct node*)malloc(sizeof(struct node));
    curr->data = val;
    curr->left = curr->right = NULL;
    return curr;
}

struct node* insert_node(struct node* root, int val) {
    if (root == NULL) {
        root = create_node(val);
    } else if (root->data > val) {
        root->left = insert_node(root->left, val);
    } else {
        root->right = insert_node(root->right, val);
    }
    return root;
}

void traverse(struct node* root, int k, int* count) {
    if (root == NULL || *count >= k) {
        return;
    }
    traverse(root->right, k, count);
    ++(*count);
    if (k == *count) {
        printf("%dth Maximum Element : %d\n", k, root->data);
        return;
    }
    traverse(root->left, k, count);
}

void kth_max(struct node* root, int k) {
    int count = 0;
    traverse(root, k, &count);
}

int main(int argc, char* argv[]) {
    int k = atoi(argv[1]);
    struct node* root = NULL;
    root = insert_node(root, 4);
    root = insert_node(root, 6);
    root = insert_node(root, 2);
    root = insert_node(root, 1);
    root = insert_node(root, 3);
    root = insert_node(root, 5);
    /*    
          4
        /   \
      2       6
     / \     /
    1   3   5
    */

    kth_max(root, k);
    return 0;
}