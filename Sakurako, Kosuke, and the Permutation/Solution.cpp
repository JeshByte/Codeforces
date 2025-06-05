#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll> perm(n+1);
    for(int i=1;i<=n;i++){
        cin>>perm[i];    
    }
    vector<pair<ll,ll>> cycles;
    vector<bool> visited(n+1,false);
    for(ll i=1;i<=n;i++){
        if(!visited[i]){
            ll mini=i;
            ll s=0;
            while(!visited[perm[i]]){
                i=perm[i];
                mini=min(mini,i);
                visited[i]=true;
                s++;
            }
            cycles.push_back({mini,s});
        }
    }
    ll ans=0;
    for(int i=0;i<cycles.size();i++){
        //cout<<cycles[i].second<<'\n';
        if(cycles[i].second>2){
        ans+=cycles[i].second/2;
        if(cycles[i].second%2==0){
            ans--;
        }
        }
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
