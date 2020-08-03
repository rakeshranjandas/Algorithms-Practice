
// Problem : Divide them all
// Contest : CodeChef - Code Invicta
// URL : https://www.codechef.com/GHC32020/problems/MOON
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)




#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define vec vector<int>
#define fo(i, n) for (int i = 0; i < n; i++)
#define foo(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define deb(x) cout << #x << " --> " << x << endl;
#define FILE_WR freopen("../input.txt", "r", stdin);\
    freopen("../output.txt", "w", stdout);
 
#define deb1a(v)                  \
    cout << #v << "--->" << endl; \
    for (auto it : v)             \
    {                             \
        cout << it << " ";        \
    }                             \
    cout << endl;
#define deb2a(v)                  \
    cout << #v << "--->" << endl; \
    for (auto it : v)             \
    {                             \
        for (auto it1 : it)       \
        {                         \
            cout << it1 << " ";   \
        }                         \
        cout << endl;             \
    }
#define mod 998244353
#define so(v) sort(v.begin(),v.end())
#define fi first
#define se second
int power(int x, unsigned int y, int p){ int res = 1;x = x % p;while (y > 0)  { if (y & 1)res = (res*x) % p;y = y>>1;  x = (x*x)% p;} return res;}

long findN(const int n) 
{ 
    // Modulus operator are expensive on most of the  
    // computers. n & 3 will be equivalent to n % 4.    
  
    switch(n & 3) // n % 4  
    { 
    case 0: return n;     // if n is multiple of 4 
    case 1: return 1;     // If n % 4 gives remainder 1   
    case 2: return n + 1; // If n % 4 gives remainder 2     
    case 3: return 0;     // If n % 4 gives remainder 3   
    } 
} 

void printSet(set<int> s) {
    for (auto x: s)
        cout << " " << x;
    cout << endl;
}

int32_t main()
{
    FILE_WR;
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set<int> s,s1;
    int n;
    cin>>n;
    int q;
    cin>>q;
    while(q--){
        int c,x;
        cin >> c >> x;
        if(c==1){
            s1.erase(x);
            if(s.find(x+1)==s.end()){
                s1.insert(x + 1);
            }
            s.insert(x);
        }
        else{
            int l, r;
            if(s.find(x)==s.end()){
                l = x;
            }
            else{
                l = *s1.lower_bound(x);
            }
            auto it = s.upper_bound(l);
            if(it==s.end())
            {
                r = n;
            }
            else{
                r = *it - 1;
            }

            
            int ans;
            deb(l);
            deb(r);
            if(l==1){
                ans = findN(r);
            }
            else
                ans = findN(r) ^ findN(l - 1);
            cout << ans << "\n";
        }

        deb(c);
        cout << "s1 ";
        printSet(s1);
        cout << "s ";
        printSet(s);
        cout << endl;

    }
}