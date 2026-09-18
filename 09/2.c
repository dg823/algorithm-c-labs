#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* l;
    int key;
    struct node* r;
};

struct node* TreeInit() {
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->l = NULL;
    head->r = NULL;
    head->key = 0;
    return head;
}

void TreeInsert(struct node* head, int xkey) {
    struct node *p, *t;
    p = head;
    t = head->r;
    
    while (t != NULL) {
        p = t;
        if (xkey == t->key) {
            printf("%d는 이미 존재합니다.\n", xkey);
            return;
        }
        else if (xkey < t->key) {
            t = t->l;
        }
        else {
            t = t->r;
        }
    }
    
    t = (struct node*)malloc(sizeof(struct node));
    t->key = xkey;
    t->l = NULL;
    t->r = NULL;
    
    if (xkey < p->key) {
        p->l = t;
    }
    else {
        p->r = t;
    }
}

void Inorder(struct node* t) {
    if (t != NULL) {
        Inorder(t->l);
        printf("%d ", t->key);
        Inorder(t->r);
    }
}

int main() {
    struct node* head = TreeInit();

    TreeInsert(head, 20);
    TreeInsert(head, 6);
    TreeInsert(head, 2);
    TreeInsert(head, 4);
    TreeInsert(head, 16);
    TreeInsert(head, 10);
    TreeInsert(head, 8);
    TreeInsert(head, 12);
    TreeInsert(head, 14);

    printf("9 삽입 전 중위 순회: ");
    Inorder(head->r);
    printf("\n");

    TreeInsert(head, 9);

    printf("9 삽입 후 중위 순회: ");
    Inorder(head->r);
    printf("\n");

    return 0;
}