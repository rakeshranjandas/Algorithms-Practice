#include<iostream>
#include <iomanip>      // std::setprecision
#include <math.h> 
using namespace std;

double netMagneticForceAt(double pos, int a[], int n) {

	double netForce = 0;

	for (int i = 0; i < n; i++) {
		netForce += 1 / ((double)a[i] - pos);
	}

	if (0 <= fabs(netForce) && fabs(netForce) < 0.0000000000001)
		return 0;

	return netForce;
}

double findMagneticZeroIn(int a[], double lo, double hi, int n) {

	if (fabs(lo - hi) < 0.0000000000001)
			return lo;

	double mid = (lo + hi) / 2;
	double force = netMagneticForceAt(mid, a, n);

	// cout << setprecision(5) << "lo=" << lo << " hi=" << hi
	// 	<< " mid=" << mid << " force=" << force << endl;

	if (force == 0)
		return mid;

	if (force > 0)
		return findMagneticZeroIn(a, lo, mid, n);

	return findMagneticZeroIn(a, mid, hi, n);	
}

void magneticZero(int a[], int n) {

	for (int i = 1; i < n; i++) {
		cout << fixed << setprecision(2) << findMagneticZeroIn(a, a[i-1], a[i], n) << " ";
	}
	cout << endl;
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

		magneticZero(a, n);
	}

	return 0;
}


// 12.89 17.12 22.61 24.87 27.42 28.92 30.54 33.70 36.52 39.67 46.37 53.56 60.98 63.48 66.04 68.53 71.67 76.12 80.55 83.52 86.02 89.64 92.18 93.64 
// 4.15 12.58 14.74 17.23 20.67 22.46 24.08 26.16 28.94 35.02 40.76 48.55 57.83 60.86 64.97 68.81 70.53 73.01 78.15 81.52 84.07 89.82 93.15 96.04 98.40 
