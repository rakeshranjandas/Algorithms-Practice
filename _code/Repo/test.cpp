#include <iostream>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl; 

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	int x = 2;

	deb(x);
}
