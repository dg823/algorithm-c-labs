#include <stdio.h>
#include <stdlib.h>

#define RED 0
#define BLACK 1

typedef struct node {
    int key;
    int color;
    struct node* left;
    struct node* right;
    struct node* parent;
} Node;

typedef struct {
    Node* root;
    Node* nil;
} RBTree;

RBTree* createRBTree(void) {
    RBTree* T = (RBTree*)malloc(sizeof(RBTree));

    T->nil = (Node*)malloc(sizeof(Node));
    T->nil->color = BLACK;
    T->nil->left = NULL;
    T->nil->right = NULL;
    T->nil->parent = NULL;

    T->root = T->nil;

    return T;
}

Node* createNode(RBTree* T, int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->key = key;
    newNode->color = RED;
    newNode->left = T->nil;
    newNode->right = T->nil;
    newNode->parent = T->nil;

    return newNode;
}

void inorder(RBTree* T, Node* root) {
    if (root == T->nil) {
        return;
    }

    inorder(T, root->left);
    printf("%d ", root->key);
    inorder(T, root->right);
}

void LEFT_ROTATE(RBTree* T, Node* x) {
    Node* y;

    y = x->right;

    x->right = y->left;

    if (y->left != T->nil) {
        y->left->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == T->nil) {
        T->root = y;
    }
    else if (x == x->parent->left) {
        x->parent->left = y;
    }
    else {
        x->parent->right = y;
    }

    y->left = x;

    x->parent = y;
}

int main(void) {
    RBTree* T = createRBTree();

    Node* x = createNode(T, 10);
    Node* y = createNode(T, 20);
    Node* beta = createNode(T, 15);

    T->root = x;
    x->parent = T->nil;

    x->left = T->nil;
    x->right = y;

    y->parent = x;

    y->left = beta;
    y->right = T->nil;

    beta->parent = y;
    beta->left = T->nil;
    beta->right = T->nil;

    printf("LEFT_ROTATE 전 중위순회: ");
    inorder(T, T->root);
    printf("\n");

    LEFT_ROTATE(T, x);

    printf("LEFT_ROTATE 후 중위순회: ");
    inorder(T, T->root);
    printf("\n");

    printf("\n회전 후 루트 노드: %d\n", T->root->key);
    printf("루트의 왼쪽 자식: %d\n", T->root->left->key);
    printf("루트의 왼쪽 자식의 오른쪽 자식: %d\n", T->root->left->right->key);

    return 0;
}