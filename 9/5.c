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
    struct node* p, * t;
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

void Inorder(struct node* t) {
    if (t != NULL) {
        Inorder(t->l);
        printf("%d ", t->key);
        Inorder(t->r);
    }
}

// 이진 탐색 나무 삭제 함수
void TreeDel(struct node* head, int xkey) {
    struct node* p, * t;
    struct node* c, * x;
    p = head;
    t = head->r;
    
    // 삭제할 노드 t와 부모 노드 p 찾기
    while (t != NULL && t->key != xkey) {
        p = t;
        if (xkey < t->key) {
            t = t->l;
        } else {
            t = t->r;
        }
    }
    
    // 삭제할 값이 없는 경우
    if (t == NULL) {
        printf("%d는 트리에 없습니다.\n", xkey);
        return;
    }
    
    // (1) 삭제할 노드의 오른쪽 자식이 없는 경우
    if (t->r == NULL) {
        x = t->l;
        printf("삭제 경우 (1): 오른쪽 자식이 없는 경우\n");
    }
    // (2) 오른쪽 자식은 있지만, 오른쪽 자식의 왼쪽 자식이 없는 경우
    else if (t->r->l == NULL) {
        x = t->r;
        x->l = t->l;
        printf("삭제 경우 (2): 오른쪽 자식은 있으나 그 오른쪽 자식의 왼쪽 자식이 없는 경우\n");
    }
    // (3) 그 외 나머지 경우
    else {
        c = t->r;
        // 오른쪽 부분트리에서 가장 작은 노드의 부모 찾기
        while (c->l->l != NULL) {
            c = c->l;
        }
        x = c->l; // x는 오른쪽 부분트리에서 가장 작은 노드
        c->l = x->r; // x의 오른쪽 자식을 x의 부모 왼쪽에 연결
        x->l = t->l; // x가 삭제 노드의 왼쪽 자식 연결
        x->r = t->r; // x가 삭제 노드의 오른쪽 자식 연결
        printf("삭제 경우 (3): 오른쪽 부분트리에서 가장 작은 값을 올리는 경우\n");
    }
    
    // 부모 노드 p가 삭제할 노드 t 대신 x를 가리키도록 연결
    if (p->l == t) {
        p->l = x;
    } else {
        p->r = x;
    }
    
    free(t);
    printf("%d 삭제 완료\n", xkey);
}

int main() {
    struct node* head;
    int delKey;

    head = TreeInit();

    // 그림의 트리 생성
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
