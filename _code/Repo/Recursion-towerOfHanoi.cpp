#include<iostream>
using namespace std;

int total_moves;

void moveDiscs(int source_rod, int target_rod, int n) {

	// Base case - if there is one disc to move
	if (n == 1) {
		cout << "move disk 1 from rod " 
			<< source_rod << " to rod " 
			<< target_rod << endl;

		total_moves++;
		return;
	}

	// Set aux rod
	int aux_rod = 6 - (source_rod + target_rod);
	

	// Move all but one from below from source to aux
	moveDiscs(source_rod, aux_rod, n-1);

	// Move disc from source to target
	cout << "move disk " << n << " from rod " 
		<< source_rod << " to rod " 
		<< target_rod << endl;

	total_moves++;

	// Move rest from aux to target
	moveDiscs(aux_rod, target_rod, n-1);
}

int numSteps(int n) {
	total_moves = 0;
	moveDiscs(1, 3, n);
	return total_moves;
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

		cout << numSteps(n) << endl;
	}

	return 0;
}