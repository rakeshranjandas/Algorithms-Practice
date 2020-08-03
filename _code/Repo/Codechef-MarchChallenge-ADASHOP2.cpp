#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

bool checkIfStandard(int r, int c) {

	// if r,c is black then return true, else false;
	// 1, 1 is black
	// manhattan distance if odd then is a black cell (return )

	return (r-1 + c-1 + 1) % 2 == 0
		? false
		: true;
}

void translate(int x2, int y2, int *x1, int *y1) {
	*x1 = 8 - y2 + 1;
	*y1 = x2;
}

void translateInv(int x1, int y1, int *x2, int *y2) {
	*x2 = y1;
	*y2 = 8 - x1 + 1;
}

void printMovesFormatted(vector<pair<int, int>> &moves, bool is_standard) {
	int f_x, f_y;
	cout << moves.size() << endl;

	for (auto xy: moves) {
		f_x = xy.first;
		f_y = xy.second;

		if (!is_standard) {
			translateInv(xy.first, xy.second, &f_x, &f_y);
		}

		cout << f_x << " " << f_y << endl;
	}
}

bool valid(int x, int y) {
	return x >= 1 && x <= 8 && y >= 1 && y <= 8;
}

bool equal(int x1, int y1, int x2, int y2) {
	return x1 == x2 && y1 == y2;
}

void setPXPY(int x, int y, int *PX, int *PY) {
	if (x + y == 8) {
		*PX = x;
		*PY = y;
	}
}

void setExtremes(int x, int y, int *LBX, int *LBY, int *RTX, int *RTY, int *PX, int *PY) {

	setPXPY(x, y, PX, PY);
	*LBX = x, *LBY = y;

	while (valid(*LBX - 1, *LBY - 1)) {
		*LBX = *LBX - 1;
		*LBY = *LBY - 1;
		setPXPY(*LBX, *LBY, PX, PY);
	}

	*RTX = x, *RTY = y;

	while (valid(*RTX + 1, *RTY + 1)) {
		*RTX = *RTX + 1;
		*RTY = *RTY + 1;
		setPXPY(*RTX, *RTY, PX, PY);
	}
}

void visit(bool visited[][9], int x, int y) {
	visited[x][y] = true;
}

bool isVisited(bool visited[][9], int x, int y) {
	return visited[x][y];
}

void applyHeuristic(int x, int y, vector<pair<int, int>> &moves) {

	int LBX, LBY,
		RTX, RTY,
		PX, PY,
		next_x, next_y,
		first_PX, first_PY;

	setExtremes(x, y,
		&LBX, &LBY,
		&RTX, &RTY,
		&PX, &PY
	);

	// deb(LBX);
	// deb(LBY);
	// deb(RTX);
	// deb(RTY);
	// deb(PX);
	// deb(PY);

	bool visited[9][9] = {0};
	visit(visited, x, y);

	// Move to prime diagonal
	if (!equal(x, y, PX, PY)) {
		moves.push_back({PX, PY});
		visit(visited, PX, PY);
	}

	first_PX = PX;
	first_PY = PY;

	// - Sub task 1 - up the prime diagonal
	// - Sub task 2 - down the prime diagonal

	for (int sub_task = 1; sub_task <= 2; sub_task++) {

		while (true) {

			// Move to bottom left
			if (!isVisited(visited, LBX, LBY)) {
				moves.push_back({LBX, LBY});
				visit(visited, LBX, LBY);	
			}

			// Move to top right
			if (!isVisited(visited, RTX, RTY)) {
				moves.push_back({RTX, RTY});
				visit(visited, RTX, RTY);		
			}

			moves.push_back({PX, PY});

			if (sub_task == 1) {
				next_x = PX - 1;
				next_y = PY + 1;

			} else {
				next_x = PX + 1;
				next_y = PY - 1;
			}

			if (!valid(next_x, next_y))
				break;

			setExtremes(next_x, next_y,
				&LBX, &LBY,
				&RTX, &RTY,
				&PX, &PY
			);

			moves.push_back({PX, PY});
			visit(visited, PX, PY);
		}

		if (sub_task == 2)
			break;

		x = first_PX + 1;
		y = first_PY - 1;

		if (!valid(x, y))
			break;

		setExtremes(x, y,
			&LBX, &LBY,
			&RTX, &RTY,
			&PX, &PY
		);

		moves.push_back({PX, PY});
		visit(visited, PX, PY);
	}
}

void printMoves(int r, int c) {

	// check if standard board
	bool is_standard = checkIfStandard(r, c);
	int x = r, y = c;

	// if not standard then translate to new x, y
	if(!is_standard) {
		translate(r, c, &x, &y);
	}

	// deb(is_standard);
	// deb(x);
	// deb(y);

	// APPLY HEURISTIC
	vector<pair<int, int>> moves;
	applyHeuristic(x, y, moves);

	printMovesFormatted(moves, is_standard);
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
		int r, c;
		cin >> r >> c;

		printMoves(r, c);
	}

	return 0;
}