#include <stdio.h>

#define MAX_SIZE 100

int S[MAX_SIZE + 1];

void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void partition(int low, int high, int* pivotpoint)
{
    int i, j;
    int pivotitem;

    pivotitem = S[low];
    j = low;

    for (i = low + 1; i <= high; i++) {
        if (S[i] < pivotitem) {
            j++;
            swap(&S[i], &S[j]);
        }
    }

    *pivotpoint = j;
    swap(&S[low], &S[*pivotpoint]);
}

void quicksort(int low, int high)
{
    int pivotpoint;

    if (high > low) {
        partition(low, high, &pivotpoint);
        quicksort(low, pivotpoint - 1);
        quicksort(pivotpoint + 1, high);
    }
}

int main()
{
    int n, i;

    printf("배열 크기 입력: ");
    scanf_s("%d", &n);

    printf("배열 원소 입력:\n");
    for (i = 1; i <= n; i++) {
        scanf_s("%d", &S[i]);
    }

    quicksort(1, n);

    printf("정렬 결과:\n");
    for (i = 1; i <= n; i++) {
        printf("%5d ", S[i]);
    }
    printf("\n");

    return 0;
}