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
void solve(ll t,ll testcases){
    ll n;
    cin>>n;
    vector<ll> a,b;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        a.push_back(input);
    }
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        b.push_back(input);
    }
    map<vector<ll>,ll> mp;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            continue;
        }
        ll val1=abs(a[i]);
        ll val2=abs(b[i]);
        ll g=__gcd(val1,val2);
        val1=val1/g;
        val2=val2/g;
        ll sign;
        bool sign1=true,sign2=true;
        if(a[i]<0){
            sign1=false;
        }
        if(b[i]<0){
            sign2=false;
        }
        if(sign1==sign2){
            sign=0;
        }
        else{
            sign=1;
        }
        mp[{sign,val2,val1}]++;
    }
    ll cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]==0 && b[i]==0){
            cnt++;
        }
    }
    ll maxi=0;
    vector<ll> tp;
    for(auto it:mp){
        //ll temp=maxi;
        maxi=max(maxi,it.second);
        // if(temp!=maxi){
        //     tp=it.first;
        // }
    }
    ll bcnt=count(b.begin(),b.end(),0);
    ll ans=max(bcnt,maxi+cnt);
    cout<<ans<<'\n';
    // if(n==200000 && a[0]==2){
    //     cout<<bcnt<<'\n';
    //     cout<<maxi<<" "<<cnt<<'\n';
    //     cout<<tp[0]<<" "<<tp[1]<<" "<<tp[2]<<'\n';
    // }
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
