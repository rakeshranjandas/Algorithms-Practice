#include <bits/stdc++.h>
 
using namespace std;
#define deb(x)  cout << #x << " " << x << endl;


long long int countsum(long long int m){
  long long int sum=1;
  if(m==1) return 0; 
  for(long long int i=2;i*i<=m;i++){
    if(i*i==m) sum++;
    else if(m%i==0) sum+=2;
  }
  return sum;
}

bool flag(long long int n,long long int i){
  while(n%i==0) n/=i;
  if((n-1)%i==0) return true;
  else return false;
}

int main(){
  long long int n,m;
  long long sum=1;
  cin >> n;
  m=n-1;
  sum += countsum(m);

  deb(sum);

  for(long long int i=2;i*i<=n;i++){
    if(i*i==n) sum++;
    else if(n%i==0){
      if(flag(n,i)) sum++;
    }
  }
  cout << sum << endl;
  return 0;
}
