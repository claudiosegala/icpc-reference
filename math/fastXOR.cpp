// XOR(A, B) = XOR(0, A-1) ^ XOR(0, B)
ll fastXor(ll n) {
    switch (n % 4) {
        case 0: return n;
        case 1: return 1;
        case 2: return n+1;
        case 3: return 0;
    }
}