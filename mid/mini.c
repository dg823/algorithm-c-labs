#include <stdio.h>

int minimum(int A[], int n){
    int temp = 0;
    temp = A[0];
    for(int i = 1; i < n; i++){
        if (temp > A[i]){
            temp = A[i];
        }
    }
    return temp;
}

int main(){
    int A[6] = {10, 3, 25, 7, 1, 8};
    printf("%d", minimum(A, 6));
}