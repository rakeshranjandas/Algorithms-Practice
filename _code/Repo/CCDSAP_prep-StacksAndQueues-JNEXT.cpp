#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printAsNum(int a[], int n) {

	for (int i = 0; i < n; i++)
		cout << a[i];
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
		st.push(n-1);
		bool swapped = false;

		for (int i = n-2; i >= 0; i--) {
			if (a[i] >= a[st.top()]) {
				st.push(i);

			} else {

				int swap_pos = 0;

				// find swap pos
				while (!st.empty() && a[st.top()] > a[i]) {
					swap_pos = st.top();
					st.pop();
				}

				// swap
				int temp = a[i];
				a[i] = a[swap_pos];
				a[swap_pos] = temp;

				// Sort
				sort(a+i+1, a+n);

				swapped = true;
				break;
			}
		}

		if (swapped)
			printAsNum(a, n);
		else
			cout << "-1";

		cout << endl;
	}

	return 0;
}