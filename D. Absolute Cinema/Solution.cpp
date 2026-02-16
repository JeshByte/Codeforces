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
    vector<ll> arr(n+1,0);
    for(int i=1;i<=n;i++){
        ll input;
        cin>>input;
        arr[i]=input;
    }
    vector<ll> res(n+1,0);
    for(int i=2;i<=n-1;i++){
        res[i]=((arr[i+1]+arr[i-1]-2*arr[i])/2);
    }
    ll coeff=1;
    ll s=0;
    for(int i=2;i<=n-1;i++){
        s=s+(coeff*res[i]);
        coeff++;
    }
    res[n]=((arr[1]-s)/(n-1));
    coeff=n-2;
    s=0;
    for(int i=2;i<=n-1;i++){
        s=s+(coeff*res[i]);
        coeff--;
    }
    res[1]=((arr[n]-s)/(n-1));
    for(int i=1;i<=n;i++){
        cout<<res[i]<<" ";
    }
    cout<<'\n';
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
