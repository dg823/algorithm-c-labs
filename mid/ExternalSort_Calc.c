#include <stdio.h>
#include <math.h>

int calculate_moves(int n, int b, int t) {
    if (t < 4 || t % 2 != 0) {
        printf("균형적 다방향 합병정렬은 최소 4개 이상의 짝수 테이프가 필요합니다.\n");
        return -1;
    }

    double initial_runs = (double)n / b;
    double merge_base = (double)t / 2;
    
    int merge_passes = (int)ceil(log(initial_runs) / log(merge_base));
    
    return merge_passes + 1;
}

int main() {
    int n = 1000, b = 100, t = 4;
    int total_moves = calculate_moves(n, b, t);

    printf("[외부 정렬 조건]\n");
    printf("전체 데이터(n): %d\n", n);
    printf("메모리 크기(b): %d\n", b);
    printf("테이프 수(t): %d\n", t);
    printf("--------------------------\n");
    printf("=> 총 이동 횟수: %d번\n", total_moves);

    return 0;
}
