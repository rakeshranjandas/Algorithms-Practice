#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long     long int ll;

class Solution {
    int countBalls(int box[], int balls_size) {
        int c = 0;
        for (int i = 0; i < balls_size; i++)
            c += box[i];
        
        return c;
    }
    
    int countDistinct(int b[], int n) {
        int c = 0;
        for (int i = 0; i < n; i++)
            if (b[i] > 0)
                c++;
        
        return c;
    }
    
    bool sameDistinct(int box[], vector<int> &balls, int num_balls, int *c) {
        int box_comp[num_balls];
        for (int i = 0; i < num_balls; i++) {
            box_comp[i] = balls[i] - box[i];
        }
        
        *c = 1;
        for (int i = 0; i < num_balls; i++) {
            if (box_comp[i] != box[i]) {
                *c = 2;
                break;
            }   
        }
        
        return countDistinct(box, num_balls) == countDistinct(box_comp, num_balls);
    }
    
    void gen(int box[], int cur_ind, int n, vector<int> &balls, int num_balls, int *count_pos, int *count_eq) {
        
        for (int i = 0; i < num_balls; i++)
            cout << "(" << i << ")" << box[i] << " ";
        cout << endl;

        deb(n);
        
        if (cur_ind >= num_balls) {
            // cout << "cB " << countBalls(box, num_balls) << endl;
            
            if (countBalls(box, num_balls) == n/2) {
                
                
                cout << "here " << endl;
             
                int c = 0;
                if (sameDistinct(box, balls, num_balls, &c))
                    *count_eq = *count_eq + 1;
                
                *count_pos = *count_pos + c;
            }
            
            return;
        }
        
        for (int i = 0; i <= balls[cur_ind]; i++) {
            box[cur_ind] = i;
            gen(box, cur_ind+1, n, balls, num_balls, count_pos, count_eq);
        }
    }
    
	public:
    double getProbability(vector<int>& balls) {
        int num_balls = balls.size();
        
        int n = 0;
        for (int i = 0; i < num_balls; i++)
            n += balls[i];
        
        int count_pos = 0, count_eq = 0;
        int box[num_balls];
        memset(box, 0, sizeof(box));
        
        gen(box, 0, n, balls, num_balls, &count_pos, &count_eq);    
        
        cout << "count pos " << count_pos << endl;
        cout << "count eq " << count_eq << endl;
        
        // return 1;
        return (double) count_eq / count_pos;
    }
};

int main() {

	IOS

	int t;
	cin >> t;

	Solution sol;

	while (t--) {
		int n;
		cin >> n;

		vector<int> balls(n);
		for (int i = 0; i < n; i++)
			cin >> balls[i];


		cout << sol.getProbability(balls) << endl;
	}

	return 0;
}