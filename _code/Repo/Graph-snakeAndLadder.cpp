#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define SIZE 31
#define TARGET 30

class Move {
	public:
	int pos, count;

	Move(int x, int c) {
		pos = x;
		count = c;
	}

};

void printLudoVector(vector<int> *ludo) {
	for (int i = 1; i < SIZE; i++) {
		cout << "(" << i << ") ";
		for (auto x: ludo[i])
			cout << x << " ";

		cout << endl;
	}
}

int checkSnakeOrLadder(int x, unordered_map<int, int> snakes_ladders) {
	return snakes_ladders.find(x) == snakes_ladders.end() ? x : snakes_ladders[x];
}

int minMoves(vector<int> *ludo_basic, unordered_map<int, int> snakes_ladders) {

	vector<bool> visited (SIZE, false);

	queue<Move> q;
	q.push(Move(1, 0));
	visited[1] = true;

	int num_moves = -1;
	bool found = false;

	while (!q.empty()) {

		if (found)
			break;

		auto popped = q.front();
		q.pop();

		// cout << popped.pos << " (" << popped.count << ")" << endl;

		for (auto next: ludo_basic[popped.pos]) {

			int x = checkSnakeOrLadder(next, snakes_ladders);

			if (!visited[x]) {

				if (x == TARGET) {
					num_moves = popped.count+1;
					found = true;
					break;
				}

				q.push(Move(x, popped.count+1));
				visited[x] = true;
			}
		}
	}

	return num_moves;
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

	// Initialise basic graph of ludo without
	// snakes and ladders
	vector<int> ludo_basic[SIZE];

	for (int i = 1; i < SIZE; i++)
		for (int j = 1; j <= 6; j++)
			if (i+j < SIZE)
				ludo_basic[i].push_back(i+j);

	// printLudoVector(ludo_basic);

	while (t--) {

		int n;
		cin >> n;

		unordered_map<int, int> snakes_ladders;
		int a, b;

		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			snakes_ladders[a] = b;
		}

		cout << minMoves(ludo_basic, snakes_ladders) << endl;
	}

	return 0;
}