#include<iostream>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

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
		double m;
		double n, k, l;

		cin >> m >> n >> k >> l;

		int whole_tasks_hours = n / (k+l);
		double whole_tasks = whole_tasks_hours * l;

		double rest_tasks_hours = n - (whole_tasks_hours * (k+l));
		double rest_tasks = min(rest_tasks_hours, l);

		double total_tasks = whole_tasks + rest_tasks;
		cout << min(total_tasks, m) << endl;
	}

	return 0;
}