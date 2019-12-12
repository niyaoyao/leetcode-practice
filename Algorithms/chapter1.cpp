// chapter1.cpp
int gcd(int p, int q) {
	if (q == 0)
	{
		return p;
	} else {
		int r = p % q;
		return gcd(q, r);
	}
}

bool isPrime (int n) {
	if (n < 2) {
		return false;
	}
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0) 
		{
			return false;
		}

		return true;
	}
}

double ny_abs(double x) {
	if (x < 0.0)
	{
		return -x;
	} else {
		return x;
	}
}

double ny_sqrt(double c) {
	if (c < 0)
	{
		return -1/0;
	} 
	double error = 0.000000000000001;
	double t = c;
	while (ny_abs(t - c/t) > error * t) 
		t = (c/t + t) / 2.0;
	return t;
}