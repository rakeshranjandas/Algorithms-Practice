#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	vector<vector<int>> a(3, vector<int> (3,1));
	int ip;
	int dx[5] = {0, 0, 0, 1, -1};
	int dy[5] = {0, 1, -1, 0, 0};

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> ip;

			if (ip%2 == 1) {
				for (int k = 0; k < 5; k++) {
					int x = i+dx[k];
					int y = j+dy[k];

					if (x >= 0 && x < 3 && y >= 0 && y < 3)
						a[x][y] = !a[x][y];
				}	
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			cout << a[i][j];
		cout << endl;
	}


	return 0;
}