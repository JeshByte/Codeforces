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
    string str;
    cin>>str;
    if(count(str.begin(),str.end(),'1')==n){
        cout<<0<<'\n';
        return;
    }
    ll len=-1;
    ll i=0;
    while(i<n){
        if(str[i]=='1'){
            i++;
            continue;
        }
        ll temp=0;
        while(i<n && str[i]=='0'){
            temp++;
            i++;
        }
        len=max(len,temp);
    }
    ll te=0;
    i=n-1;
    while(i>=0 && str[i]=='0'){
        i--;
        te++;
    }
    i=0;
    while(i<n && str[i]=='0'){
        i++;
        te++;
    }
    len=max(len,te);
    cout<<len<<'\n';
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
