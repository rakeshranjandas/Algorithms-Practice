#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

void printVV(vector<vector<int>> v) {
	for (auto x: v) {
		cout << "(" << x[0] << "," << x[1] << "), ";
	}
	cout << endl;
}

int main() {

	IOS

	vector<vector<int>> A;
	A.push_back(vector<int> {0,2});
	A.push_back(vector<int> {5,10});
	A.push_back(vector<int> {13,23});
	A.push_back(vector<int> {24,25});
	
	vector<vector<int>> B;
	B.push_back(vector<int> {1,5});
	B.push_back(vector<int> {8,12});
	B.push_back(vector<int> {15,24});
	B.push_back(vector<int> {25,26});

	printVV(A);
	printVV(B);

	///////////////////////////

	int depth = 0;
    int ai = 0, bi = 0;
    int cur = -1, sai = 0, sbi = 0, last_cur, last_depth;
    
    A.push_back({INT_MAX, INT_MAX});
    B.push_back({INT_MAX, INT_MAX});
    
    vector<vector<int>> v;
    
    while (A[ai][sai] != INT_MAX || B[bi][sbi] != INT_MAX) {

    	deb(ai);
    	deb(sai);
        deb(bi);
        deb(sbi);
        cout << endl;

        if (A[ai][sai] == B[bi][sbi]) {
            if (sai == 0) {
                cur = A[ai][sai];
                sai = 1;
                depth++;
                
            } else if (sbi == 0) {
                cur = B[bi][sbi];
                sbi = 1;
                depth++;
                
            } else {
                cur = A[ai][sai];
                sai = 0;
                depth--;
                ai++;
                
                if (last_depth == 2 && depth == 1)
                    v.push_back(vector<int> {last_cur, cur});
            }
            
        } else if (A[ai][sai] < B[bi][sbi]) {
            
            cur = A[ai][sai];
            
            if (sai == 0) {
                depth++;
                sai = 1;
                
            } else {
                depth--;
                sai = 0;
                ai++;
                
                if (last_depth == 2 && depth == 1)
                    v.push_back(vector<int> {last_cur, cur});
            }
            
        } else {

            cur = B[bi][sbi];
            
            if (sbi == 0) {
                depth++;
                sbi = 1;
                
            } else {
                depth--;
                sbi = 0;
                bi++;
                
                if (last_depth == 2 && depth == 1)
                    v.push_back(vector<int> {last_cur, cur});
            }
        }
        
        last_cur = cur;
        last_depth = depth;
        
    }
       

    printVV(v);


	return 0;
}