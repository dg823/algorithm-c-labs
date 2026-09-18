#include <stdio.h>

int S[] = { 0, 10, 12, 13, 14, 18, 20, 25, 27, 30, 35, 40, 45, 47 };
int x = 18;

int location(int low, int high) {
    int mid;
    if (low > high)
        return -1;
    else {
        mid = (low + high) / 2;
        if (x == S[mid])
            return mid;
        else if (x < S[mid])
            return location(low, mid - 1);
        else
            return location(mid + 1, high);
    }
}

int main() {
    int n = sizeof(S) / sizeof(S[0]);
    int loc = location(0, n - 1);
    
    if (loc != -1)
        printf("x=%d 는 배열의 %d번째 위치에 있습니다.\n", x, loc);
    else
        printf("x=%d 를 찾을 수 없습니다.\n", x);
    
    return 0;
}
