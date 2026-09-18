#include <stdio.h>
#include <stdlib.h>

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 작은 배열(크기 5 이하)을 정렬하여 중간값을 반환하는 함수
int get_median(int A[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] > A[j]) Swap(&A[i], &A[j]);
        }
    }
    return A[n / 2];
}

// 특정 값을 기준으로 파티션을 수행하는 함수
int partition_with_pivot(int A[], int left, int right, int pivot) {
    int i;
    for (i = left; i < right; i++) {
        if (A[i] == pivot) break;
    }
    Swap(&A[i], &A[right]); // 피벗을 맨 뒤로 보냄

    int store_index = left;
    for (i = left; i < right; i++) {
        if (A[i] < pivot) {
            Swap(&A[i], &A[store_index]);
            store_index++;
        }
    }
    Swap(&A[store_index], &A[right]);
    return store_index;
}

// O(n)을 보장하는 SELECT 알고리즘
int SELECT(int A[], int left, int right, int i) {
    int n = right - left + 1;

    // 단계 1: 원소 수가 5 이하이면 직접 정렬해서 답을 찾음
    if (n <= 5) {
        for (int p = left; p <= right; p++) {
            for (int q = p + 1; q <= right; q++) {
                if (A[p] > A[q]) Swap(&A[p], &A[q]);
            }
        }
        return A[left + i - 1];
    }

    // 단계 2 & 3: 5개씩 묶어 중간값들을 찾음
    int num_groups = (n + 4) / 5;
    int *medians = (int *)malloc(num_groups * sizeof(int));
    for (int g = 0; p < num_groups; g++) {
        int group_left = left + g * 5;
        int group_right = group_left + 4;
        if (group_right > right) group_right = right;
        medians[g] = get_median(&A[group_left], group_right - group_left + 1);
    }

    // 단계 4: 중간값들의 중간값 p를 재귀적으로 구함
    int pivot = SELECT(medians, 0, num_groups - 1, (num_groups + 1) / 2);
    free(medians);

    // 단계 5: p를 피벗으로 하여 파티션
    int j = partition_with_pivot(A, left, right, pivot);
    int k = j - left + 1; // 피벗의 순위

    // 단계 6: 순위 비교 후 재귀 호출
    if (i == k) return A[j];
    else if (i < k) return SELECT(A, left, j - 1, i);
    else return SELECT(A, j + 1, right, i - k);
}

int main() {
    int A[] = { 25, 7, 18, 3, 40, 12, 30, 1, 22, 15, 9, 27, 35, 5, 11 };
    int n = 15;
    int i = 4; // 4번째로 작은 수 찾기

    printf("배열: ");
    for (int k = 0; k < n; k++) printf("%d ", A[k]);
    printf("\n");

    int result = SELECT(A, 0, n - 1, i);
    printf("%d번째 작은 수는 %d입니다.\n", i, result);

    return 0;
}
