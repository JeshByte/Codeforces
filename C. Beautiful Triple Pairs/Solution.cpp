#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
ll comp(map<vector<ll>,ll>& mp, ll l, ll r, vector<vector<ll>>& triplets){
    mp.clear();
    ll ans=0;
    for(int i=0;i<triplets.size();i++){
        mp[{triplets[i][l],triplets[i][r]}]++;
    }
    for(auto it:mp){
        ll freq=it.second;
        ans+=((freq*(freq-1))/2);
    }
    return ans;
}
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<ll>> triplets;
    for(int i=0;i<n-2;i++){
        vector<ll> temp;
        temp={arr[i],arr[i+1],arr[i+2]};
        triplets.push_back(temp);
    }
    map<vector<ll>,ll> mp;
    ll ans=0;
    ans+=comp(mp,1,2,triplets);
    ans+=comp(mp,0,1,triplets);
    ans+=comp(mp,0,2,triplets);
    mp.clear();
    for(int i=0;i<triplets.size();i++){
        mp[triplets[i]]++;
    }
    for(auto it:mp){
        ll freq=it.second;
        freq=((freq*(freq-1))/2);
        ans-=(3*freq);
    }
    cout<<ans<<'\n';
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
