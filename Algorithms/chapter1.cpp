#include <vector>

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
	return true;
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


double ny_hypotenuse(double a, double b) {
	return ny_sqrt(a * a + b * b);
} 




int ny_rank(int key, std::vector<int> &v, int low, int high) {
	if (low > high)
	{
		return -1;
	}

	int mid = low + (high - low / 2);
	if (key < v.at(mid))
	{
		return ny_rank(key, v, low, mid - 1);
	} else if (key > v.at(mid)) {
		return ny_rank(key, v, mid + 1, high);
	} else {
		return mid;
	}
}

int ny_rank(int key, std::vector<int> &v) {
	return ny_rank(key, v, 0, v.size() - 1);
}