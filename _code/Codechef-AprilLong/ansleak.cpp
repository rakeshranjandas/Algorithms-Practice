#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

class Form {
	public:

	vector<int> ques;
	set<int> correct;
	int no_of_ques;
	int index;

	Form(int n) {
		no_of_ques = n;
		ques.resize(n);
	}

	Form(const Form& f) {
		ques = f.ques;
		correct = f.correct;
		no_of_ques = f.no_of_ques;
		index = f.index;
	}	

	void examine(Form f) {
		for (int i = 0; i < f.no_of_ques; i++) {
			if (f.ans(i) == ans(i))
				correct.insert(i);
		}
	}

	int ans(int qno) {
		return ques[qno];
	}

	void respond(int qno, int ans) {
		ques[qno] = ans;
	}

	void setIndex(int i) {
		index = i;
	}

	int score() {
		return correct.size();
	}

	void printAns() {
		cout << index << "- ";
		for (int i = 0; i < no_of_ques; i++)
			cout << "(" << i << ")" << ans(i) << " ";
		cout << endl;
	}

	void printCorrect() {
		cout  <<"correct " << index << "- {";
		for (auto x: correct)
			cout << x << ",";
		cout << "}" << endl;
	}
};

bool sortByScore(Form f1, Form f2) {
	return f1.score() < f2.score();
}

int main() {

	IOS

	int t;
	cin >> t;

	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;

		Form f[k](n);
		for (int i = 0; i < k; i++)
			f[i].setIndex(i);

		int resp;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k; j++) {
				cin >> resp;
				f[j].respond(i, resp);
			}
		}

		for (int i = 0; i < k; i++)
			f[i].printAns();

		Form myf = Form(f[0]);

		for (int i = 0; i < k; i++)
			f[i].examine(myf);

		sort(f, f+k, sortByScore);

		for (int i = 0; i < k; i++) {
			f[i].printCorrect();
		}
	}

	return 0;
}