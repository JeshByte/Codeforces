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
void solve(ll t){
    ll n;
    cin>>n;
    map<ll,ll> factors;
    getPrimeFactorPowers(n,factors);
    ll k=1;
    for(auto it:factors){
        ll prime=it.first;
        ll times=1;
        if(it.second>n){
            times=Ceil(it.second,n);
        }
        ll power=Expo(prime,times);
        k=k*power;
    }
    cout<<k<<'\n';
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
