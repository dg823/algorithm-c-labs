#include <stdio.h>

long long pow10(int m) {
    long long result = 1;
    for (int i = 0; i < m; i++) result *= 10;
    return result;
}

int digits(long long n) {
    int count = 0;
    if (n == 0) return 1;
    while (n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

long long prod2(long long u, long long v) {
    if (u < 10 || v < 10)
        return u * v;

    int n1 = digits(u);
    int n2 = digits(v);
    int n = (n1 > n2) ? n1 : n2;
    int m = n / 2;

    long long p10 = pow10(m);

    long long x = u / p10;
    long long y = u % p10;
    long long w = v / p10;
    long long z = v % p10;

    long long p = prod2(x, w);
    long long q = prod2(y, z);
    long long r = prod2(x + y, w + z);

    return p * pow10(2 * m) + (r - p - q) * pow10(m) + q;
}

int main() {
    long long u = 1234;
    long long v = 5678;

    long long result = prod2(u, v);

    printf("Algorithm 2.10\n");
    printf("%lld * %lld = %lld\n", u, v, result);

    return 0;
}