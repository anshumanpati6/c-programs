#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* left;
    int data;
    struct node* right;
};

struct node_queue {
    struct node* data;
    struct node_queue* next;
};

typedef struct {
    struct node_queue* front;
    struct node_queue* rear;
} QUEUE;

struct node_stack {
    struct node* data;
    struct node_stack* next;
};

typedef struct {
    struct node_stack* top;
} STACK;

int enqueue(QUEUE* q, struct node* val) {
    struct node_queue* curr;
    curr = (struct node_queue*)malloc(sizeof(struct node_queue));
    if (curr == NULL) {
        return 1;
    }
    curr->data = val;
    curr->next = NULL;
    if (q->front == NULL) {
        q->front = q->rear = curr;
    } else {
        q->rear->next = curr;
        q->rear = curr;
    }
    return 0;
}

int dequeue(QUEUE* q, struct node** del) {
    if (q->front == NULL) {
        return 1;
    }
    *del = q->front->data;
    if (q->front == q->rear) {
        q->front = q->rear = NULL;
    } else {
        q->front = q->front->next;
    }
    return 0;
}

int is_empty_queue(QUEUE q) {
    return q.front == NULL;
}

int push(STACK* s, struct node* val) {
    if (val == NULL) {
        return 1;
    }
    struct node_stack* curr;
    curr = (struct node_stack*)malloc(sizeof(struct node_stack));
    if (curr == NULL) {
        return 1;
    }
    curr->data = val;
    curr->next = NULL;
    curr->next = s->top;
    s->top = curr;
    return 0;
}

int pop(STACK* s, struct node** del) {
    if (s->top == NULL) {
        return 1;
    }
    *del = s->top->data;
    s->top = s->top->next;
    return 0;
}

int is_empty_stack(STACK s) {
    return s.top == NULL;
}

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

void level_order_reverse_traverse(struct node* root) {
    QUEUE q;
    q.front = q.rear = NULL;
    STACK s;
    s.top = NULL;
    struct node* curr = root;
    if (curr != NULL) {
        enqueue(&q, curr);
        while (!is_empty_queue(q)) {
            dequeue(&q, &curr);
            push(&s, curr);
            if (curr->right != NULL) {
                enqueue(&q, curr->right);
            }
            if (curr->left != NULL) {
                enqueue(&q, curr->left);
            }
        }
        while (!is_empty_stack(s)) {
            pop(&s, &curr);
            printf("%d ", curr->data);
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
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
    level_order_reverse_traverse(root);
    return 0;
}