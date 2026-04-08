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
ll rec(vector<ll>& arr, ll n){
    vector<ll> dp(n+1,0);
    for(int i=n-1;i>=0;i--){
        ll ans=n;
        ll op1=dp[i+1]+1;
        ll next=arr[i]+i+1;
        ll op2;
        if(next>n){
            op2=n-i;
        }
        else{
            op2=dp[next];
        }
        dp[i]=min(op1,op2);
    }
    return dp[0];
}
void solve(ll t,ll testcases){
    ll n;
    cin>>n;
    vector<ll> arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    // vector<ll> dp(n+1,0);
    // ll ans=n;
    // for(int i=n-1;i>=0;i--){
    //     ll next=i+arr[i]+1;
    //     if(next>n){
    //         dp[i]=(n-i);            
    //     }
    //     else{
    //         dp[i]=dp[next];
    //     }
    //     ans=min(ans,dp[i]+i);
    // } 
    ll ans=rec(arr,n);
    cout<<ans<<'\n';
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
