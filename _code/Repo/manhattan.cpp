// Round 1B 2019 - Google Code Jam 2019

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	int t;
	cin >> t;

	while (t--) {
		int p, q;
		cin >> p >> q;

		int x, y;
		char d;
		int minX = 0, minY = 0, maxX = q, maxY = q;

		vector<map<string, int>> v;
		map<string, int> m;
		m["minX"] = 0;
		m["minY"] = 0;
		m["maxX"] = q;
		m["maxY"] = q;
		m["count"] = 0;

		bool noRegion;	// If a person could not find any existing region

		for (int i = 0; i < p; i++) {
			cin >> x >> y >> d;


			noRegion = true;

			for (int j = 0; j < v.size(); j++) {

				// Conditions when person is going to another region
				if (d == 'N' && v[i].maxY <= y)
					continue;
				if (d == 'E' && v[i].maxX <= x)
					continue;
				if (d == 'S' && v[i].minY >= y)
					continue;
				if (d == 'W' && v[i].minX >= x)
					continue;


				// if person is in existing region
				// then update the region
				noRegion = false;


			}

			// Check if x y d are heading to that region
			// If a person could not find any existing region
			// then create own region
			if (noRegion) {

			}







			// switch(d) {
			// 	case 'N':
			// 		minY = max(minY, y+1);
			// 		cout << "minY " << endl;
			// 		break;

			// 	case 'E':
			// 		minX = max(minX, x+1);
			// 		cout << "minX " << endl;
			// 		break;

			// 	case 'W':
			// 		maxX = min(maxX, x-1);
			// 		cout << "maxX " << endl;
			// 		break;

			// 	case 'S':
			// 		maxY = min(maxY, y-1);
			// 		cout << "maxY " << endl;
			// 		break;
			// }

			// cout << x << " " << y << " " << d <<endl;
			// cout << minX << " " << minY << " " << maxX << " " << maxY << endl;
		}

		// cout << minX << " " << minY << endl;
	}

	return 0;
}