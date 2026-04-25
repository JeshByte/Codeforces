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
void dfs(vector<vector<ll>>& adj){
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    pq.push(1);
    set<ll> visited;
    visited.insert(1);
    while(!pq.empty()){
        ll u=pq.top();
        pq.pop();
        cout<<u<<" ";
        for(auto it:adj[u]){
            if(visited.count(it)==0){
                pq.push(it);
                visited.insert(it);
            }
        }
    }
    cout<<'\n';
}
void solve(ll t,ll testcases){
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>> edges;
    for(int i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }
    map<pair<ll,ll>,ll> mp;
    vector<pair<ll,ll>> nedges;
    for(int i=0;i<m;i++){
        mp[edges[i]]++;
        if(edges[i].first==edges[i].second || mp[edges[i]]>1){
            continue;
        }
        nedges.push_back(edges[i]);
    }
    ll len=nedges.size();
    vector<vector<ll>> adj(n+1,vector<ll>());
    for(int i=0;i<len;i++){
        ll u=nedges[i].first;
        ll v=nedges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(adj);
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
