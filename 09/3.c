#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* l;
    int key;
    struct node* r;
};

struct node* TreeInit() {
    struct node* head;
    head = (struct node*)malloc(sizeof(struct node));
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

    if (p == head || xkey < p->key) {
        if (p == head) p->r = t;
        else p->l = t;
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

void TreeDel(struct node* head, int xkey) {
    struct node *p, *t;
    struct node *c, *x;
    p = head;
    t = head->r;

    while (t != NULL && t->key != xkey) {
        p = t;
        if (xkey < t->key) {
            t = t->l;
        }
        else {
            t = t->r;
        }
    }

    if (t == NULL) {
        printf("%d는 트리에 없습니다.\n", xkey);
        return;
    }

    if (t->r == NULL) {
        x = t->l;
        printf("삭제 경우 (1): 오른쪽 자식이 없는 경우\n");
    }
    else if (t->r->l == NULL) {
        x = t->r;
        x->l = t->l;
        printf("삭제 경우 (2): 오른쪽 자식은 있으나 그 오른쪽 자식의 왼쪽 자식이 없는 경우\n");
    }
    else {
        c = t->r;
        while (c->l->l != NULL) {
            c = c->l;
        }
        x = c->l;
        c->l = x->r;
        x->l = t->l;
        x->r = t->r;
        printf("삭제 경우 (3): 오른쪽 부분트리에서 가장 작은 값을 올리는 경우\n");
    }

    if (p->l == t) {
        p->l = x;
    }
    else {
        p->r = x;
    }

    free(t);
    printf("%d 삭제 완료\n", xkey);
}

int main() {
    struct node* head;
    int delKey;

    head = TreeInit();

    TreeInsert(head, 20);
    TreeInsert(head, 6);
    TreeInsert(head, 2);
    TreeInsert(head, 4);
    TreeInsert(head, 16);
    TreeInsert(head, 10);
    TreeInsert(head, 8);
    TreeInsert(head, 9);
    TreeInsert(head, 12);
    TreeInsert(head, 14);

    printf("삭제 전 중위 순회: ");
    Inorder(head->r);
    printf("\n");

    printf("삭제할 숫자를 입력하세요: ");
    scanf_s("%d", &delKey);

    TreeDel(head, delKey);

    printf("삭제 후 중위 순회: ");
    Inorder(head->r);
    printf("\n");

    return 0;
}