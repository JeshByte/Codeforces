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
ll highestBit(ll n){
    ll bit=0;
    for(int i=0;i<64;i++){
        ll mask=1ll<<i;
        if(n&mask){
            bit=i;
        }
    }
    return bit;
}
void solve(ll t,ll testcases){
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    map<char,ll> mp;
    ll ans=0;
    ll len;
    if(k&1){
        len=k/2;
    }
    else{
        len=(k/2)-1;
    }
    for(int i=0;i<=len;i++){
        mp.clear();
        for(int j=i;j<n;j+=k){
            mp[s[j]]++;
        }
        ll opp=k-i-1;
        if(opp==i){
            ll total=(n/k);
            ll maxi=0;
            for(auto it:mp){
                maxi=max(maxi,it.second);
            }
            //cout<<"equal:"<<total<<" "<<maxi<<'\n';
            ans+=(total-maxi);
            continue;
        }
        for(int j=opp;j<n;j+=k){
            mp[s[j]]++;
        }
        ll total=(n/k)*2;
        ll maxi=0;
        for(auto it:mp){
            maxi=max(maxi,it.second);
        }
        //cout<<total<<" "<<maxi<<'\n';
        ans+=(total-maxi);
    }
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
