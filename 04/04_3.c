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

long long prod(long long u, long long v) {
    if (u < 10 || v < 10)
        return u * v;

    int n1 = digits(u);
    int n2 = digits(v);
    int n = (n1 > n2) ? n1 : n2;
    int m = n / 2;

    long long p = pow10(m);

    long long x = u / p;
    long long y = u % p;
    long long w = v / p;
    long long z = v % p;

    long long xw = prod(x, w);
    long long xz = prod(x, z);
    long long wy = prod(w, y);
    long long yz = prod(y, z);

    return xw * pow10(2 * m) + (xz + wy) * pow10(m) + yz;
}

int main() {
    long long u = 1234;
    long long v = 5678;

    long long result = prod(u, v);

    printf("Algorithm 2.9\n");
    printf("%lld * %lld = %lld\n", u, v, result);

    return 0;
}