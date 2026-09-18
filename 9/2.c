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
        if (xkey == t->key) return;
        else if (xkey < t->key) t = t->l;
        else t = t->r;
    }
    t = (struct node*)malloc(sizeof(struct node));
    t->key = xkey;
    t->l = NULL;
    t->r = NULL;
    if (xkey < p->key) p->l = t;
    else p->r = t;
}

// 이진 탐색 트리에서의 이진 탐색
struct node* TreeSearch(struct node* head, int xkey) {
    struct node* t;
    t = head->r;
    while (t != NULL) {
        if (xkey == t->key) {
            return t; // 키 찾으면
        } else if (xkey < t->key) {
            t = t->l; // 더 작으면 왼쪽 찾음
        } else {
            t = t->r; // 더 크면 오른쪽 찾음
        }
    }
    return NULL;
}

int main() {
    struct node* head = TreeInit();
    struct node* result;

    TreeInsert(head, 20);
    TreeInsert(head, 6);
    TreeInsert(head, 16);

    result = TreeSearch(head, 6);
    if (result != NULL) {
        printf("탐색 성공: %d\n", result->key);
    } else {
        printf("찾는 값이 트리에 없다는 뜻\n");
    }

    result = TreeSearch(head, 100);
    if (result != NULL) {
        printf("탐색 성공: %d\n", result->key);
    } else {
        printf("찾는 값이 트리에 없다는 뜻\n");
    }

    return 0;
}
