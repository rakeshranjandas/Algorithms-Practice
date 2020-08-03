#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;
#define GRID_SIZE 9

bool valid(int sudoku[][GRID_SIZE], int now_x, int now_y) {

	// Check row has all unique numbers
	// unordered_set<int> row_numbers;
	// for (int i = 0; i < GRID_SIZE; i++)
	// 	if (sudoku[now_x][i] > 0)
	// 		if (row_numbers.find(sudoku[now_x][i]) != row_numbers.end())
	// 			return false;
	// 		else
	// 			row_numbers.insert(sudoku[now_x][i]);

	bool row_numbers[GRID_SIZE+1] = {0};
	for (int j = 0; j < GRID_SIZE; j++) {

		if (sudoku[now_x][j] == 0)
			continue;

		if (row_numbers[sudoku[now_x][j]])
			return false;

		row_numbers[sudoku[now_x][j]] = true;
	}



	// Check col has all unique numbers
	// unordered_set<int> col_numbers;
	// for (int i = 0; i < GRID_SIZE; i++)
	// 	if (sudoku[i][now_y] > 0)
	// 		if (col_numbers.find(sudoku[i][now_y]) != col_numbers.end())
	// 			return false;
	// 		else
	// 			col_numbers.insert(sudoku[i][now_y]);

	bool col_numbers[GRID_SIZE+1] = {0};
	for (int i = 0; i < GRID_SIZE; i++) {

		if (sudoku[i][now_y] == 0)
			continue;

		if (col_numbers[sudoku[i][now_y]])
			return false;

		col_numbers[sudoku[i][now_y]] = true;
	}


	// Check grid has all unique numbers
	// unordered_set<int> grid_numbers;
	int grid_start_x = (now_x / 3) * 3;
	int grid_start_y = (now_y / 3) * 3;
	// for (int i = 0; i < 3; i++)
	// 	for (int j = 0; j < 3; j++)
	// 		if (sudoku[grid_start_x+i][grid_start_y+j] > 0)
	// 			if (grid_numbers.find(sudoku[grid_start_x+i][grid_start_y+j]) != grid_numbers.end())
	// 				return false;
	// 			else
	// 				grid_numbers.insert(sudoku[grid_start_x+i][grid_start_y+j]);

	bool grid_numbers[GRID_SIZE+1] = {0};
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {

			if (sudoku[grid_start_x+i][grid_start_y+j] == 0)
				continue;

			if (grid_numbers[sudoku[grid_start_x+i][grid_start_y+j]])
				return false;

			grid_numbers[sudoku[grid_start_x+i][grid_start_y+j]] = true;
		}
	}


	return true;
}

bool findNextAndSolveSudoku(int sudoku[][GRID_SIZE], int now_x, int now_y) {

	// cout << "inside " << now_x << " " << now_y << endl;

	if (now_x >= GRID_SIZE)
		return true;

	if (sudoku[now_x][now_y] != 0) {
		int next_y = now_y+1, next_x = now_x;
		if (next_y >= GRID_SIZE) {
			next_y = 0;
			next_x += 1;
		}

		return findNextAndSolveSudoku(sudoku, next_x, next_y);

	}

	// Solve for this cell
	for (int num = 1; num <= 9; num++) {
		sudoku[now_x][now_y] = num;

		if (valid(sudoku, now_x, now_y)) {
			// cout << "valid " << now_x << " " << now_y << " " << num << endl;

			bool solved = findNextAndSolveSudoku(sudoku, now_x, now_y);

			// cout << solved << " " << now_x << " " << now_y << " " << num << endl;

			if (solved)
				return true;
		}
	}

	sudoku[now_x][now_y] = 0;
	return false;
	
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
		int sudoku[GRID_SIZE][GRID_SIZE];
		for (int i = 0; i < GRID_SIZE; i++)
			for (int j = 0; j < GRID_SIZE; j++)
				cin >> sudoku[i][j];

		findNextAndSolveSudoku(sudoku, 0, 0);

		// Print Sudoku
		for (int i = 0; i < GRID_SIZE; i++) {
			for (int j = 0; j < GRID_SIZE; j++)
				cout << sudoku[i][j] << " ";
		}

	}

	return 0;
}