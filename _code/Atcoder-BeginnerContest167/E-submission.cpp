#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front

// #define fisier 1

using namespace std;

typedef long long ll;

const int mod = 998244353;
const double dancila = 3.14159265359; // PI 
const double eps = 1e-9;

int n;

vector<pair<int, int> >ar[2000002];
int main()
{

    #ifdef fisier
        ifstream cin("input.in");
        ofstream cout("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> n;
	int dif = 0;
	int dif2 = 0;
	for(int i = 1; i <= n; ++i)
	{
		string s;
		cin >> s;
		deque<char> d;
		for(int j = 0; j < s.size(); ++j)
		{
			if(!d.empty() && s[j] == ')' && d.back() == '(')
				d.pop_back();
			else
				d.pb(s[j]);
		}
		if(!d.empty() && d[0] == '(')
			dif += d.size();
		else
		{
			int dsc = 0;
			int cl = 0;
			for(int j = 0; j < d.size(); ++j)
				if(d[j] == '(')
					dsc++;
				else
					cl++;
			if(!dsc)
				dif2 += cl;
			else
			{
				ar[1000000 + dsc - cl].pb({cl, dsc});
			}
		}
	}
	multiset<pair<int, int> >prd;
	for(int i = 1000001; i <= 2000000; ++i)
		for(auto pr : ar[i])
			prd.insert(pr);
	while(!prd.empty())
	{
		pair<int, int> xx = *prd.begin();
		if(dif >= xx.fi)
			dif = dif - xx.fi + xx.se, prd.erase(prd.lower_bound(xx));
		else
		{
			cout << "No";
			return 0;
		}
	}
	for(int i = 1000000; i >= 0; --i)
	{
		for(auto pr : ar[i])
		{
			if(dif < pr.fi)
			{
				cout << "No";
				return 0;
			}
			dif = dif - pr.fi + pr.se;
		}
	}
	dif -= dif2;
	if(dif == 0)
		cout << "Yes";
	else
		cout << "No";
    return 0;
}
