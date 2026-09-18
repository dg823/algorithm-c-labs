#include <stdio.h>

void merge(int h, int m, int U[], int V[], int S[]) {
    int i = 0, j = 0, k = 0;
    while (i < h && j < m) {
        if (U[i] < V[j]) {
            S[k] = U[i];
            i++;
        } else {
            S[k] = V[j];
            j++;
        }
        k++;
    }
    if (i >= h) {
        while (j < m) S[k++] = V[j++];
    } else {
        while (i < h) S[k++] = U[i++];
    }
}

int main() {
    int U[] = { 10, 20, 30 };
    int V[] = { 15, 25, 40 };
    int S[6];

    merge(3, 3, U, V, S);

    printf("병합 결과: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", S[i]);
    }
    printf("\n");

    return 0;
}
