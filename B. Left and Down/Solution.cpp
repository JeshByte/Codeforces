#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll a,b,k;
    cin>>a>>b>>k;
    ll c=__gcd(a,b);
    ll x=a/c;
    ll y=b/c;
    if(x<=k && y<=k){
        cout<<"1"<<'\n';
    }
    else{
        cout<<"2"<<'\n';
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

