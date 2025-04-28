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
    vector<ll>pos(n+1,0);
    vector<ll>neg(n+1,0);
    for(int i=1;i<=n;i++){
        pos[i]=pos[i-1]+max(0ll,arr[i-1]);
    }
    for(int i=1;i<=n;i++){
        neg[i]=abs(neg[i-1])+abs(min(0ll,arr[i-1]));
    }
    ll mx=-1;
    for(int i=0;i<n;i++){
        ll temp=pos[i+1]-pos[0];
        // cout<<pos[i]-pos[0]<<'\n';
        // cout<<neg[n]-neg[i]<<'\n';
        temp+=neg[n]-neg[i];
        mx=max(mx,temp);
    }
    cout<<mx<<'\n';
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
