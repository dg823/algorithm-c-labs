#include <stdio.h>

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int A[], int Left, int Right) {
    int PartElem, Value;
    
    PartElem = Left;
    Value = A[Left];

    do {
        do {
            Left++;
        } while (A[Left] < Value);

        do {
            Right--;
        } while (A[Right] > Value);

        if (Left < Right) {
            Swap(&A[Left], &A[Right]);
        } else {
            break;
        }
    } while (1);

    A[PartElem] = A[Right];
    A[Right] = Value;

    return Right;
}

int main() {
    int A[] = { 50, 20, 70, 10, 80, 30, 9999 };
    int n = 7;
    int i, pivotIndex;

    printf("분할 전 배열: ");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    pivotIndex = Partition(A, 0, n - 1);

    printf("분할 후 배열: ");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    printf("pivot의 최종 위치 = %d\n", pivotIndex);
    printf("pivot 값 = %d\n", A[pivotIndex]);

    return 0;
}