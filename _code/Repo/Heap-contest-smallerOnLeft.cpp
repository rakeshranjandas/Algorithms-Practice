#include<iostream>
#include<bits/stdc++.h>
using namespace std;

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

		int x;

		priority_queue<int> max_heap;
		priority_queue<int, vector<int>, greater<int>> min_heap;
		int sizeMaxHeap;

		for (int i = 0; i < n; i++) {
			cin >> x;

			if (min_heap.size() == 0)
				min_heap.push(x);

			else {

				while (min_heap.size() > 0 && x > min_heap.top()) {
					max_heap.push(min_heap.top());
					min_heap.pop();
				}

				while (max_heap.size() > 0 && x < max_heap.top()) {
					min_heap.push(max_heap.top());
					max_heap.pop();
				}

				min_heap.push(x);
			}

			sizeMaxHeap = max_heap.size();

			cout << (sizeMaxHeap == 0 ? -1 : sizeMaxHeap)<< " ";
		}

		cout << endl;
	}

	return 0;
}



