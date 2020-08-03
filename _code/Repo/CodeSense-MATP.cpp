#include<iostream>
#include<cmath>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;
#define N 20

int pascal[N][2*N];

void init() {

	pascal[1][0] = 1;

	for (int i = 2; i < N; i++) {
		pascal[i][0] = i%2 == 1 ? (pascal[i-1][1] * 2):0;

		for (int j = 1; j < min(2*i, 10); j++) {

			if(i % 2 == 1) {
				if (j%2 == 0)
					pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j+1];

			} else {
				if (j%2 == 1)
					pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j+1];
			}
		}
	}

	// for (int i = 0; i < N; i++) {
	// 	for (int j = 0; j < 10; j++) {
	// 		cout << pascal[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

}

void matki(int n) {

	double sum = 0, now, prec_now;
	int ten_pow, denom;

	for (int i = 1; i <= n+1; i++) {
		ten_pow = pow(10, i);
		denom = i == 1 ? 1 : i-1;
		now = (double(pascal[i][1])/denom) * ten_pow;
		prec_now = ((double)((int)(now)) / ten_pow);
		// deb(now);
		// deb(prec_now);
		sum +=  prec_now * 2;
		// deb(sum);
	}

	cout << sum;
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		matki(n);
		cout << endl;
	}

	return 0;
}