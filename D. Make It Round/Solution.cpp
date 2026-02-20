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
    ll n,m;
    cin>>n>>m;
    ll maxi=n*m;
    ll max10=1;
    while(true){
        if(max10*10<=maxi){
            max10*=10;
        }
        else{
            break;
        }
    }
    vector<ll> poss;
    while(max10){
        ll tbound=(maxi/max10);
        ll g=__gcd(max10,n);
        ll L=(n/g);
        ll m=(tbound/L);
        ll num=L*m*max10;
        if(num>0){
            poss.push_back(num);
        }
        max10=max10/10;
    }
    ll mval=-1;
    ll m0=-1;
    ll len=poss.size();
    for(int i=0;i<len;i++){
        ll c0=0;
        ll tp=poss[i];
        while(tp%10==0){
            c0++;
            tp=tp/10;
        }
        if(c0>m0){
            mval=poss[i];
            m0=c0;
        }
        else if(c0==m0 && poss[i]>mval){
            mval=poss[i];
        }
    }
    cout<<mval<<'\n';
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
