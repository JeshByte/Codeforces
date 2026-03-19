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
pair<bool,ll> isBipartite(ll root,int n, vector<vector<ll>>& adj) {
    vector<int> color(n+1, -1); 
    queue<int> q;

    color[root] = 0;
    q.push(root);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (color[v] == -1) {
                color[v] = 1 - color[u]; 
                q.push(v);
            } else if (color[v] == color[u]) {
                return {false,-1}; 
            }
        }
    }
    ll cnt=max(count(color.begin(),color.end(),1),count(color.begin(),color.end(),0));
    return {true,cnt};
}
void solve(ll t, ll testcases) {
    ll n;
    cin>>n;
    vector<ll> arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    vector<ll>pos(n+1,0),neg(n+1,0);
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            pos[i]=1;
        }
        else{
            neg[i]=1;
        }
    }
    for(int i=n-2;i>=0;i--){
        if(arr[i]>0){
            pos[i]+=pos[i+1];
            neg[i]+=neg[i+1];
        }
        else{
            pos[i]+=neg[i+1];
            neg[i]+=pos[i+1];
        }
    }
    ll posi=accumulate(pos.begin(),pos.end(),0ll);
    ll negi=accumulate(neg.begin(),neg.end(),0ll);
    cout<<negi<<" "<<posi<<'\n';
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
