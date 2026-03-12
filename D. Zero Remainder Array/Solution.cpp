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
bool check(ll mid,ll n,ll m,ll l,vector<ll>& arr,vector<ll>& ph){
    for(int i=0;i<m;i++){
        ph[i]=0;
    }
    ll t=0;
    for(int i=0;i<n;i++){
        ll time=(arr[i]-1)-t;
        ll init=time/m;
        for(int j=0;j<m;j++){
            ph[j]+=init;
        }
        ll rest=time-(init*m);
        
    }
}
void solve(ll t,ll testcases){
    ll n,k;
    cin>>n>>k;
    vector<ll> arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    map<ll,ll> mp;
    for(int i=0;i<n;i++){
        ll q=Ceil(arr[i],k);
        ll req=k*q-arr[i];
        mp[req]++;
    }
    ll ans=-1;
    for(auto it:mp){
        if(it.first==0){
            continue;
        }
        ll maxi=it.first+(it.second-1)*k;
        ans=max(ans,maxi);
    }
    cout<<ans+1<<'\n';
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
