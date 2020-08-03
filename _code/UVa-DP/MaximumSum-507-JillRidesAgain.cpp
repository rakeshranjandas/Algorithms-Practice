#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

void maxSumRoute(int a[], int n, int *start, int *end) {
	int max_sum = 0, acc = 0, max_start_ind = 0, max_end_ind = 0, start_ind = 1;

	for (int i = 0; i < n; i++) {
		acc += a[i];

		if (acc >= max_sum) {
			int new_start = start_ind;
			int new_end = i+2;

			if (acc == max_sum) {
				if (*end-*start < new_end-new_start) {
					*start = new_start;
					*end = new_end;						
				}

			} else {
				*start = new_start;
				*end = new_end;	
			}

			max_sum = acc;
		}

		if (acc < 0) {
			acc = 0;
			start_ind = i+2;
		}
	}
}

int main() {

	IOS

	int t;
	cin >> t;

	for (int t_i = 1; t_i <= t; t_i++) {
		int n;
		cin >> n;

		if (n <= 0) {
			cout << "Route " << t_i << " has no nice parts" << endl;
			continue;
		}

		int a[n];
		for (int i = 0; i < n-1; i++)
			cin >> a[i];

		int start = n, end = n;
		maxSumRoute(a, n-1, &start, &end);

		if (start < n)
			cout << "The nicest part of route " << t_i 
				<< " is between stops " << start 
				<< " and " << end << endl;

		else
			cout << "Route " << t_i << " has no nice parts" << endl;
	}

	return 0;
}