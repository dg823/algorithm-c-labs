#include <stdio.h>
#include <stdlib.h>

#define RED 0
#define BLACK 1

typedef struct Node {
    int key;
    int color;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} Node;

typedef struct RBTree {
    Node* root;
    Node* nil;
} RBTree;

/* 새 노드 생성 */
Node* createNode(RBTree* T, int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    
    node->key = key;
    node->color = RED;            // 새 노드는 RED로 삽입
    node->left = T->nil;
    node->right = T->nil;
    node->parent = T->nil;
    
    return node;
}

/* 레드-블랙 트리 초기화 */
RBTree* createRBTree() {
    RBTree* T = (RBTree*)malloc(sizeof(RBTree));
    
    T->nil = (Node*)malloc(sizeof(Node));
    T->nil->color = BLACK;        // NIL 노드는 항상 BLACK
    T->nil->left = NULL;
    T->nil->right = NULL;
    T->nil->parent = NULL;
    
    T->root = T->nil;             // 처음 루트는 NIL
    
    return T;
}

/* 왼쪽 회전 */
void LEFT_ROTATE(RBTree* T, Node* x) {
    Node* y = x->right;
    
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

/* 오른쪽 회전 */
void RIGHT_ROTATE(RBTree* T, Node* x) {
    Node* y = x->left;
    
    x->left = y->right;
    
    if (y->right != T->nil) {
        y->right->parent = x;
    }
    
    y->parent = x->parent;
    
    if (x->parent == T->nil) {
        T->root = y;
    }
    else if (x == x->parent->right) {
        x->parent->right = y;
    }
    else {
        x->parent->left = y;
    }
    
    y->right = x;
    x->parent = y;
}

/* 삽입 후 레드-블랙 트리 규칙 복구 */
void RB_INSERT_FIXUP(RBTree* T, Node* z) {
    Node* y;
    
    while (z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            y = z->parent->parent->right;
            
            // Case 1: 삼촌이 RED
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            // Case 2, 3: 삼촌이 BLACK
            else {
                // Case 2
                if (z == z->parent->right) {
                    z = z->parent;
                    LEFT_ROTATE(T, z);
                }
                
                // Case 3
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                RIGHT_ROTATE(T, z->parent->parent);
            }
        }
        else {
            y = z->parent->parent->left;
            
            // Case 1: 삼촌이 RED
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            // Case 2, 3: 삼촌이 BLACK
            else {
                // Case 2
                if (z == z->parent->left) {
                    z = z->parent;
                    RIGHT_ROTATE(T, z);
                }
                
                // Case 3
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                LEFT_ROTATE(T, z->parent->parent);
            }
        }
    }
    T->root->color = BLACK;
}

/* 레드-블랙 트리에 key 삽입 */
void RB_INSERT(RBTree* T, int key) {
    Node* z = createNode(T, key);
    Node* y = T->nil;
    Node* x = T->root;
    
    // 일반 이진 탐색 트리 삽입 위치 찾기
    while (x != T->nil) {
        y = x;
        
        if (z->key < x->key) {
            x = x->left;
        }
        else {
            x = x->right;
        }
    }
    
    z->parent = y;
    
    if (y == T->nil) {
        T->root = z;              // 트리가 비어 있으면 z가 루트
    }
    else if (z->key < y->key) {
        y->left = z;
    }
    else {
        y->right = z;
    }
    
    z->left = T->nil;
    z->right = T->nil;
    z->color = RED;
    
    RB_INSERT_FIXUP(T, z);
}

/* 중위 순회 출력 */
void inorder(RBTree* T, Node* node) {
    if (node != T->nil) {
        inorder(T, node->left);
        
        printf("%d(%s) ", node->key, 
               node->color == RED ? "RED" : "BLACK");
               
        inorder(T, node->right);
    }
}

/* 테스트 */
int main() {
    RBTree* T = createRBTree();
    
    RB_INSERT(T, 10);
    RB_INSERT(T, 20);
    RB_INSERT(T, 30);
    RB_INSERT(T, 15);
    RB_INSERT(T, 25);
    RB_INSERT(T, 5);
    
    printf("중위 순회 결과:\n");
    inorder(T, T->root);
    
    printf("\n");
    
    return 0;
}