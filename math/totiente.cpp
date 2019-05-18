//In number theory, Euler's totient function counts the positive integers up to a 
//given integer n that are relatively prime to n. In other words, it is the number 
//of integers k in the range 1 ≤ k ≤ n for which the greatest common divisor gcd(n, k) 
//is equal to 1.
ll totiente(ll n){
	ll ans = n;
	for(ll i = 2; i*i <= n; i++){
		if(n % i == 0){
			ans = ans / i * (i - 1);
			while(n % i == 0) n /= i;
		}
	}

	if(n > 1) ans = ans / n * (n - 1);
	return ans;
}