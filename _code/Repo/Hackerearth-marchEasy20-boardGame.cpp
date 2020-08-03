#include<iostream>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;
#define MOD 1000000007

long long int power(long long int x, long long int y, long long int p)  
{  
    long long int res = 1;     // Initialize result  
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) % p;  
  
        // y must be even now  
        y = y/2;
        x = (x*x) % p;  
    }

    return res;  
} 

long long int twoPower(long long int k) {

	return power(2, k, MOD);

	long long int res = 1;
	for (int i = 0; i < k; i++) {
		res = (res << 1) % MOD;
	}

	return res;
}

long long int ways(long long int n) {

	if (n <= 1)
		return 0;

	if (n%2 == 0)
		return 0;

	long long int k = n/2;
	return twoPower(k-1);
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		long long int n;
		cin >> n;

		cout << ways(n) << endl;
	}

	return 0;
}