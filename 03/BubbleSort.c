#include <stdio.h>

#define TRUE 1
#define FALSE 0

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int A[], int n) {
    int i, Sorted;
    Sorted = FALSE;
    while (!Sorted) {
        Sorted = TRUE;
        for (i = 1; i < n; i++) {
            if (A[i - 1] > A[i]) {
                Swap(&A[i - 1], &A[i]);
                Sorted = FALSE;
            }
        }
    }
}

int main() {
    int A[] = { 30, 20, 40, 10, 5, 10, 30, 15 };
    int n = sizeof(A) / sizeof(A[0]);
    int i;

    printf("정렬 전: ");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    BubbleSort(A, n);

    printf("정렬 후: ");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
