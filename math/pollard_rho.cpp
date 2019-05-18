//Pollard's rho algorithm is an algorithm for integer factorization. It uses only a 
//small amount of space, and its expected running time is proportional to  the square 
//root of the size of the smallest prime factor of the composite number being factorized.

long long pollard_r, pollard_n;

inline long long f(long long val) { return (val*val + pollard_r) % pollard_n; }
inline long long myabs(long long a) { return a >= 0 ? a : -a; }

long long pollard(long long n) {
    srand(unsigned(time(0)));
    pollard_n = n;

    long long d = 1;
    do {
        d = 1;
        pollard_r = rand() % n;

        long long x = 2, y = 2;
        while (d == 1)
            x = f(x), y = f(f(y)), d = __gcd(myabs(x-y), n);
    } while (d == n);

    return d;
}