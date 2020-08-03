#include<iostream>
#include<limits.h>
#include<string>
using namespace std;

string findCommonElements(int a1[], int n1, int a2[], int n2,
 	int a3[], int n3) {

	int i1 = 0, i2 = 0, i3 = 0;
	int a1Val, a2Val, a3Val, minVal;
	string res = "";

	while (i1 < n1 && i2 < n2 && i3 < n3) {

		minVal = min(a1[i1], min(a2[i2], a3[i3]));
		// cout << "a1Val " << a1[i1] << endl;
		// cout << "minVal " << minVal << endl;

		if (minVal == a1[i1] && minVal == a2[i2] && minVal == a3[i3])
			res += to_string(minVal) + " ";

		while (minVal == a1[i1])
			i1++;

		while (minVal == a2[i2])
			i2++;

		while (minVal == a3[i3])
			i3++;
	}

	return res == "" ? "-1" : res;
}


int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	int t;
	cin >> t;

	while (t--) {
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;

		int a1[n1], a2[n2], a3[n3];

		for (int i = 0; i < n1; i++)
			cin >> a1[i];
		for (int i = 0; i < n2; i++)
			cin >> a2[i];
		for (int i = 0; i < n3; i++)
			cin >> a3[i];

		cout << findCommonElements(a1, n1, a2, n2, a3, n3) << endl;
	}

	return 0;
}