#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n,m;
    cin>>n>>m;
    if(n>=3 && m>=2){
        cout<<"YES\n";
    }
    else if(m>=3 && n>=2){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  cin>>t;
  for(int i=1;i<=t;i++){
  solve(i);
  }
  return 0;
}
