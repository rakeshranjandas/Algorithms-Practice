#include<iostream>
using namespace std;

long long int inv_count;

void printArray(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

int* copyArray(int a[], int lo, int hi) {

	int* new_arr = (int*) malloc((hi-lo+1) * sizeof(int));

	for (int i = lo, j = 0; i <= hi; i++, j++)
		new_arr[j] = a[i];

	return new_arr;
}

void merge(int a[], int l_lo, int l_hi, int r_lo, int r_hi) {

	// Copy to aux array
	int *l_aux = copyArray(a, l_lo, l_hi);
	int *r_aux = copyArray(a, r_lo, r_hi);

	int i = l_lo;
	int l_aux_size = l_hi-l_lo+1, r_aux_size = r_hi-r_lo+1, l_i = 0, r_i = 0;

	// cout << "l_aux ";
	// printArray(l_aux, l_aux_size);

	// cout << "r_aux ";
	// printArray(r_aux, r_aux_size);

	// Merge to original array
	while (l_i < l_aux_size && r_i < r_aux_size) {

		if (l_aux[l_i] <= r_aux[r_i]) {
			a[i] = l_aux[l_i];
			l_i++;

		} else {
			a[i] = r_aux[r_i];
			r_i++;

			inv_count += (l_aux_size - l_i);
		}

		i++;
	}

	while (l_i < l_aux_size) {
		a[i] = l_aux[l_i];
		l_i++;
		i++;
	}

	while (r_i < r_aux_size) {
		a[i] = r_aux[r_i];
		r_i++;
		i++;
	}
}

void mergeSort(int a[], int lo, int hi) {

	// cout << lo << hi << endl;

	if (lo == hi)
		return;

	int mid = (lo+hi) / 2;

	mergeSort(a, lo, mid);
	mergeSort(a, mid+1, hi);
	merge(a, lo, mid, mid+1, hi);
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

		inv_count = 0;
		mergeSort(a, 0, n-1);

		// cout << "sorted : ";
		// printArray(a, n);

		cout << inv_count << endl;
	}

	return 0;
}