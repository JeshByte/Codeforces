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
ll MOD=998244353;
ll leftOnes(ll x){
    x++;
    ll t1=x/4;
    ll ans=(t1%MOD);
    x-=t1*4;
    if(x>=2){
        ans=(ans+1)%MOD;
    }
    return ans;
}
ll rightOnes(ll x,ll n){
    ll total=leftOnes(n);
    ll extra=leftOnes(x-1);
    ll ans=(total-extra+MOD)%MOD;
    return ans;
}
ll leftZeroes(ll x){
    x++;
    ll t1=x/4;
    ll ans=(t1%MOD);
    x-=t1*4;
    if(0<=ans){
        ans=(ans+1)%MOD;
    }
    return ans; 
}
ll rightZeroes(ll x,ll n){
    ll total=leftZeroes(n);
    ll extra=leftZeroes(x-1);
    //cout<<"total:"<<total<<'\n';
    //cout<<"extra:"<<extra<<'\n';
    ll ans=(total-extra+MOD)%MOD;
    return ans;
}
void solve(ll t,ll testcases){
    ll n,x;
    cin>>n>>x;
    //cout<<leftOnes(x-1)<<" "<<rightOnes(x,n)<<" "<<leftZeroes(x-1)<<" "<<rightZeroes(x,n)<<'\n';
    ll t1=(leftOnes(x-1)*rightOnes(x,n))%MOD;
    ll t2=(leftZeroes(x-1)*rightZeroes(x,n))%MOD;
    ll ans=(t1+t2)%MOD;
    cout<<ans<<'\n';
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
// for interactive
// cout<<" "<<endl;
// fflush(stdout);
