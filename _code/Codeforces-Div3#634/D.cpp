#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;
#define swap(a, b) char temp = a; a = b; b = temp;

typedef long long int ll;

int main() {

	IOS

	int t;
	cin >> t;

	while (t--) {
		string a[10], s;

		for (int i = 1; i <= 9; i++) {
			cin >> s;
			a[i] = " " + s;
		}	

		int undest_cell_3_1, undest_cell_3_2, undest_cell_3_3;

		//
		if (a[1][1] != a[4][2]) {
			swap(a[1][1], a[4][2]);
			undest_cell_3_1 = 3;

		} else if (a[1][1] != a[4][3]) {
			swap(a[1][1], a[4][3]);
			undest_cell_3_1 = 2;
		}

		//
		if (a[2][4] != a[5][5]) {
			swap(a[2][4], a[5][5]);
			undest_cell_3_2 = 6;

		} else if (a[2][4] != a[5][6]) {
			swap(a[2][4], a[5][6]);
			undest_cell_3_2 = 5;
		}

		//
		if (a[3][7] != a[6][8]) {
			swap(a[3][7], a[6][8]);
			undest_cell_3_3 = 9;

		} else if (a[3][7] != a[6][9]) {
			swap(a[3][7], a[6][9]);
			undest_cell_3_3 = 8;
		}

		int undest_row_3_3;

		if (a[7][undest_cell_3_1] != a[8][undest_cell_3_2]) {
			swap(a[7][undest_cell_3_1], a[8][undest_cell_3_2]);
			undest_row_3_3 = 9;

		} else if (a[7][undest_cell_3_1] != a[9][undest_cell_3_2]) {
			swap(a[7][undest_cell_3_1], a[9][undest_cell_3_2]);
			undest_row_3_3 = 8;
		}

		// Destroy undest_row and undest3,3
		if (a[undest_row_3_3][undest_cell_3_3] == 9)
			a[undest_row_3_3][undest_cell_3_3]--;
		else
			a[undest_row_3_3][undest_cell_3_3]++;

		for (int i = 1; i <= 9; i++) {
			cout << a[i].substr(1) << endl;
		}
	}

	return 0;
}