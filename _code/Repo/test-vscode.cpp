#include <iostream>
using namespace std;

void call(int i, int j) {
    cout << i << endl;

    call(3, 5);

    cout << j << endl;
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

    call(1, 2);

    return 0;
}