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
    vector<ll> row1,row2;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        row1.push_back(input);
    }
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        row2.push_back(input);
    }
    vector<vector<ll>> dp(n+1,vector<ll>(3,0));
    dp[0][1]=row1[0];
    dp[0][2]=row2[0];
    for(int i=1;i<n;i++){
        dp[i][0]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
        dp[i][1]=max(dp[i-1][0],dp[i-1][2])+row1[i];
        dp[i][2]=max(dp[i-1][0],dp[i-1][1])+row2[i];
    }
    ll ans=max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
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
