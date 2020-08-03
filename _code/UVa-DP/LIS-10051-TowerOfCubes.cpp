#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;
typedef vector<vector<int>> vvi;
typedef vector<vector<pair<int, int>>> vvpi;
enum Orientation {FRONT, BACK, LEFT, RIGHT, TOP, BOTTOM};

class Cubes {
	public:
	int dim[6];
	
	Cubes(int d[]) {
		for (int i = 0; i < 6; i++)
			dim[i] = d[i];
	}
};

void printCube(Cubes c) {
	for (int i = 0; i < 6; i++)
		cout << c.dim[i] << " ";
	cout << endl;
}

void printVVI(vvi &v) {
	for (auto x: v) {
		for (auto y: x)
			cout << y << " ";
		cout << endl;
	}
}

int findBottomDim(int d) {
	int bottom_d;
	switch(d) {
		case FRONT: bottom_d = BACK; break;
		case BACK: bottom_d = FRONT; break;
		case LEFT: bottom_d = RIGHT; break;
		case RIGHT: bottom_d = LEFT; break;
		case TOP: bottom_d = BOTTOM; break;
		case BOTTOM: bottom_d = TOP; break;
	}

	return bottom_d;
}

int findBottomColor(Cubes c, int d) {
	return c.dim[findBottomDim(d)];
}

string findOrientation(int d) {
	string orn;
	switch(d) {
		case FRONT: orn = "front"; break;
		case BACK: orn = "back"; break;
		case LEFT: orn = "left"; break;
		case RIGHT: orn = "right"; break;
		case TOP: orn = "top"; break;
		case BOTTOM: orn = "bottom"; break;
	}

	return orn;
}

string resForCube(int x, int y) {
	return to_string(x+1) + " " + findOrientation(y);
}

void LIS(vector<Cubes> &v, int test_case) {

	// for (auto x: v)
	// 	printCube(x);

	int n = v.size();
	vvi dp(n, vector<int>(6, 1));
	vvpi par(n, vector<pair<int, int>>(6, {-1, -1}));

	int lis_len = 1, lis_x = 0, lis_y = 0;

	for (int j = 1; j < n; j++) {
		for (int i = 0; i < j; i++) {
			// tryCubes(v[j], v[i], dp, par, &lis_len, &lis_x, &lis_y);

			for (int dj = 0; dj < 6; dj++) {

				for (int di = 0; di < 6; di++) {
					int color_bottom = findBottomColor(v[i], di);

					if (color_bottom == v[j].dim[dj]) {

						if (dp[j][dj] < dp[i][di] + 1) {
							dp[j][dj] = dp[i][di] + 1;
							par[j][dj] = {i, di};

							if (lis_len <= dp[j][dj]) {
								lis_len = dp[j][dj];
								lis_x = j, lis_y = dj;
							}
						}
					}
				}
			}
		}
	}

	// printVVI(dp);

	// print solution
	cout << "Case #" << test_case << endl;
	cout << lis_len << endl;

	string res = "";
	// deb(lis_x); deb(lis_y);
		
	while (lis_x != -1 && lis_y != -1) {
		res = resForCube(lis_x, lis_y) + "\n" + res;
		auto par_p = par[lis_x][lis_y];
		lis_x = par_p.first, lis_y = par_p.second;
		// deb(lis_x); deb(lis_y);
	}
	cout << res;
}

int main() {

	IOS

	int n, test_case = 1;
	while (true) {
		if(!(cin >> n))
			continue;

		if (n == 0)
			break;

		vector<Cubes> v;
		int d[6];

		for (int t_i = 1; t_i <= n; t_i++) {
			for (int i = 0; i < 6; i++)
				cin >> d[i];

			v.push_back(Cubes(d));
		}

		if (test_case > 1)
			cout << endl;
		LIS(v, test_case++);

	}

	return 0;
}