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
    ll n,a,b;
    cin>>n>>a>>b;
    vector<ll> arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
        ll s=accumulate(arr.begin(),arr.end(),0ll);
        ll res=b*s;
        ll run=0;
        ll prev=0;
        for(int i=0;i<n;i++){
            s-=arr[i];
            run+=(b*(arr[i]-prev));
            if(i!=n-1){
                run+=(a*(arr[i]-prev));
            }
            ll later=b*(s-(arr[i]*(n-i-1)));
            ll total=run+later;
            res=min(res,total);
            prev=arr[i];
        }
    cout<<res<<'\n';
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
