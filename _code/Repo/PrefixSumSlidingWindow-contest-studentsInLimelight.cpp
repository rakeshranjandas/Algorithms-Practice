#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void pushDecreasing(deque<int> &dq, int a[], int i) {

	while (!dq.empty() && a[dq.back()] <= a[i])
		dq.pop_back();

	dq.push_back(i);
}

string limelight(int a[], int n, int k) {

	deque<int> dq;
	string res = "";

	for (int i = 0; i < k; i++)
		pushDecreasing(dq, a, i);

	res += to_string(a[dq.front()]) + " ";

	for (int i = k; i < n; i++) {
		while (dq.front() <= i-k)
			dq.pop_front();

		pushDecreasing(dq, a, i);
		res += to_string(a[dq.front()]) + " ";
	}

	return res;
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
	    cin >> n >> k;
	    
	    int a[n];
	    for (int i = 0; i < n; i++)
	        cin >> a[i];

	    cout << limelight(a, n, k) << endl;
	}
	
	return 0;
}