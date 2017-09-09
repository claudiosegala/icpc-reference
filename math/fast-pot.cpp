int fastPot(int x, int exp){
	if(!exp)	return 1;
	if(exp%2)	return x * fastPot(x*x, (exp-1)/2);
	return fastPot(x*x, exp/2);
}