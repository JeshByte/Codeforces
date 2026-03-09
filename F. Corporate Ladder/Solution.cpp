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
void build(vector<vector<ll>>& child,vector<ll>& parent,ll n,vector<vector<ll>>& dp,ll LOG,vector<ll>& depth){
    stack<ll> st;
    st.push(1);
    dp[1][0]=1;
    while(!st.empty()){
        ll v=st.top();
        st.pop();
        dp[v][0]=parent[v];
        depth[v]=depth[parent[v]]+1;
        for(int i=1;i<=LOG;i++){
            dp[v][i]=dp[dp[v][i-1]][i-1];
        }
        for(auto it:child[v]){
            st.push(it);
        }
    }
}
ll query(ll x,ll k,vector<vector<ll>>& dp,vector<ll>& depth,ll LOG){
    if(k>=depth[x]){
        return -1;
    }
    ll anc=x;
    for(int i=0;i<=LOG;i++){
        if(k&(1ll<<i)){
            anc=dp[anc][i];
        }
    }
    return anc;
}
void solve(ll t,ll testcases){
    ll n,q;
    cin>>n>>q;
    vector<ll>arr;
    for(int i=0;i<n-1;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    vector<pair<ll,ll>> queries;
    for(int i=0;i<q;i++){
        ll x,k;
        cin>>x>>k;
        queries.push_back({x,k});
    }
    vector<vector<ll>> child(n+1);
    vector<ll> parent(n+1);
    parent[1]=1;
    for(int i=2;i<=n;i++){
        child[arr[i-2]].push_back(i);
        parent[i]=(arr[i-2]);
    }
    ll LOG=0;
    while((1ll<<LOG)<=n){
        LOG++;
    }
    vector<vector<ll>>dp(n+1,vector<ll>(LOG+1));
    vector<ll> depth(n+1,0);
    build(child,parent,n,dp,LOG,depth);
    //cout<<depth[4]<<'\n';
    for(int i=0;i<q;i++){
        ll x=queries[i].first;
        ll k=queries[i].second;
        cout<<query(x,k,dp,depth,LOG)<<'\n';
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
