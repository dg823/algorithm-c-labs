#include <stdio.h>

int Minimum(int A[], int n) {
    int i, temp;
    temp = A[0];
    for (i = 1; i < n; i++) {
        if (temp > A[i]) {
            temp = A[i];
        }
    }
    return temp;
}

int main() {
    int A[6] = { 10, 3, 25, 7, 1, 8 };
    printf("최소값: %d\n", Minimum(A, 6));
    return 0;
}
