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
set<ll> power;
void generatePowers(){
    ll i=0;
    while((1ll<<i)<=1e12){
        power.insert((1ll<<i));
        i++;
    }
    ll fact=1;
    for(ll i=1;i<=1e12 && fact<=1e12;i++){
        fact=fact*i;
        power.insert(fact);
    }
}
// vector<ll> dp(301,50);
// void rec(){
//     dp[0]=0;
//     for(ll val:power){
//         for(ll i=val;i<=300;i++){
//             dp[i]=min(dp[i],1+dp[i-val]);
//         }
//     }
// }
ll rec(ll n, vector<ll>& arr, ll turn, ll ind, vector<vector<ll>>& dp){
    if(ind>=n){
        return 0;
    }
    if(dp[ind][turn]!=-1){
        return dp[ind][turn];
    }
    ll ans=1e6;
    if(turn){
        if(arr[ind]==1){
            ans=min(ans,1+rec(n,arr,0,ind+1,dp));
        }
        else{
            ans=min(ans,rec(n,arr,0,ind+1,dp));
        }
        if(ind+1<n){
            ll skips=0;
            if(arr[ind]==1){
                skips++;
            }
            if(arr[ind+1]==1){
                skips++;
            }
            ans=min(ans,skips+rec(n,arr,0,ind+2,dp));
        }
    }
    else{
        ans=min(ans,rec(n,arr,1,ind+1,dp));
        ans=min(ans,rec(n,arr,1,ind+2,dp));
    }
    dp[ind][turn]=ans;
    return dp[ind][turn];
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
    vector<vector<ll>> dp(n+1,vector<ll>(2,-1));
    cout<<rec(n,arr,1,0,dp)<<'\n';
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  cin>>t;
  //generatePowers();
  //rec();
  for(int i=1;i<=t;i++){
  solve(i,t);
  }
  return 0;
}
