#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

unordered_map<string, queue<int>> m;

bool canCreateDish() {
	// cout << "boolCD\n";
	string has_atleast_one = "", has_atleast_two = "";

	for (auto x: m) {

		int q_size = x.second.size();

		// cout << q_size << " q_size \n";

		if (q_size == 3) {
			// cout << "here1" << endl;
			return true;
		}

		if (q_size == 2) {

			if (has_atleast_one != "") {
				// cout << "here2" << endl;
				return true;
			}

			has_atleast_two = x.first;

		} else	if (q_size == 1) {

			if (has_atleast_two != "") {
				// cout << "here3" << endl;
				return true;
			}

			has_atleast_one = x.first;
		}
	}

	// cout << "here4" << endl;
	return false;
}

void createDish() {
	// cout << "insCD\n";

	for (auto &x: m)
		if (x.second.size() == 3) {
			x.second.pop();
			x.second.pop();
			x.second.pop();

			return;
		}

	string popped_key;
	for (auto &x: m) {
		if (x.second.size() == 2) {
			x.second.pop();
			x.second.pop();

			popped_key = x.first;
		}
	}

	int found_ind1 = -1, found_ind2 = -1;
	string found_ind_key1, found_ind_key2;

	for (auto &x: m) {
		if (x.first == popped_key)
			continue;

		if (x.second.size() > 0) {
			if (found_ind1 == -1) {
				found_ind1 = x.second.front();
				found_ind_key1 = x.first;

			} else {
				found_ind2 = x.second.front();
				found_ind_key2 = x.first;
			}
		}
	}

	// deb(found_ind1);
	// deb(found_ind2);

	if (found_ind1 >= 0 && found_ind2 >= 0) {
		if (found_ind1 < found_ind2)
			m[found_ind_key1].pop();
		else 
			m[found_ind_key2].pop();

	} else if (found_ind1 >= 0)
		m[found_ind_key1].pop();

	return;
}

string findCategory(string ing) {
	if (ing.substr(0, 3) == "FAT")
		return "FAT";

	if (ing.substr(0, 4) == "CARB")
		return "CARB";

	if (ing.substr(0, 5) == "FIBER")
		return "FIBER";

	return "";
}

void printQ(queue<int> q) {
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
}

void printMap() {
	for (auto x: m) {
		cout << endl;
		cout << x.first << " ";

		printQ(x.second);

	}

	cout << endl;
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	int n;
	cin >> n;

	string ingredient, category;

	for (int i = 0; i < n; i++) {
		cin >> ingredient;

		category = findCategory(ingredient);

		m[category].push(i);

		// cout << endl << "------";

		// deb(i);


		// printMap();
		// cout << endl;

		bool can_create_dish = canCreateDish();
		// deb(can_create_dish);

		if (can_create_dish) {
			createDish();

			// cout << "\ncreated ";
			// printMap();


			cout << 1;

		} else {
			cout << 0;
		}
	}

	return 0;
}