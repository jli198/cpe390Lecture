void sum(int n) {
	int sum = 0;
	for(int i = 1; i <= n; i++)
		sum = sum + i;
	//what is sum(1..n) = n?
	//1 2 3 4 5 6 7 ... (n-1) (n)
	//n (n-1) (n-2) ... 2 1
	//---------------------------
	//n+1 n+1+ ... n+1 n+1
	//return n * n(n+1)/2
	return sum;



