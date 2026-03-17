#include<bits/stdc++.h>
#include <iomanip>
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
long double rec(ll ind,ll n,vector<long double>& dp,vector<pair<long double,long double>>& arr){
    if(ind>=n){
        return 0.0;
    }
    if(dp[ind]!=(-1.0)){
        return dp[ind];
    }
    dp[ind]=max(rec(ind+1,n,dp,arr),arr[ind].first+rec(ind+1,n,dp,arr)*((100.00-arr[ind].second)/100.00));
    return dp[ind];
}
void printWithPrecision(auto n){
    cout << fixed << setprecision(6) << n << '\n';
}
void solve(ll t,ll testcases){
    ll n;
    cin>>n;
    vector<pair<long double,long double>> arr;
    for(int i=0;i<n;i++){
        double c,p;
        cin>>c>>p;
        arr.push_back({c,p});
    }
    vector<long double> dp(n+1,-1);
    printWithPrecision(rec(0,n,dp,arr));
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
