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
    map<ll,ll>mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    ll p=0;
    for(auto it:mp){
        p+=(it.second/2);
    }
    if(p<4){
        cout<<"NO\n";
        return;
    }
    vector<ll> comp;
    for(auto it:mp){
        ll req=it.second/2;
        for(int i=0;i<req;i++){
            comp.push_back(it.first);
        }
    }
    sort(comp.begin(),comp.end());
    ll m=comp.size();
    ll x=comp[0],y=comp[1],nx=comp[m-2],ny=comp[m-1];
    cout<<"YES\n";
    cout<<x<<" "<<y<<" "<<x<<" "<<ny<<" "<<nx<<" "<<y<<" "<<nx<<" "<<ny<<'\n';
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
