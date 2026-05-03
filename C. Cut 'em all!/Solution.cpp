#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
void printWithPrecision(auto n){
    cout << fixed << setprecision(6) << n << '\n';
}
ll dfs(ll v,vector<vector<ll>>& adj,vector<bool>& visited,ll& del){
    ll ans=0;
    visited[v]=true;
    for(auto it:adj[v]){
        if(!visited[it]){
            ll cnt=dfs(it,adj,visited,del);
            if(cnt&1){
                ans+=cnt;
            }
            else{
                del++;
            }
        }
    }
    return ans+1;
}
void solve(ll t,ll testcases){
    ll n;
    cin>>n;
    vector<pair<ll,ll>> edges;
    for(int i=1;i<=n-1;i++){
        ll u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }
    if(n&1){
        cout<<-1<<'\n';
        return;
    }
    vector<vector<ll>> adj(n+1,vector<ll>());
    for(int i=1;i<=n-1;i++){
        ll u=edges[i-1].first;
        ll v=edges[i-1].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n+1,false);
    ll ans=0;
    ll dummy=dfs(1,adj,visited,ans);
    cout<<ans<<'\n';
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  //cin>>t;
  for(int i=1;i<=t;i++){
  solve(i,t);
  }
  return 0;
}
// for interactive
// cout<<" "<<endl;
// fflush(stdout);
