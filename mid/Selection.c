#include <stdio.h>
#include <limits.h>

#define Infinity INT_MAX

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int A[], int Left, int Right) {
    int PartElem, Value;
    PartElem = Left;
    Value = A[PartElem];

    int i = Left;
    int j = Right;

    while (1) {
        do { i++; } while (i < Right && A[i] < Value);
        do { j--; } while (j > Left && A[j] > Value);

        if (i < j) Swap(&A[i], &A[j]);
        else break;
    }
    
    A[PartElem] = A[j];
    A[j] = Value;
    return j;
}

int Selection_N2(int A[], int n, int i) {
    int Left = 0, Right = n;
    int j;
    A[n] = Infinity;

    while (1) {
        j = Partition(A, Left, Right);
        if (i == j + 1) return A[j];
        if (i < j + 1) Right = j;
        else Left = j + 1;
    }
}

int main() {
    int A[20] = { 40, 10, 70, 30, 20, 60, 50 };
    int n = 7;
    int i, result;

    printf("배열: ");
    for (int k = 0; k < n; k++) {
        printf("%d ", A[k]);
    }
    printf("\n");

    printf("찾고 싶은 순위(i)를 입력하세요: ");
    scanf("%d", &i);

    result = Selection_N2(A, n, i);
    printf("%d번째 작은 수는 %d입니다.\n", i, result);

    return 0;
}
