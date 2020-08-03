#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool solvable;
vector<int> numbers_processes[1000001], output_sequence;

// void printNumberProcesses(vector<stack<int>> numbers_processes) {

// 	string seq;
// 	int i = 1;

// 	for (auto st: numbers_processes) {
// 		seq = "";
// 		cout << "Thread #" << to_string(i++) << " : ";

// 		while (!st.empty()) {
// 			seq = to_string(st.top()) + " " + seq;
// 			st.pop();
// 		}

// 		cout << seq << endl;		
// 	}
// }


// void printOutputQueue(vector<int> q, int index) {

// 	cout << "Output Current State : ";

// 	// while (!q.empty()) {
// 	// 	cout << q.front() << " ";
// 	// 	q.pop_front();
// 	// }

// 	for (int i = index; i < q.size(); i++)
// 		cout << q[i] << " ";

// 	cout << endl;
// }

void solve(int index, int numbers_processes_size) {

	// cout << "-----" << endl;
	// printNumberProcesses(numbers_processes);
	// printOutputQueue(output_sequence, index);
	// cout << endl;

	if (index == output_sequence.size()) {
		solvable = true;
		return;
	}

	for (int i = 0; i < numbers_processes_size; i++) {

		if (!solvable 
			&& !numbers_processes[i].empty()
			&& numbers_processes[i].back() == output_sequence[index]
		) {

			int temp = numbers_processes[i].back();
			numbers_processes[i].pop_back();

			solve(index+1, numbers_processes_size);

			numbers_processes[i].push_back(temp);
		}
	}
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
		int num_threads;
		cin >> num_threads;

		int list_size, inp, total_list_size = 0;

		for (int i = 0; i < num_threads; i++) {
			cin >> list_size;

			total_list_size += list_size;

			for (int j = 0; j < list_size; j++) {
				cin >> inp;
				numbers_processes[i].push_back(inp);
			}
		}

		for (int i = 0; i < total_list_size; i++) {
			cin >> inp;
			output_sequence.push_back(inp);
		}

		solvable = false;
		solve(0, num_threads);

		cout << (solvable ? "Yes" : "No") << endl;

		for (int i = 0; i < num_threads; i++)
			numbers_processes[i].clear();
		output_sequence.clear();
	}

	return 0;
}