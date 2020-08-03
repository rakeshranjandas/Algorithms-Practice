#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string partition(int a[], int n) {

	long long int prod = 1;
	for (int i = 0; i < n; i++)
		prod *= a[i];

	long long int cur_prod = 1;
	for (int i = 0; i < n; i++) {
		cur_prod *= a[i];

		if (cur_prod == prod/cur_prod && prod % cur_prod == 0)
			return to_string(i+1) + "." + to_string(i+2);
	}

	return "-1";
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	int t;
	cin >> t;
	
	while (t--) {
	    int n, k;
	    cin >> n;
	    
	    int a[n];
	    for (int i = 0; i < n; i++)
	        cin >> a[i];

	    cout << partition(a, n) << endl;
	}
	
	return 0;
}