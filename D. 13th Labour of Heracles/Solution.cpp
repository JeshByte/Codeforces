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
void solve(ll t,ll testcases){
    ll n;
    cin>>n;
    vector<ll> weights(n+2,0);
    for(int i=1;i<=n;i++){
        ll input;
        cin>>input;
        weights[i]=input;
    }
    vector<pair<ll,ll>> edges;
    for(int i=1;i<=n-1;i++){
        ll u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }
    vector<ll> degree(n+2,0);
    for(int i=0;i<edges.size();i++){
        ll u=edges[i].first;
        ll v=edges[i].second;
        degree[u]++;
        degree[v]++;
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    ll s=0;
    for(int i=1;i<=n;i++){
        if(degree[i]>=2){
            pq.push({weights[i],degree[i]});
        }
        s+=degree[i]*weights[i];
    }
    vector<ll> res(n,0);
    res[n-1]=s;
    for(int i=n-2;i>=1;i--){
        pair<ll,ll> val=pq.top();
        pq.pop();
        ll wt=val.first;
        ll deg=val.second;
        s-=wt;
        res[i]=s;
        deg--;
        if(deg>=2){
            pq.push({wt,deg});
        }
    }
    for(int i=1;i<=n-1;i++){
        cout<<res[i]<<" ";
    }
    cout<<'\n';
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  cin>>t;
  for(int i=1;i<=t;i++){
  solve(i,t);
  }
  return 0;
}
