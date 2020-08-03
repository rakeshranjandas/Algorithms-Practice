#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

struct Job {
	int start_time, end_time, num;

	Job(int s, int e, int i) {
		start_time = s;
		end_time = e;
		num = i;
	}
};

bool sortJob(Job a, Job b) {
	bool is_correct = false;

	if (a.start_time < b.start_time)
		is_correct = true;

	else if (a.start_time == b.start_time && a.end_time < b.end_time)
		is_correct = true;

	return is_correct;
}

void maxActivitiesNum(int start[], int end[], int n) {

	vector<Job> v;

	for (int i = 0; i < n; i++)
		v.push_back(Job(start[i], end[i], i+1));

	sort(v.begin(), v.end(), sortJob);

	// for (auto x: v) {
	// 	cout << x.start_time << "-" << x.end_time << ", ";
	// }
	// cout << endl;

	Job now_job = v[0];
	int job_count = 1;

	for (int i = 1; i < n; i++) {

		if (v[i].start_time >= now_job.end_time) {

			cout << now_job.num << " ";

			now_job = v[i];
			job_count++;

		} else if (v[i].end_time < now_job.end_time) {
			now_job = v[i];
		}
	}

	cout << now_job.num << " ";
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
		
		int start[n];
		for (int i = 0; i < n; i++)
			cin >> start[i];

		int end[n];
		for (int i = 0; i < n; i++)
			cin >> end[i];

		maxActivitiesNum(start, end, n);

		cout << endl;
	}

	return 0;
}