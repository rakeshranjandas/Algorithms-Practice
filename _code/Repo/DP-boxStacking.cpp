#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

struct Box {
	int x, y, z;

	Box(int xx, int yy, int zz) {
		x = xx;
		y = yy;
		z = zz;
	};

	Box() {

	};

	void printBox() {
		cout << "x " << x << ", y " << y << ", z " << z << endl;
	}
};

bool sortByFace(Box a, Box b) {
	return (a.x < b.x);
}

bool canStack(Box a, Box b) {
	return a.x < b.x && a.y < b.y;
}

int maxHeight(Box box[], int n) {

	int b_count = 3*n*2;
	Box b[b_count];
	int b_i = 0;

	for (int i = 0; i < n; i++) {
		b[b_i++] = Box(box[i].x, box[i].y, box[i].z);
		b[b_i++] = Box(box[i].y, box[i].z, box[i].x);
		b[b_i++] = Box(box[i].x, box[i].z, box[i].y);

		b[b_i++] = Box(box[i].y, box[i].x, box[i].z);
		b[b_i++] = Box(box[i].z, box[i].y, box[i].x);
		b[b_i++] = Box(box[i].z, box[i].x, box[i].y);
	}

	sort(b, b+b_count, sortByFace);	

	// for (int i = 0; i < b_count; i++)
	// 	b[i].printBox();

	int dp[b_count];
	for (int i = 0; i < b_count; i++)
		dp[i] = b[i].z;

	for (int j = b_count-1; j > 0; j--)	{
		for (int i = j-1; i >= 0; i--) {
			if (canStack(b[i], b[j]))
				dp[i] = max(dp[i], (b[i].z + dp[j]));
		}
	}

	// for (int i = 0; i < b_count; i++)
	// 	cout << dp[i] << " ";
	// cout << endl;

	int max_height = 0;
	for (int i = 0; i < b_count; i++)
		max_height = max(max_height, dp[i]);

	return max_height;
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

		Box box[n];
		int x, y, z;

		for (int i = 0; i < n; i++) {
			cin >> x >> y >> z;
			box[i] = Box(x, y, z);
		}

		cout << maxHeight(box, n) << endl;
	}

	return 0;
}