int f(int n, int k){	// Quantidade de pessoas e o tamanho do salto
	return (n == 1) 1 : (f(n-1, k) + k - 1) % n + 1;
}