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
void solve(ll t){
    ll n,m;
    cin>>n>>m;
    vector<ll> a,b;
    for(int i=0;i<n-1;i++){
        ll input;
        cin>>input;
        a.push_back(input);
    }
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        b.push_back(input);
    }
    a.push_back(1);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll cnt=0;
    ll i=0,j=0;
    while(i<n && j<n){
        if(a[i]<b[j]){
            cnt++;
            i++;
            j++;
        }
        else{
            j++;
        }
    }
    cout<<n-cnt<<'\n';
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
