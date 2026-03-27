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
void solve(ll t,ll testcases){
    ll n,k;
    cin>>n>>k;
    // for(int i=1;i<=n;i++){
    //     cout<<i<<":";
    //     for(int j=0;j<factors[i].size();j++){
    //         cout<<factors[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    vector<ll> dp(n+1,1);
    for(int len=2;len<=k;len++){
        vector<ll> new_dp(n+1,0);
        for(int end=1;end<=n;end++){
            for(int mul=end;mul<=n;mul+=end){
                new_dp[end]=(new_dp[end]+dp[mul])%1000000007;
            }
        }
        dp=new_dp;
    }
    // for(int i=1;i<=n;i++){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<'\n';
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans=(ans+dp[i])%1000000007;
    }
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
