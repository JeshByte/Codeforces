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
ll highestBit(ll n){
    ll bit=0;
    for(int i=0;i<64;i++){
        ll mask=1ll<<i;
        if(n&mask){
            bit=i;
        }
    }
    return bit;
}
void solve(ll t,ll testcases){
    ll n;
    cin>>n;
    vector<pair<ll,ll>> edges(n+1);
    for(int i=1;i<=n-1;i++){
        ll u,v;
        cin>>u>>v;
        edges[i]={u,v};
    }
    vector<ll> degree(n+1,0);
    for(int i=1;i<=n-1;i++){
        ll u=edges[i].first;
        ll v=edges[i].second;
        degree[u]++;
        degree[v]++;
    }
    ll node=-1;
    for(int i=1;i<=n;i++){
        if(degree[i]>=3){
            node=i;
            break;
        }
    }
    if(node==-1){
        for(int i=0;i<=n-2;i++){
            cout<<i<<'\n';
        }
        return;
    }
    vector<ll> alloted(n+1,-1);
    vector<ll> req_edges;
    for(int i=1;i<=n-1;i++){
        ll u=edges[i].first;
        ll v=edges[i].second;
        if(u==node || v==node){
            req_edges.push_back(i);
            if(req_edges.size()==3){
                break;
            }
        }
    }
    alloted[req_edges[0]]=0;
    alloted[req_edges[1]]=1;
    alloted[req_edges[2]]=2;
    ll ind=3;
    for(int i=1;i<=n-1;i++){
        if(alloted[i]==-1){
            alloted[i]=ind;
            ind++;
        }
    }
    for(int i=1;i<=n-1;i++){
        cout<<alloted[i]<<'\n';
    }
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
