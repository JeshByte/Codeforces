#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
void printWithPrecision(auto n){
    cout << fixed << setprecision(6) << n << '\n';
}
ll MOD=1e9+7;
void solve(ll t,ll testcases){
    string s;
    cin>>s;
    ll n=s.size();
    vector<ll> pre(n+1,0);
    ll lb=-1;
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(s[i-1]=='b'){
            lb=i;
            pre[i]=pre[i-1];
            continue;
        }
        if(s[i-1]=='a'){
            if(lb==-1){
                ans=(ans+1)%MOD;
                pre[i]=(pre[i-1]+1)%MOD;
            }
            else{
                ans=(ans+pre[lb]+1)%MOD;
                pre[i]=(pre[i-1]+pre[lb]+1)%MOD;
            }
            continue;
        }
        pre[i]=pre[i-1];
    }
    // for(int i=0;i<=n;i++){
    //     cout<<pre[i]<<" ";
    // }
    // cout<<'\n';
    cout<<ans<<'\n';
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  //cin>>t;
  for(int i=1;i<=t;i++){
  solve(i,t);
  }
  return 0;
}
// for interactive
// cout<<" "<<endl;
// fflush(stdout);
