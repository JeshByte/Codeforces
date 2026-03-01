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
ll Expo(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base);
        }
 
        exp = exp >> 1;
 
        base = (base * base);
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
void getPrimeFactorPowers(ll n,map<ll,ll>&factors) {
    while (n % 2 == 0) {
        factors[2]++;
        n /= 2;
    }
    for (int i = 3; i <= sqrtl(n); i += 2) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    if (n > 2) {
        factors[n]++;
    }
}
void rec(ll curr,vector<ll>& sz,vector<ll>& dp,vector<ll>& l,vector<ll>& r){
    if(curr==(-1)){
        return;
    }
    rec(l[curr],sz,dp,l,r);
    rec(r[curr],sz,dp,l,r);
    ll left=0,right=0,szl=0,szr=0;
    if(l[curr]!=-1){
        szl=sz[l[curr]];
        left=dp[l[curr]];
    }
    if(r[curr]!=-1){
        szr=sz[r[curr]];
        right=dp[r[curr]];
    }
    sz[curr]=szl+szr+1;
    dp[curr]=min(szl+right,szr+left);
}
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll> arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    stack<ll> st;
    vector<ll> l(n,-1),r(n,-1);
    for(int i=0;i<n;i++){
        ll last=-1;
        while(!st.empty() && arr[st.top()]<arr[i]){
            last=st.top();
            st.pop();
        }
        if(last!=-1){
            l[i]=last;
        }
        if(!st.empty()){
            r[st.top()]=i;
        }
        st.push(i);
    }
    ll root;
    while(!st.empty()){
        root=st.top();
        st.pop();
    }
    vector<ll> sz(n),dp(n);
    rec(root,sz,dp,l,r);
    cout<<dp[root]<<'\n';
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
