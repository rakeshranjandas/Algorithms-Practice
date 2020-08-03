#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class sortByName {

   public:
     bool operator()(const string a,const string b) { return a.compare(b) < 0; }
};

class sortByMarks {

   public:
     bool operator()(const int a,const int b) { return a > b; }
};

void countStudents(string name[], int marks[], int n) {


	map<string, map<int, int, sortByMarks>, sortByName> studentsMap;

	for (int i = 0; i < n; i++) {
		studentsMap[name[i]][marks[i]]++;
	}

	for (auto student: studentsMap)
		for (auto markCount: student.second)
			cout << student.first << ' ' << markCount.first << ' ' << markCount.second << endl;
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

		string name[n];
		int marks[n];

		for (int i = 0; i < n; i++) {
			cin >> name[i] >> marks[i];
		}

		countStudents(name, marks, n);
	}

	return 0;
}



// ankit 100 2
// ankit 30 1
// john 60 1
// john 50 1