#include <stdio.h>

int sample4(int A[], int n) {
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            sum += A[i] * A[j];
        }
    }
    return sum;
}

int main() {
    int A[] = {1, 2, 3, 4};
    int n = 4;
    printf("sample4결과=%d\n", sample4(A, n));
    return 0;
}
