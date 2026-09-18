#include <stdio.h>
#include <stdlib.h>

void merge(int h, int m, int U[], int V[], int S[]) {
    int i = 0, j = 0, k = 0;
    while (i < h && j < m) {
        if (U[i] < V[j]) S[k++] = U[i++];
        else S[k++] = V[j++];
    }
    while (i < h) S[k++] = U[i++];
    while (j < m) S[k++] = V[j++];
}

void mergesort(int n, int S[]) {
    if (n > 1) {
        int h = n / 2;
        int m = n - h;
        int *U = (int *)malloc(sizeof(int) * h);
        int *V = (int *)malloc(sizeof(int) * m);

        for (int i = 0; i < h; i++) U[i] = S[i];
        for (int i = 0; i < m; i++) V[i] = S[h + i];

        mergesort(h, U);
        mergesort(m, V);
        merge(h, m, U, V, S);

        free(U);
        free(V);
    }
}

int main() {
    int A[] = { 27, 10, 12, 20, 25, 13, 15, 22 };
    int n = sizeof(A) / sizeof(A[0]);

    printf("정렬 전: ");
    for (int i = 0; i < n; i++) printf("%d ", A[i]);
    printf("\n");

    mergesort(n, A);

    printf("정렬 후: ");
    for (int i = 0; i < n; i++) printf("%d ", A[i]);
    printf("\n");

    return 0;
}
