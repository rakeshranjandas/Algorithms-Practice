#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

class State {
	public:
	string moves;
	int a, b, c;
	int level;

	State(int aa, int bb, int cc, string mv = "", int l = 0) {
		a = aa, b = bb, c = cc;
		moves = mv;
		level = l;
	}
};

int main() {

	IOS

	int n, a, b, c;
	cin >> n >> a >> b >> c;

	deque<State> q;
	q.push_back(State(a, b, c));

	string ip;
	int lv = 0, nlv;

	for (int i = 0; i < n; i++) {
		cin >> ip;

		if (q.empty())
			break;

		while (q.front().level == lv) {
			nlv = lv + 1;

			State popped = q.front();
			q.pop_front();

			// deb(popped.moves);

			if (ip == "AB") {
				if (popped.a > 0)
					q.push_back(State(popped.a - 1, popped.b + 1, popped.c, popped.moves + "\nB", nlv));

				if (popped.b > 0)
					q.push_back(State(popped.a + 1, popped.b - 1, popped.c, popped.moves + "\nA", nlv));

			} else if (ip == "AC") {
				if (popped.a > 0)
					q.push_back(State(popped.a - 1, popped.b, popped.c + 1, popped.moves + "\nC", nlv));

				if (popped.c > 0)
					q.push_back(State(popped.a + 1, popped.b, popped.c - 1, popped.moves + "\nA", nlv));
			
			} else if (ip == "BC") {
				if (popped.b > 0)
					q.push_back(State(popped.a, popped.b - 1, popped.c + 1, popped.moves + "\nC", nlv));

				if (popped.c > 0)
					q.push_back(State(popped.a, popped.b + 1, popped.c - 1, popped.moves + "\nB", nlv));
			}
		}

		lv++;
	}

	if (q.empty())
		cout << "No" << endl;
	
	else {
		cout << "Yes";
		State popped = q.back();
		cout << popped.moves << endl;
	}

	return 0;
}