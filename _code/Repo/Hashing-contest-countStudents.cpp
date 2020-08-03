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


	map<string, map<int, int>, sortByName> mStudents;
	map<string, map<int, int>> :: iterator mStudents_it;
	map<int, int> :: iterator mMarks_it;

	for (int i = 0; i < n; i++) {
		mStudents_it = mStudents.find(name[i]);

		if (mStudents_it != mStudents.end()) {

			mMarks_it = (mStudents_it->second).find(marks[i]);

			if (mMarks_it != (mStudents_it->second).end()) {
				mMarks_it->second++;

			} else {
				
				(mStudents_it->second)[marks[i]] = 1;
			}


		} else {

			map<int, int> mMarks;
			mMarks[marks[i]] = 1;

			mStudents[name[i]] = mMarks;
		}
	}

	map<int, int> :: reverse_iterator mMarks_rit;

	for (auto mS: mStudents) {

		for (mMarks_rit = (mS.second).rbegin(); mMarks_rit != (mS.second).rend(); mMarks_rit++){

			cout << mS.first << " " << mMarks_rit->first << " " << mMarks_rit->second << endl;
		}
	}

	cout << endl;

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