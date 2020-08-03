#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

void printV(vector<char> &ch, vector<int> &cnt) {
    for (int i = 0; i < ch.size(); i++) {
        cout << ch[i] << "(" << cnt[i] << ") ";
    }
    cout << endl;
}

int compress(vector<char> &ch, vector<int> &cnt, int cur, int last, int k) {

	cout << "in cur " << cur << " last " << last << " k " << k << endl;
	printV(ch, cnt);
	cout << endl;
	
    if (k < 0)
        return 200;
    
    if (cur == ch.size())
        return 0;
    
    cout << ch[cur] << " " << cur << " - " << k << endl;
    

    int corr = 0, corr_orig = cnt[cur];
    
    if (last != -1 && ch[cur] == ch[last]) {
    	deb("corrected");
        corr = -1* (1 + (cnt[last] == 1 ? "" : to_string(cnt[last])).size());
        cnt[cur] += cnt[last];
    }

    if (k == 0) {
        int tc = 0;
        for (int i = cur; i < ch.size(); i++) {
            tc += 1 + (cnt[i] == 1 ? "" : to_string(cnt[i])).size();
        }

        if (corr != 0) {
    		cnt[cur] = corr_orig;
    	}

    	deb(tc);
    	deb(corr);
        
        return tc + corr;
    }

    string fs = ch[cur] + (cnt[cur] == 1 ? "" : to_string(cnt[cur]));
    deb(fs);
    
    // do nothing
    int min_c = fs.size() + corr + compress(ch, cnt, cur+1, cur, k);
    cout << "min_c X " << min_c << endl; 
    
    int orig = cnt[cur];
        
    // if count made to 0
    cnt[cur] = 0;
    min_c = min(min_c, 0 + corr + compress(ch, cnt, cur+1, last, k-orig));
    cout << "min_c 0 " << min_c << endl;
    cnt[cur] = orig;
    
    // if count made to 1
    if (cnt[cur] - 1 >= 0) {
        cnt[cur] = 1;
        min_c = min(min_c, 1 + corr + compress(ch, cnt, cur+1, cur, k-orig+1));
        cout << "min_c 1 " << min_c << endl;
        cnt[cur] = orig;
    }
    
    // if count made to 1 digit
    if (cnt[cur] - 9 >= 0) {
        cnt[cur] = 9;
        min_c = min(min_c, 2 + corr + compress(ch, cnt, cur+1, cur, k-orig+9));
        cout << "min_c 9 " << min_c << endl;
        cnt[cur] = orig;
    }
    
    // if count made to 2 digits
    if (cnt[cur] - 99 >= 0) {
        cnt[cur] = 99;
        min_c = min(min_c, 3 + corr + compress(ch, cnt, cur+1, cur, k-orig+99));
        cout << "min_c 99 " << min_c << endl;
        cnt[cur] = orig;
    }

    if (corr != 0) {
    	cnt[cur] = corr_orig;
    }

    cout << "out    cur " << cur << " last " << last << " k " << k << " min " << min_c << endl << endl;
    
    return min_c;
}

int getLengthOfOptimalCompression(string s, int k) {
    
    vector<char> ch;
    vector<int> cnt;
    
    char last = s[0];
    int last_c = 1;
    
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == last) {
            last_c++;
        
        } else {
            ch.push_back(last);
            cnt.push_back(last_c);
            last_c = 1;
        }
        
        last = s[i];
    }
    
    ch.push_back(last);
    cnt.push_back(last_c);
    
	printV(ch, cnt);
	cout << endl;
    
    int res = compress(ch, cnt, 0, -1, k);
    
    return res;
}

int main() {

	IOS

	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;
		int k;
		cin >> k;

		cout << "ans = " << getLengthOfOptimalCompression(s, k) << endl;
	}

	return 0;
}