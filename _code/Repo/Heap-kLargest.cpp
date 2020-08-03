#include<iostream>
using namespace std;

struct heap {
	int *a, last;

	void swap_indices_data(int fi, int si) {
		int temp = a[fi];
		a[fi] = a[si];
		a[si] = temp;
	}

	void max_heapify(int ind, int N) {

		int left_child = 2*ind, right_child = 2*ind+1, largest_ind = ind;

		if (left_child <= N && a[left_child] > a[ind])
			largest_ind = left_child;

		if (right_child <= N && a[right_child] > a[largest_ind])
			largest_ind = right_child;

		if (largest_ind != ind) {
			swap_indices_data(largest_ind, ind);
			max_heapify(largest_ind, N);
		}

	}

	void build_heap() {
		for (int i = last/2; i > 0; i--)
			max_heapify(i, last);

		cout << "heap ";
		for (int i = 1; i <= last; i++)
			cout << a[i] << " ";
		cout << endl;

	}

	heap(int arr[], int n) {
		last = n;
		a = (int *) malloc((n+1) * sizeof(int));

		for (int i = 1; i <= n; i++)
			a[i] = arr[i-1];

		build_heap();
	}

	int pop() {
		int popped = a[1];
		swap_indices_data(1, last);
		last--;
		max_heapify(1, last);
		return popped;
	}
};

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
		int n, k;
		cin >> n >> k;
		
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		heap h = heap(a, n);

		for (int i = 0; i < k; i++)
			cout << h.pop() << " ";

		cout << endl;
	}

	return 0;
}