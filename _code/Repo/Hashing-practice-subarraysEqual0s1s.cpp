#include<iostream>
#include<cstring>
using namespace std;

int *zeroCount, *oneCount;

int equalOs1s(int a[], int n) {

	zeroCount = (int *) calloc(n+1, sizeof(int));
	oneCount = (int *) calloc(n+1, sizeof(int));

	for (int i = 0; i < n; i++) {
		zeroCount[i+1] = zeroCount[i] + (a[i] == 0 ? 1 : 0);
		oneCount[i+1] = oneCount[i] + (a[i] == 1 ? 1 : 0);
	}

	cout << "zeroCount : ";
	for (int i = 0; i < n+1; i++)
		cout << zeroCount[i] << " ";
	cout << endl;

	cout << "oneCount : ";
	for (int i = 0; i < n+1; i++)
		cout << oneCount[i] << " ";
	cout << endl;

	int c = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n+1; j++) {
			if (zeroCount[j] - zeroCount[i] == oneCount[j] - oneCount[i])
				c++;
		}
	}

	return c;
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

		cout << equalOs1s(a, n) << endl;
	}

	return 0;
}