#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* l;
    int key;
    struct node* r;
};

// 트리 초기화
struct node* TreeInit() {
    struct node* head;
    head = (struct node*)malloc(sizeof(struct node));
    head->l = NULL;
    head->r = NULL; // 실제 루트는 head->r
    head->key = 0;
    return head;
}

int main() {
    struct node* head;

    head = TreeInit();

    printf("트리가 초기화되었습니다.\n");
    printf("head->key = %d\n", head->key);

    free(head);
    return 0;
}
