#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

unordered_map<string, queue<int>> m;

bool canCreateDish() {
	string has_atleast_one = "", has_atleast_two = "";

	for (auto x: m) {

		int q_size = x.second.size();

		if (q_size == 3) {
			return true;
		}

		if (q_size == 2) {

			if (has_atleast_one != "") {
				return true;
			}

			has_atleast_two = x.first;

		} else	if (q_size == 1) {

			if (has_atleast_two != "") {
				return true;
			}

			has_atleast_one = x.first;
		}
	}

	return false;
}

void createDish() {

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

		if (found_ind1 == -1) {
			found_ind1 = x.second.front();
			found_ind_key1 = x.first;

		} else {
			found_ind2 = x.second.front();
			found_ind_key2 = x.first;
		}
	}

	if (found_ind1 >= 0 && found_ind2 >= 0) {
		if (found_ind1 < found_ind2)
			m[found_ind_key1].pop();
		else 
			m[found_ind_key2].pop();
	}

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

	int n;
	cin >> n;

	string ingredient, category;

	for (int i = 0; i < n; i++) {
		cin >> ingredient;

		category = findCategory(ingredient);

		m[category].push(i);

		bool can_create_dish = canCreateDish();

		if (can_create_dish) {
			createDish();
			cout << 1;

		} else {
			cout << 0;
		}
	}

	return 0;
}