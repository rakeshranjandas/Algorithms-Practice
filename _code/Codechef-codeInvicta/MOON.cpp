#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FILE_WR freopen("../input.txt", "r", stdin);\
	freopen("../output.txt", "w", stdout);
#define deb(x)	cout << #x << " " << x << endl;

int main() {

	FILE_WR;
	IOS;

	int t;
	cin >> t;

	while (t--) {
		int n, m, x, y;
		cin >> n >> m >> x >> y;

		int tot = n*x + m*y;
		string ans = "NO";

		if (tot%2 == 0) {

			int half_val = tot/2;

			for (int a = 0; a <= n; a++) {
				for (int b = 0; b <= m; b++) {

					if (a*x + b*y == half_val && (n-a)*x + (m-b)*y == half_val) {
						ans = "YES";
						break;
					}
				}

				if (ans == "YES")
					break;
			}
		}

		cout << ans << endl;
	}

	return 0;
}