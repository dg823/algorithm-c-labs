#include <stdio.h>

void FindMinMax(int A[], int n, int *min, int *max) {
    int i, small, large;
    *min = A[0];
    *max = A[0];

    for (i = 1; i < n - 1; i += 2) {
        if (A[i] < A[i + 1]) {
            small = A[i];
            large = A[i + 1];
        } else {
            small = A[i + 1];
            large = A[i];
        }

        if (small < *min) *min = small;
        if (large > *max) *max = large;
    }

    // 배열의 개수가 홀수인 경우 마지막 원소 처리
    if (n % 2 == 1) {
        if (A[n - 1] < *min) *min = A[n - 1];
        else if (A[n - 1] > *max) *max = A[n - 1];
    }
}

int main() {
    int A[] = { 12, 3, 25, 7, 1, 18 };
    int min, max;

    FindMinMax(A, 6, &min, &max);
    printf("최소값 = %d\n", min);
    printf("최대값 = %d\n", max);

    return 0;
}
