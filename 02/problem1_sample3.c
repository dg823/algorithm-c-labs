#include <stdio.h>

int sample3(int A[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += A[i] * A[j];
        }
    }
    return sum;
}

int main() {
    int A[] = {1, 2, 3, 4};
    int n = 4;
    printf("sample3 결과: %d\n", sample3(A, n));
    return 0;
}
