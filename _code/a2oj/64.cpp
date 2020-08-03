#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int t, sx, sy, ex, ey;
	cin >> t >> sx >> sy >> ex >> ey;

	int reqN = 0, reqS = 0, reqE = 0, reqW = 0;

	int diffy = ey - sy;
	if (diffy > 0)
		reqN = abs(diffy);
	else
		reqS = abs(diffy);

	int diffx = ex - sx;
	if (diffx > 0)
		reqE = abs(diffx);
	else
		reqW = abs(diffx);

	string wind;
	cin >> wind;

	int cN = 0, cS = 0, cE = 0, cW = 0;
	int res = -1;

	for (int i = 0; i < t; i++) {
		// deb(wind[i]);

		switch(wind[i]) {
			case 'N': cN++;
				break;
			case 'S': cS++;
				break;
			case 'E': cE++; 
				break;
			case 'W': cW++;
				break;
		}

		// deb(cN);
		// deb(cS);
		// deb(cE);
		// deb(cW);

		if (cN >= reqN && cS >= reqS && cE >= reqE && cW >= reqW) {
			res = i+1;
			break;
		}
	}

	cout << res;

	return 0;
}