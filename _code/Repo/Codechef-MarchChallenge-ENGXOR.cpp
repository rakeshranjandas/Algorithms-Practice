#include<iostream>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;
#define N 100000001
// #define N 101

bool has_even_ones[N];

void recursiveStore(int cur_num, int cur_val) {

	int new_num = cur_num << 1;

	if (new_num >= N)
		return;

	has_even_ones[new_num] = cur_val;
	recursiveStore(new_num, cur_val);

	has_even_ones[new_num | 1] = !cur_val;
	recursiveStore(new_num | 1, !cur_val);
}

void initDP() {
	has_even_ones[0] = true;
	has_even_ones[1] = false;
	recursiveStore(1, 0);

	for (int i = 0; i < N; i++)
		cout << i << " " << has_even_ones[i] << endl;


}

bool hasEvenZeros(int n) {

	return has_even_ones[n];

	int c_1 = 0;

	while (n > 0) {
		if (n & 1)
			c_1++;

		n = n/2;
	}

	return c_1 % 2 == 0;
}

void engXor(int a[], int n, int p) {

	int c = 0;
	for (int i = 0; i < n; i++)
		if (hasEvenZeros(p ^ a[i]))
			c++;

	cout << c << " " << n-c;
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

	initDP();

	while (t--) {
		int n, q;
		cin >> n >> q;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int p;
		for (int i = 0; i < q; i++) {
			cin >> p;
			engXor(a, n, p);
			cout << endl;
		}
	}

	return 0;
}