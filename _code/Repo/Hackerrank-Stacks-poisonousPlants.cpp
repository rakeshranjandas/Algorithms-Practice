#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct plant{
	int value;
	int day;

	plant(int v, int d) {
		value = v;
		day = d;
	}
};

void printStack(stack<plant> st) {
	// return;

	string out;

	while (!st.empty()) {
		plant top_plant = st.top();
		out = "(" + to_string(top_plant.value) + ","
			+ to_string(top_plant.day) + "), " + out;

		st.pop();
	}

	cout << out << endl;
}

int poisonousPlants(vector<int> p) {

	stack<plant> st;
	st.push(plant(p[0], 0));

	// printStack(st);
	int day, max_day = 0;

	for (int i = 1; i < p.size(); i++) {
		day = 0;
		while (true) {

			if (st.empty()) {
				st.push(plant(p[i], 0));
				break;

			} else {
				if (st.top().value < p[i]) {
					if (st.top().day == day+1)
						st.pop();

					st.push(plant(p[i], day+1));
					max_day = max(max_day, day+1);

					break;

				} else {
					day = st.top().day;
					st.pop();
				}
			}
		}
			// printStack(st);

	}

	return max_day;
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> v;
	int ip;

	for (int i = 0; i < n; i++) {
		cin >> ip;
		v.push_back(ip);
	}

	cout << poisonousPlants(v) << endl;

	return 0;
}