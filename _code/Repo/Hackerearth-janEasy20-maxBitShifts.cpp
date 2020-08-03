#include<iostream>
#include<cmath>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

long long int maxSeq(long long int n) {
    
    while (n > 0) {
        if (n&1)
            ones_count++;
            
        n /= 2;
        
        max_k++;
    }

	// deb(ones_count);
	// deb(max_k);
	// deb(max_k-ones_count+1);

	long long int num = 0;
	for (int i = 0; i < ones_count; i++)
		num = (num << 1) | 1;

	num = num << (max_k-ones_count+1);

	return num;
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	long long int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++)
		cout << maxSeq(a[i]) << " ";

	cout << endl;

	return 0;
}