#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
  ll n;
  cin>>n;
  vector<ll> arr;
  for(int i=0;i<n;i++){
    ll input;
    cin>>input;
    arr.push_back(input);
  }
  vector<ll> mini(n+1);
  ll mi=arr[0];
  for(int i=1;i<n;i++){
    mini[i]=mi;
    mi=min(mi,arr[i]);
  }
  for(int i=1;i<n;i++){
    if(arr[i]<=mini[i] || (arr[i]-mini[i])<mini[i]){
      continue;
    }
    cout<<"NO\n";
    return;
  }
  cout<<"YES\n";
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
