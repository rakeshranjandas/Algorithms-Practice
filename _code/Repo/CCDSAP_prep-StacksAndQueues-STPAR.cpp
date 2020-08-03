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

	while (true) {
		int n;
		cin >> n;

		if (n == 0)
			break;
		
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int passed = 1;
		bool fault = false;

		stack<int> st;
		int i = 0;

		while (passed <= n || i < n) {

			// cout << passed << " " << a[i] << " x" << endl;

			if (i < n && a[i] == passed) {
				passed++;
				i++;

			} else if (!st.empty() && st.top() == passed) {
				st.pop();
				passed++;

			} else if (i < n && st.empty())
				st.push(a[i++]);

			else if (i < n && st.top() > a[i]) 
				st.push(a[i++]);

			else {
				fault = true;
				break;
			}
		}

		cout << (fault ? "no" : "yes") << endl;
	}


	return 0;
}