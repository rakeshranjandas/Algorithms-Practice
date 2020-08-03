#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printLeaf(int a[], int l, int h, stack<int> &st) {

	if (l > h)
		return;



	// if (l == h) {
	// 	// cout << a[l] << " ";
	// 	// st.push(a[l]);
	// 	return;
	// }

	// root is a[l]
	// l+1 is left child
	// first bigger number is right child

	int ri = h+1;
	for (int i = l+1; i <= h; i++) {
		if (a[i] > a[l]) {
			ri = i;
			break;
		}
	}

	
	printLeaf(a, l+1, ri-1, st);
	printLeaf(a, ri, h, st);

	cout << a[l] << " ";
	
}

void printStack(stack<int> st) {
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
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
		int n;
		cin >> n;
		
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		stack<int> st;
		printLeaf(a, 0, n-1, st);
		printStack(st);
		cout << endl;
	}

	return 0;
}