#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxSimltaneousDiff(int a[], int n) {

	sort(a, a+n);

	int maxDiff = 0;
	for (int i = 0; i < n-1; i++)
		maxDiff = max(maxDiff, (a[i+1] - a[i]));

	return maxDiff;
}

void printArr(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

// CPP program to find maximum adjacent difference 
// between two adjacent after sorting. 
#include <bits/stdc++.h> 
using namespace std; 

int maxSortedAdjacentDiff(int* arr, int n) 
{ 
	// Find maximum and minimum in arr[] 
	int maxVal = arr[0], minVal = arr[0]; 
	for (int i = 1; i < n; i++) { 
		maxVal = max(maxVal, arr[i]); 
		minVal = min(minVal, arr[i]); 
	} 

	cout << "minVal = " << minVal << ", maxVal = " << maxVal << endl;

	// Arrays to store maximum and minimum values 
	// in n-1 buckets of differences. 
	int maxBucket[n - 1]; 
	int minBucket[n - 1]; 
	fill_n(maxBucket, n - 1, INT_MIN); 
	fill_n(minBucket, n - 1, INT_MAX); 

	// Expected gap for every bucket. 
	float delta = (float)(maxVal - minVal) / (float)(n - 1);
	cout << "expected gap = " << delta << endl;

	cout << "minBucket - ";
	printArr(minBucket, n-1);
	cout << "maxBucket - ";
	printArr(maxBucket, n-1);
	cout << "--------";

	// Traversing through array elements and 
	// filling in appropriate bucket if bucket 
	// is empty. Else updating bucket values. 
	for (int i = 0; i < n; i++) {
		
		cout << "minBucket - ";
		printArr(minBucket, n-1);
		cout << "maxBucket - ";
		printArr(maxBucket, n-1);
		cout << "--------";



		if (arr[i] == maxVal || arr[i] == minVal) 
			continue; 

		// Finding index of bucket. 
		int index = (float)(floor(arr[i] - minVal) / delta); 

		cout << "\nfound Index = " << index << endl;

		// Filling/Updating maximum value of bucket 
		if (maxBucket[index] == INT_MIN) 
			maxBucket[index] = arr[i]; 
		else
			maxBucket[index] = max(maxBucket[index], arr[i]); 

		// Filling/Updating minimum value of bucket 
		if (minBucket[index] == INT_MAX) 
			minBucket[index] = arr[i]; 
		else
			minBucket[index] = min(minBucket[index], arr[i]); 
	} 
	cout << "minBucket - ";
	printArr(minBucket, n-1);
	cout << "maxBucket - ";
	printArr(maxBucket, n-1);
	cout << "--------";
	// Finding maximum difference between maximum value 
	// of previous bucket minus minimum of current bucket. 
	int prev_val = minVal; 
	int max_gap = 0; 
	for (int i = 0; i < n - 1; i++) { 
		if (minBucket[i] == INT_MAX) 
			continue; 
		max_gap = max(max_gap, minBucket[i] - prev_val); 
		prev_val = maxBucket[i]; 
	} 
	max_gap = max(max_gap, maxVal - prev_val); 

	return max_gap; 
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

		// cout << maxSimltaneousDiff(a, n) << endl;
		cout << maxSortedAdjacentDiff(a, n) << endl;
	}

	return 0;
}