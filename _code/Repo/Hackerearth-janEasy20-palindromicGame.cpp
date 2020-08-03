#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

bool allCharsUnique(string s) {

	int char_count[26] = {0};

	for (auto x: s) {
		char_count[x-'a']++;

		if (char_count[x-'a'] == 2)
			return false;
	}

	return true;
}

// void printArr(int a[]) {
// 	for (int i = 0; i < 26; i++)
// 		cout << a[i];
// 	cout << endl;
// }

// // void findWinner(string s, vector<int> v, int start, int end, int *max_path, int now_path) {

// // 	cout << "inside " << start << " " << end << " now_path " << now_path << endl ;

// // 	if (start > end)
// // 		return;

// // 	if (v[s[start]-'a'] == 0) {
// // 		// Call recursively

// // 		v[s[start]-'a']++;

// // 		findWinner(s, v, start+1, end, max_path, now_path+1);

// // 	} else {
// // 		cout << "set max a" << endl;
// // 		*max_path = now_path;
// // 	}


// // 	if (v[s[end]-'a'] == 0) {
// // 		// Call recursively

// // 		v[s[end]-'a']++;

// // 		findWinner(s, v, start, end-1, max_path, now_path+1);

// // 	} else {
// // 		cout << "set max b" << endl;
// // 		*max_path = now_path;
// // 	}
// // }

// string findWinner(string s) {

// 	int global[26] = {0};

// 	for (auto x: s)
// 		global[x-'a']++;

// 	cout << "global ";
// 	printArr(global);

// 	int len = s.length();
// 	int moves = 0;
// 	int cur[26] = {0};
// 	int start = 0, end = len-1;

// 	while (true) {

// 		deb(start);
// 		deb(end);
// 		cout << endl;

// 		if (start > end)
// 			break;

// 		moves++;
// 		cout << "moved " << (moves % 2 == 0 ? "Bob" : "Alice") << endl;

// 		cout << "cur ";
// 		printArr(cur);

// 		if (cur[s[start] - 'a'] > 0 || cur[s[end] - 'a'] > 0)
// 			break;

// 		if (global[s[start] - 'a'] >= global[s[end] - 'a']) {
// 			cur[s[start] - 'a']++;
// 			global[s[start] - 'a']--;
// 			start++;

// 		} else {
// 			cur[s[end] - 'a']++;
// 			global[s[end] - 'a']--;
// 			end--;			
// 		}
// 	}

// 	return (moves % 2 == 0 ? "Bob" : "Alice");
// }

string setDump(unordered_set<char> s) {

	string out = " {";
	for (auto it = s.begin(); it!=s.end(); it++)
		out += string(1, *it) + ',';
	out += "} ";

	return out;
}

bool findWinnerUtil(string str, int start, int end, unordered_set<char> &s) {

	// cout << "-> " << setDump(s) << str.substr(start, end-start+1) << endl;

	if (s.find(str[start]) != s.end() || s.find(str[end]) != s.end())
		return true;

	// choose start, insert into set;
	s.insert(str[start]);

	bool next_wins = findWinnerUtil(str, start+1, end, s);

	// cout << "from the start; "
	// 	<< setDump(s) <<"[" << str.substr(start+1, end-start) << "]"
	// 	<< " next wins " << next_wins << endl;

	// restore set
	s.erase(str[start]);

	if (!next_wins)
		return true;

	// choose end, insert into set;
	s.insert(str[end]);

	next_wins = findWinnerUtil(str, start, end-1, s);

	// cout << "from the end; "
	// 	<< setDump(s) << "[" << str.substr(start, end-start) << "]"
	// 	<< " next wins " << next_wins << endl;

	s.erase(str[end]);

	if (!next_wins)
		return true;

	return false;
}

string findWinner(string str) {
	unordered_set<char> set;
	return findWinnerUtil(str, 0, str.size()-1, set) ? "Alice" : "Bob";
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	// If all chars unique, then Tie
	if (allCharsUnique(s))
		cout << "Tie";

	else {
		s = s.substr(0, 30) + s.substr(s.size()-30);
		cout << findWinner(s);
	}

	cout << endl;

	return 0;
}