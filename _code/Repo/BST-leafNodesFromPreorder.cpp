#include<iostream>
using namespace std;



void printLeaf(int a[], int l, int h) {

	if (l > h)
		return;

	if (l == h) {
		cout << a[l] << " ";
		return;
	}

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

	// if (ri == h+1) {
	// 	// then it has no right child
	// 	printLeaf(a, l+1, h);

	// } else if (ri == l+1) {
	// 	// then it has no left child
	// 	printLeaf(a, l+1, h);

	// } else {
	// 	printLeaf(a, l+1, ri-1);
	// 	printLeaf(a, ri, h);
	// }

	printLeaf(a, l+1, ri-1);
	printLeaf(a, ri, h);
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

		printLeaf(a, 0, n-1);
		cout << endl;
	}

	return 0;
}