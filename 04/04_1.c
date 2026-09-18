#include <stdio.h>

#define MAX_SIZE 100
int S[MAX_SIZE + 1];
int U[MAX_SIZE + 1];

void merge2(int low, int mid, int high) {
    int i, j, k;

    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high) {
        if (S[i] < S[j]) {
            U[k] = S[i];
            i++;
        } else {
            U[k] = S[j];
            j++;
        }
        k++;
    }

    if (i > mid) {
        while (j <= high) {
            U[k] = S[j];
            j++;
            k++;
        }
    } 
    else {
        while (i <= mid) {
            U[k] = S[i];
            i++;
            k++;
        }
    }

    for (k = low; k <= high; k++) {
        S[k] = U[k];
    }
}

void mergesort2(int low, int high) {
    int mid;

    if (low < high) {
        mid = (low + high) / 2;

        mergesort2(low, mid);

        mergesort2(mid + 1, high);

        merge2(low, mid, high);
    }
}

int main() {
    int n = 8;
    int data[] = {0, 27, 10, 12, 20, 25, 13, 15, 22};

    for (int i = 1; i <= n; i++) {
        S[i] = data[i];
    }

    mergesort2(1, n);

    for (int i = 1; i <= n; i++) {
        printf("%d ", S[i]);
    }

    return 0;
}