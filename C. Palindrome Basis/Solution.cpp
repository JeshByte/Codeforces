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
vector<ll> palindromes;
bool checkPalindromic(ll n){
    ll rn=0;
    ll tp=n;
    while(n){
        ll digit=n%10;
        rn=rn*10+digit;
        n=n/10;
    }
    return rn==tp;
}
void generatePalindromes(){
    for(ll i=1;i<=4e4;i++){
        if(checkPalindromic(i)){
            palindromes.push_back(i);
        }
    }
}
ll MOD=1e9+7;
vector<ll> dp(4e4+1,0);
void rec(ll n){
    dp[0]=1;
    for(ll j=0;j<palindromes.size() && palindromes[j]<=n;j++){
        for(ll i=palindromes[j];i<=n;i++){
            dp[i]=(dp[i]+dp[i-palindromes[j]])%MOD;
        }
    }
    // for(ll i=1;i<=n;i++){
    //     if(visited[i]){
    //         continue;
    //     }
    //     for(ll j=0;j<palindromes.size() && palindromes[j]<=i;j++){
    //         dp[i]+=dp[i-palindromes[j]];
    //     }
    //     visited[i]=true;
    // }
}
void solve(ll t,ll testcases){
    ll n;
    cin>>n;
    cout<<dp[n]<<'\n';
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  cin>>t;
  generatePalindromes();
  rec(4e4);
  for(int i=1;i<=t;i++){
  solve(i,t);
  }
  return 0;
}
