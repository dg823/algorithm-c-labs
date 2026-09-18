#include <stdio.h>

void find(int A[], int n, int *min, int *max){
    int small = A[0], large = A[0];
    for(int i = 1; i < n; i++){
        if (small > A[i]){
            small = A[i];
        }
        else if(large < A[i]){
            large = A[i];
        }
    }
    *min = small;
    *max = large;
}



int main() {
    int A[] = { 12, 3, 25, 7, 1, 18 };
    int min, max;
    find(A, 6, &min, &max);
    printf("최소값 = %d\n", min);
    printf("최대값 = %d\n", max);
    return 0;
}