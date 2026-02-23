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
    string s;
    cin>>s;
    ll blocks=0;
    ll i=0;
    string ns="";
    char first=s[0];
    ll ind=-1;
    for(int i=n-1;i>=0;i--){
        if(s[i]!=first){
            ns=s[i]+ns;
            first=s[i];
        }
        else{
            ind=i;
            break;
        }
    }
    for(int i=0;i<=ind;i++){
        ns=ns+s[i];
    }
    //cout<<ns<<'\n';
    while(i<n){
        char tp=ns[i];
        while(ns[i]==tp){
            i++;
        }
        blocks++;
    }
    cout<<blocks<<'\n';
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
