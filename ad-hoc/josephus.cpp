int f(int n, int k){	// #people, jump size
	return (n == 1) 1 : (f(n-1, k) + k - 1) % n + 1;
}
//--------
int live[MAXN];
void josephus( int n, int m ){ // n people, m-th get killed
	live[1] = 0;
	for( int i = 2; i <= n; i++ )
		live[i] = (live[i-1]+(m%i))%i;
}