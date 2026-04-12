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
void solve(ll t,ll testcases){
    ll n;
    cin>>n;
    vector<ll> fact;
    ll f=2;
    ll mul=3;
    while((f*mul)<=n){
        f*=mul;
        fact.push_back(f);
        mul++;
    }
    ll len=fact.size();
    ll mask=(1ll<<len);
    ll ans=50;
    for(ll i=0;i<=mask;i++){
        ll s=0;
        ll cnt=0;
        for(ll j=0;j<fact.size();j++){
            if(i&(1ll<<j)){
                s+=fact[j];
                cnt++;
            }
        }
        ll remain=n-s;
        ll bits=0;
        for(ll j=0;j<64;j++){
            if(remain&(1ll<<j)){
                bits++;
            }
        }
        ans=min(ans,cnt+bits);
    }
    cout<<ans<<'\n';
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
