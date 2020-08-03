#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

class Box {
	public:

	int *properties;
	int index, n;

	void initBox(int nn) {
		n = nn;
		properties = (int *) malloc(sizeof(int) * nn);
	}

	void printBox() {
		cout << "[" << index << "] ";
		for (int i = 0; i < n; i++)
			cout << properties[i] << ",";
		cout << endl;
	}
};

bool sortBox(Box a, Box b) {
	int n = a.n;

	for (int i = 0; i < n; i++) {
		if (a.properties[i] == b.properties[i])
			continue;

		if (a.properties[i] < b.properties[i]) {
			return true;

		} else
			return false;
	}

	return false;
}

bool canStackOver(Box a, Box b) {
	int n = a.n;
	for (int i = 0; i < n; i++) {
		if (a.properties[i] >= b.properties[i]) {
			return false;
		}
	}

	return true;
}

string findStackSequence(Box b[], int stack_par[], int ind) {

	string res = "";

	while (stack_par[ind] != ind) {
		res = to_string(b[ind].index+1) + " " + res;
		ind = stack_par[ind];
	}

	return to_string(b[ind].index+1) + " " + res;
}

int main() {

	IOS

	while (!cin.eof()) {
		int k, n;
		cin >> k >> n;

		Box b[k];

		for (int i = 0; i < k; i++) {
			b[i].initBox(n);
			b[i].index = i;
			for (int j = 0; j < n; j++)
				cin >> b[i].properties[j];

			sort(b[i].properties, b[i].properties+n);
		}

		sort(b, b+k, sortBox);

		int stack_len[k], stack_par[k];

		for (int i = 0; i < k; i++) {
			stack_len[i] = 1;
			stack_par[i] = i;
		}

		for (int i = 0; i < k-1; i++) {
			for (int j = i+1; j < k; j++)	{
				if (canStackOver(b[i], b[j])) {
					int now_stack_len = stack_len[i] + 1;

					if (now_stack_len > stack_len[j]) {
						stack_len[j] = now_stack_len;
						stack_par[j] = i;
					}
				}
			}

		}

		int max_ind = 0;
		for (int i = 1; i < k; i++) {
			if (stack_len[max_ind] < stack_len[i])
				max_ind = i;
		}

		cout << stack_len[max_ind] << endl;
		cout << findStackSequence(b, stack_par, max_ind) << endl;

	}

	return 0;
}