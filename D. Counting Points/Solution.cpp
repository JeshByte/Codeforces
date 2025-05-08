#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
ll compute(ll centre,ll radius,ll point){
    ll term=(point-centre)*(point-centre);
    term=(radius*radius)-term;
    term=sqrt(term);
    return 2*((int)term)+1;
}
void solve(ll t){
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>>comp(n,{0,0});
    for(int i=0;i<n;i++){
        cin>>comp[i].first;
    }
    for(int i=0;i<n;i++){
        cin>>comp[i].second;
    }
    sort(comp.begin(),comp.end());
    map<ll,ll>mp;
    for(int i=0;i<n;i++){
        ll centre=comp[i].first;
        ll radius=comp[i].second;
        for(int j=centre-radius;j<=centre+radius;j++){
            mp[j]=max(mp[j],compute(centre,radius,j));
        }
    }
    ll ans=0;
    for(auto it:mp){
        ans+=it.second;
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
