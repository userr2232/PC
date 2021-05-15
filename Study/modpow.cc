int modpow(int x, int n, int m) {
    if(n == 0) return 1 % m;
    long long u = modpow(x, n/2, m);
    u = (u * u) % m;
    if(n % 2) u = (u * x) % m;
    return u;
}