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
ll fact(ll n,ll MOD){
    ll ans=1;
    for(int i=n;i>=1;i--){
        ans=(ans*n)%MOD;
    }
    return ans;
}
void solve(ll t,ll testcases){
    ll n,x,y;
    cin>>n>>x>>y;
    vector<ll> arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    bool p1,p2;
    if(x&1){
        p1=false;
    }
    else{
        p1=true;
    }
    p2=!p1;
    for(int i=0;i<n;i++){
        if(arr[i]&1){
            p1=!p1;
            p2=!p2;
        }
    }
    bool p3;
    if(y&1){
        p3=false;
    }
    else{
        p3=true;
    }
    if(p1==p3){
        cout<<"Alice\n";
    }
    else{
        cout<<"Bob\n";
    }
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
