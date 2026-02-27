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
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll> digits;
    ll s=0;
    while(n){
        ll digi=n%10;
        digits.push_back(digi);
        s+=digi;
        n=n/10;
    }
    digits[digits.size()-1]--;
    sort(digits.rbegin(),digits.rend());
    ll ans=0;
    for(int i=0;i<digits.size();i++){
        if(s<=9){
            cout<<ans<<'\n';
            return;
        }
        s-=digits[i];
        ans++;
    }
    cout<<ans<<'\n';
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
