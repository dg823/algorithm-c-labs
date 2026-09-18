#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node* left;
    struct node* right;
    struct node* p;
};

struct node* MakeNode(int key)
{
    struct node* z = (struct node*)malloc(sizeof(struct node));
    z->key = key;
    z->left = NULL;
    z->right = NULL;
    z->p = NULL;
    return z;
}

void TreeInsert(struct node** root, struct node* z)
{
    struct node* y = NULL;
    struct node* x = *root;

    while (x != NULL) {
        y = x;

        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    z->p = y;

    if (y == NULL) {
        *root = z;
    }
    else if (z->key < y->key) {
        y->left = z;
    }
    else {
        y->right = z;
    }
}

void Inorder(struct node* x)
{
    if (x != NULL) {
        Inorder(x->left);
        printf("%d ", x->key);
        Inorder(x->right);
    }
}

int main()
{
    struct node* root = NULL;

    TreeInsert(&root, MakeNode(20));
    TreeInsert(&root, MakeNode(6));
    TreeInsert(&root, MakeNode(2));
    TreeInsert(&root, MakeNode(4));
    TreeInsert(&root, MakeNode(16));
    TreeInsert(&root, MakeNode(10));
    TreeInsert(&root, MakeNode(8));
    TreeInsert(&root, MakeNode(12));
    TreeInsert(&root, MakeNode(14));

    printf("9 삽입 전 중위순회: ");
    Inorder(root);
    printf("\n");

    TreeInsert(&root, MakeNode(9));

    printf("9 삽입 후 중위순회: ");
    Inorder(root);
    printf("\n");

    return 0;
}