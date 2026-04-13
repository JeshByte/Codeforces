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
    ll n;
    cin>>n;
    vector<ll> arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    if(count(arr.begin(),arr.end(),arr[0])==n){
        cout<<"YES\n";
        return;
    }
    vector<ll> pre(n,0);
    vector<ll> suff(n,0);
    pre[0]=arr[0];
    for(int i=1;i<n;i++){
        pre[i]=arr[i]^pre[i-1];
    }
    if(pre[n-1]==0){
        cout<<"YES\n";
        return;
    }
    suff[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        suff[i]=suff[i+1]^arr[i];
    }
    ll x=pre[n-1];
    for(int i=0;i<=n-3;i++){
        ll rxor=0;
        for(int j=i+1;j<=n-2;j++){
            rxor=rxor^arr[j];
            if(pre[i]==rxor && rxor==suff[j+1]){
                cout<<"YES\n";
                return;
            }
        }
    }
    cout<<"NO\n";
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  cin>>t;
  //generatePowers();
  //rec();
  for(int i=1;i<=t;i++){
  solve(i,t);
  }
  return 0;
}
