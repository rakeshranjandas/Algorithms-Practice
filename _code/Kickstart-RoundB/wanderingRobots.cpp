#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

bool isHole(int i, int j, int l, int u, int r, int d) {
	return i >= u-1 && i <= d-1 && j >= l-1 && j <= r-1;
}

bool valid(int i, int j, int w, int h) {
	return i >= 0 && i < h && j >= 0 && j < w;
}

bool last(int i, int j, int w, int h) {
	return i == h-1 || j == w-1; 
}

double prob(int w, int h, int l, int u, int r, int d) {
	double p[h][w] = {0};

	int hole_count = 0;


	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {

			p[i][j] = 0;
			// cout << p[i][j] << " ";
		}
		// cout << endl;
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (isHole(i, j, l, u, r, d))
				continue;

			if (i == 0 && j == 0) {
				// a[i][j] = 1;
				p[i][j] = 1;

			} else {
				int ways = 0;
				double this_prob = 0;

				if (valid(i-1, j, w, h)) {
					// ways += a[i-1][j];

					if (last(i-1, j, w, h))
						this_prob += p[i-1][j];

					else
						this_prob += p[i-1][j] * 0.5;
				}


				if (valid(i, j-1, w, h)) {
					// ways += a[i][j-1];

					if (last(i, j-1, w, h))
						this_prob += p[i][j-1];
					else
						this_prob += p[i][j-1] * 0.5;
				}

				// a[i][j] = ways;
				p[i][j] = this_prob;
				
				// deb(valid(i-1, j, w, h));
				// deb(valid(i, j-1, w, h));
				// cout << "a " << i << " " << j << " = "<< ways << endl;
			}

			if (valid(i+1, j, w, h) && isHole(i+1, j, l, u, r, d))
				hole_count++;

			if (valid(i, j+1, w, h) && isHole(i, j+1, l, u, r, d))
				hole_count++;
		}
	}

	// deb(a[h-1][w-1]);

	// for (int i = 0; i < h; i++) {
	// 	for (int j = 0; j < w; j++) {
	// 		cout << a[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	// for (int i = 0; i < h; i++) {
	// 	for (int j = 0; j < w; j++) {
	// 		cout << p[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	// deb(hole_count);

	return p[h-1][w-1];
}

int main() {

	IOS

	int t;
	cin >> t;

	for (int t_i = 1; t_i <= t; t_i++) {
		int w, h, l, u, r, d;
		cin >> w >> h >> l >> u >> r >> d;

		cout << "Case #" << t_i << ": " << setprecision(5) << prob(w, h, l, u, r, d) << endl;
	}

	return 0;
}