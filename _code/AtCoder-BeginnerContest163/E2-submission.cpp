#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,dp[2005][2005];

struct node
{
	int rt;
	int num;
}a[5005];

bool cmp(node a,node b)
{
	return a.num>b.num;
}

int work(int now,int l,int r)
{

	cout << " now" << now << endl;
	if (l>r)  return a[now].num;
	if (dp[l][r]!=-1)  return dp[l][r];

	cout << a[now].num << endl;
	
	int first=work(now+1,l+1,r)+a[now].num*abs(a[now].rt-l);
	int second=work(now+1,l,r-1)+a[now].num*abs(a[now].rt-r);

	cout << " " << first << " " << second << endl;

	dp[l][r]=max(dp[l][r],max(first,second));
	
	return dp[l][r];
}

signed main()
{
	cin>>n;
	memset(dp,-1,sizeof(dp));
	for (int i=1;i<=n;i++)  cin>>a[i].num,a[i].rt=i;
	
	sort(a+1,a+n+1,cmp);
	
	for (int i = 1; i <= n; i++)
		cout << a[i].num << " " << a[i].rt << ", ";
	cout << endl;

	cout<<work(1,1,n)<<endl;
	
	return 0;
}