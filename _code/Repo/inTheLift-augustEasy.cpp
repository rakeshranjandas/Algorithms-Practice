#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define M 1000000007

long long int power(long long int x, unsigned int y, long long int p) { 
    long long int res = 1;      // Initialize result 

    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p;   
    } 
    return res; 
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	long long int ans = ((power(2, n-k, M) * k) % M) % M;

	cout << ans << "--\n";

	ans += (((power(2, k, M) - (k+1)) %M) + M) % M;
	ans %= M;

	cout << ans << endl;

	return 0;
}