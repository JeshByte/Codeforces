#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll>arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    vector<ll> bits(32,0);
    for(int i=0;i<n;i++){
      ll num=arr[i];
      for(int j=0;j<32;j++){
        if((num>>j)&1){
          bits[j]++;
        }
      }
    }
    ll g=0;
    for(int i=0;i<32;i++){
      //cout<<bits[i]<<" ";
      g=__gcd(g,bits[i]);
    }
    //cout<<'\n';
    if(g==0){
      for(int i=1;i<=n;i++){
        cout<<i<<" ";
      }
      cout<<'\n';
      return;
    }
    //cout<<g<<'\n';
    set<ll> factors;
    for(int i=1;i<=sqrt(g);i++){
      if(g%i==0){
        factors.insert(i);
        factors.insert(g/i);
      }
    }
    for(auto it:factors){
      cout<<it<<" ";
    }
    cout<<'\n';
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
