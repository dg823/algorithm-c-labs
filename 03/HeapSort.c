#include <stdio.h>

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void MakeHeap(int A[], int Root, int LastNode) {
    int Parent, LeftSon, RightSon, Son, RootValue;
    Parent = Root;
    RootValue = A[Root];
    LeftSon = 2 * Parent + 1;
    RightSon = LeftSon + 1;
    
    while (LeftSon <= LastNode) {
        if (RightSon <= LastNode && A[LeftSon] < A[RightSon])
            Son = RightSon;
        else
            Son = LeftSon;
            
        if (RootValue < A[Son]) {
            A[Parent] = A[Son];
            Parent = Son;
            LeftSon = Parent * 2 + 1;
            RightSon = LeftSon + 1;
        } else {
            break;
        }
    }
    A[Parent] = RootValue;
}

void HeapSort(int A[], int n) {
    int i;
    // 1단계: 배열을 최대 힙으로 만든다.
    for (i = n / 2 - 1; i >= 0; i--) {
        MakeHeap(A, i, n - 1);
    }
    
    // 2단계: 최댓값을 하나씩 꺼내 뒤로 보내며 정렬한다.
    for (i = n - 1; i > 0; i--) {
        Swap(&A[0], &A[i]);
        MakeHeap(A, 0, i - 1);
    }
}

int main() {
    int A[] = { 30, 10, 50, 60, 20, 70, 80 };
    int n = sizeof(A) / sizeof(A[0]);
    int i;

    printf("정렬 전: ");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    HeapSort(A, n);

    printf("정렬 후: ");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
