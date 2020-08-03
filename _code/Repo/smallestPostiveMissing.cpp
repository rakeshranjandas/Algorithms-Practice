#include<iostream>
using namespace std;

void swap(int* a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int smallestPositive(int a[], int n) {

	int j = -1;

	// Segregate positive and negative numbers
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) {
			// cout << "i " << i << endl;
			swap(a+i, a+j+1);
			j++;
		}
	}

	// cout << j << " <<" << endl;
	// for (int i = 0; i <= j; i++)
	// 	cout << a[i] << " ";
	// cout << endl;

	for (int i = 0; i <= j; i++) {
		if (abs(a[i]) <= j+1 && a[abs(a[i]) - 1] > 0) {
			a[abs(a[i]) - 1] *= -1;
		}
	}

	// for (int i = 0; i <= j; i++)
	// 	cout << a[i] << " ";
	// cout << endl;


	int i;
	for (i = 0; i <= j; i++) {
		if (a[i] > 0)
			break;
	}

	return i+1;
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
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		cout << smallestPositive(a, n) << endl;
	}

	return 0;
}