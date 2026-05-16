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
class DSU{
    vector<ll>parent,rank;
    public:
    DSU(ll n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    ll findParent(ll v){
        if(v==parent[v]){
            return v;
        }
        return parent[v]=findParent(parent[v]);
    }
    void Union(ll u,ll v){
        ll pu=findParent(u);
        ll pv=findParent(v);
        if(pu==pv){
            return;
        }
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else if(rank[pv]<rank[pu]){
            parent[pv]=pu;
        }
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
};
void solve(ll t,ll testcases){
    ll n,k;
    cin>>n>>k;
    vector<vector<ll>> edges;
    for(int i=1;i<=n-1;i++){
        ll u,v,x;
        cin>>u>>v>>x;
        edges.push_back({u,v,x});
    }
    DSU D(n);
    for(int i=0;i<edges.size();i++){
        ll u=edges[i][0];
        ll v=edges[i][1];
        ll x=edges[i][2];
        if(x==0){
            D.Union(u,v);
        }
    }
    ll MOD=1e9+7;
    ll total=modExpo(n,k,MOD);
    map<ll,ll> mp;
    for(int i=1;i<=n;i++){
        ll p=D.findParent(i);
        mp[p]++;
    }
    for(auto it:mp){
        ll val=it.second;
        ll tp=modExpo(val,k,MOD);
        total=(total-tp+MOD)%MOD;
    }
    cout<<total<<'\n';
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
