#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
ll modExpo(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
 
        exp = exp >> 1;
 
        base = (base * base) % mod;
    }
    return result;
}
ll findInverse(ll n,ll MOD){
    return modExpo(n,MOD-2,MOD);
}
ll divideModulo(ll a, ll b, ll m) {
    ll b_inv = findInverse(b, m);
    return ((a % m) * b_inv) % m;
}
void dfs(ll u,vector<ll>& dp,vector<ll>& id,vector<vector<pair<ll,ll>>>&edges){
    for(auto it:edges[u]){
        ll v=it.first;
        ll ind=it.second;
        if(dp[v]==0){
            if(id[u]<=ind){
                dp[v]=dp[u];
                id[v]=ind;
            }
            else{
                dp[v]=1+dp[u];
                id[v]=ind;
            }
            dfs(v,dp,id,edges);
        }
    }
}
void solve(ll t){
    ll n;
    cin>>n;
    vector<vector<pair<ll,ll>>> edges(n+1,vector<pair<ll,ll>>());
    for(int i=1;i<=n-1;i++){
        ll u,v;
        cin>>u>>v;
        edges[u].push_back({v,i});
        edges[v].push_back({u,i});
    }
    vector<ll>dp(n+1,0);
    vector<ll>id(n+1,0);
    dp[1]=1;
    dfs(1,dp,id,edges);
    ll ans=*max_element(dp.begin(),dp.end());
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
