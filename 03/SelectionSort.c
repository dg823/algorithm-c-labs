#include <stdio.h>

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int A[], int n) {
    int i, j, minIndex;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (A[minIndex] > A[j])
                minIndex = j;
        }
        if (minIndex != i)
            Swap(&A[i], &A[minIndex]);
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

    SelectionSort(A, n);

    printf("정렬 후: ");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
