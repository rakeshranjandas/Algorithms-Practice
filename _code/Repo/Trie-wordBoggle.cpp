#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;
#define COL 8
#define MOVES 8

int dx[MOVES] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[MOVES] = {1, -1, 0, 1, -1, 0, 1, -1};

struct sortString {
	bool operator() (string a, string b) {
		return a.compare(b) <= 0;
	}
};

bool valid(int x, int y, int row, int col) {
	return x >= 0 && x < row && y >= 0 && y < col;
}

bool canFind(int now_x, int now_y, char boggle[][COL],
	int row, int col, bool visited[][COL], string str, int ind) {

	if (ind == str.size())
		return true;

	visited[now_x][now_y] = true;

	for (int move = 0; move < MOVES; move++) {
		int new_x = now_x + dx[move];
		int new_y = now_y + dy[move];

		if (valid(new_x, new_y, row, col) && !visited[new_x][new_y] && boggle[new_x][new_y] == str[ind]) {
			if (canFind(new_x, new_y, boggle, row, col, visited, str, ind+1))
				return true;
		}
	}

	return false;
}

void printPossibleWords(string dict[], int n, char boggle[][COL], int row, int col) {

	// Store the start points of characters
	map<char, vector<pair<int, int>>> start_xy;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			start_xy[boggle[i][j]].push_back({i, j});

	// Set to remove duplicates
	set<string> str_set;
	for (int i = 0; i < n; i++)
		str_set.insert(dict[i]);

	bool at_least_one = false;

	for (auto now_str: str_set) {
		bool visited[row][COL] = {0};

		for (auto start: start_xy[now_str[0]]) {
			bool found = canFind(start.first, start.second, boggle, row, col, visited, now_str, 1);

			if (found) {
				at_least_one = true;
				cout << now_str << " ";
				break;
			}
		}
	}

	if (!at_least_one)
		cout << "-1";
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

		string dict[n];
		for (int i = 0; i < n; i++)
			cin >> dict[i];

		int row, col;
		cin >> row >> col;

		char boggle[row][COL];

		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				cin >> boggle[i][j];

		printPossibleWords(dict, n, boggle, row, col);
		cout << endl;
	}

	return 0;
}